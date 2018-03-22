#include <Threading/Thread/StealableQueue/StealableQueue.hpp>

#include <cassert>
#include <tuple>
#include <iostream>

namespace drak {
namespace thread {

template<class T>
void StealableQueue<T>::push(const T& data) {
	emplace(data);
}

template<class T>
void StealableQueue<T>::push(T&& data) {
	emplace(std::move(data));
}

template<class T>
T StealableQueue<T>::front() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	return m_pFront->m_data;
}

template<class T>
U32 StealableQueue<T>::safeCapacity(){
	std::scoped_lock<std::mutex> lck(m_mutex);
	return m_capacity;
}

template<class T>
U32 StealableQueue<T>::safeSize(){
	std::scoped_lock<std::mutex> lck(m_mutex);
	return m_size.load(std::memory_order_acquire);
}

template<class T>
bool StealableQueue<T>::safeEmpty(){
	std::scoped_lock<std::mutex> lck(m_mutex);
	return (m_size.load(std::memory_order_acquire) == 0);
}

template<class T>
U32 StealableQueue<T>::capacity() const {
	return m_capacity;
}

template<class T>
U32 StealableQueue<T>::size() const {
	return m_size.load(std::memory_order_acquire);
}

template<class T>
bool StealableQueue<T>::empty() const {
	return (m_size.load(std::memory_order_acquire) == 0);
}

template<class T>
StealableQueue<T>::StealableQueue()
	: m_size(0u), m_capacity(0u), m_pBack(nullptr), m_pFront(nullptr),
	m_pFrontUnUsedCapacity(nullptr), m_pBackUnUsedCapacity(nullptr) {

}

template<class T>
StealableQueue<T>::StealableQueue(StealableQueue<T>&& queue) 
	: m_pFront(std::forward<StealableQueue<T>>(queue).m_pFront),
	m_pBack(std::forward<StealableQueue<T>>(queue).m_pBack),
	m_pFrontUnUsedCapacity(std::forward<StealableQueue<T>>(queue).m_pFrontUnUsedCapacity),
	m_pBackUnUsedCapacity(std::forward<StealableQueue<T>>(queue).m_pBackUnUsedCapacity),
	m_capacity(std::forward<StealableQueue<T>>(queue).safeCapacity()),
	m_size(std::forward<StealableQueue<T>>(queue).safeSize()) {

	queue.m_pFront = nullptr;
	queue.m_pBack = nullptr;
	queue.m_pFrontUnUsedCapacity = nullptr;
	queue.m_pBackUnUsedCapacity = nullptr;
	queue.m_capacity = 0u;
	queue.m_size = 0u;
}

template<class T>
StealableQueue<T>::~StealableQueue() {
	shrinkToFit();
	while (size())pop();
}

template<class T>
StealableQueue<T>& StealableQueue<T>::operator=(StealableQueue&& queue) {
	m_pFront = std::forward<StealableQueue<T>>(queue).m_pFront;
	m_pBack = std::forward<StealableQueue<T>>(queue).m_pBack;
	m_pFrontUnUsedCapacity = std::forward<StealableQueue<T>>(queue).m_pFrontUnUsedCapacity;
	m_pBackUnUsedCapacity = std::forward<StealableQueue<T>>(queue).m_pBackUnUsedCapacity;
	m_capacity = std::forward<StealableQueue<T>>(queue).safeCapacity();
	m_size = std::forward<StealableQueue<T>>(queue).safeSize();

	queue.m_pFront = nullptr;
	queue.m_pBack = nullptr;
	queue.m_pFrontUnUsedCapacity = nullptr;
	queue.m_pBackUnUsedCapacity = nullptr;
	queue.m_capacity = 0u;
	queue.m_size = 0u;
}

template<class T>
template<bool DeallocateNode>
void StealableQueue<T>::pop() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	if (!empty()) {
		if constexpr (DeallocateNode) {

			if (size() == 1) {
				m_pFront->m_data.~T();
				delete m_pFront;
				m_pFront = m_pBack = nullptr;
			}
			else {
				m_pFront = m_pFront->m_pNext;
				m_pFront->m_data.~T();
				delete m_pFront->m_pPrevious;
				m_pFront->m_pPrevious = nullptr;
			}
			m_capacity.store(capacity() - 1, std::memory_order_release);
			m_size.store(size() - 1, std::memory_order_release);
		}
		else {
			if (size() == 1) {
				m_pFront->m_data.~T();
				if (m_pFrontUnUsedCapacity)
					m_pBackUnUsedCapacity =
					addNode(m_pFront, nullptr, m_pBackUnUsedCapacity, T());
				else
					m_pFrontUnUsedCapacity = m_pBackUnUsedCapacity =
					addNode(m_pFront, nullptr, nullptr, T());
				m_pFront = m_pBack = nullptr;
			}
			else {
				m_pFront->m_data.~T();
				m_pFront = m_pFront->m_pNext;
				if (m_pFrontUnUsedCapacity)
					m_pBackUnUsedCapacity =
					addNode(m_pFront->m_pPrevious, nullptr, m_pBackUnUsedCapacity, T());
				else
					m_pFrontUnUsedCapacity = m_pBackUnUsedCapacity =
					addNode(m_pFront->m_pPrevious, nullptr, m_pBack, T());
				
				m_pFront->m_pPrevious = nullptr;
			}
			m_size.store(size() - 1, std::memory_order_release);
		}
	}
}

template<class T>
auto StealableQueue<T>::steal(U32 number) {
	if (number <= size() && number) {
		Node* res = m_pBack;
		Node* back = m_pBack;

		for (U32 i = 1; i < number; ++i) {
			res = res->m_pPrevious;
		}

		if(number != size())
			res->m_pPrevious->m_pNext = m_pBack->m_pNext;
		m_pBack = res->m_pPrevious;

		if (size() == 1)
			m_pFront = m_pBack;

		m_capacity.store(capacity() - number, std::memory_order_release);
		m_size.store(size() - number, std::memory_order_release);


		return std::make_tuple(res, back);
	}
	return std::make_tuple<Node*, Node*>(nullptr, nullptr);
}

template<class T>
void StealableQueue<T>::steal(U32 number, StealableQueue<T>& queue) {
	std::scoped_lock<std::mutex, std::mutex> lck(m_mutex, queue.m_mutex);
	auto [stealedNode, backNode] = queue.steal(number);
	if (stealedNode) {
		if (m_pBack) {
			stealedNode->m_pPrevious = m_pBack;
			backNode->m_pNext = m_pBack->m_pNext;
			m_pBack->m_pNext = stealedNode;
			m_pBack = backNode;
		}
		else {
			m_pFront = stealedNode;
			m_pFront->m_pPrevious = nullptr;
			m_pBack = backNode;
			m_pBack->m_pNext = m_pFrontUnUsedCapacity;
			if (m_pFrontUnUsedCapacity)
				m_pFrontUnUsedCapacity->m_pPrevious = m_pBack;
		}
		m_capacity.store(capacity() + number, std::memory_order_release);
		m_size.store(size() + number, std::memory_order_release);
	}
}

template<class T>
T StealableQueue<T>::back() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	return m_pBack->m_data;
}

template<class T>
bool StealableQueue<T>::emptyHasCapacity() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	return empty() && capacity();
}

template<class T>
bool StealableQueue<T>::emptyHasNoCapacity() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	return empty() && !capacity();
}

template<class T>
bool StealableQueue<T>::capacityGreaterThanSize() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	return size() < capacity();
}

template<class T>
bool StealableQueue<T>::sizeEqualOne() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	return m_size.load(std::memory_order_acquire) == 1;
}

template<class T>
void StealableQueue<T>::incSize() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) + 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incCapacity() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incSizeCapacity() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) + 1, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incSize(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) + ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incSizeCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) + ui, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSize() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) - 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decCapacity() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSizeCapacity() {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) - 1, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSize(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) - ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSizeCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	m_size.store(m_size.load(std::memory_order_acquire) - ui, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::reserve(U32 ui) {
	Node* node = new Node[ui];
	if (std::scoped_lock<std::mutex> lck(m_mutex); !capacity()) {
		m_pFrontUnUsedCapacity = m_pBackUnUsedCapacity = addNode(node, nullptr, nullptr, T());
		for (U32 i = 1; i < ui; ++i) {
			m_pBackUnUsedCapacity = addNode(node + i, nullptr, m_pBackUnUsedCapacity, T());
		}
	}
	else {
		Node* n = m_pBackUnUsedCapacity;
		for (U32 i = 0; i < ui; ++i) {
			n = addNode(node + i, nullptr, n, T());
		}
	}
	incCapacity(ui);
}

template<class T>
template<class ..._Vt>
void StealableQueue<T>::emplace(_Vt&&...data) {
	std::scoped_lock<std::mutex> lck(m_mutex);
	if (m_pFrontUnUsedCapacity) {
		if (empty()) {

			m_pFront = m_pBack = addNode(m_pFrontUnUsedCapacity,
				m_pFrontUnUsedCapacity->m_pNext, nullptr, std::forward<_Vt>(data)...);
			m_pFrontUnUsedCapacity = m_pFrontUnUsedCapacity->m_pNext;
		}
		else if (size() == 1) {
			m_pBack = addNode(m_pFrontUnUsedCapacity, m_pFrontUnUsedCapacity->m_pNext,
				m_pFront, std::forward<_Vt>(data)...);
			m_pFrontUnUsedCapacity = m_pFrontUnUsedCapacity->m_pNext;
		}
		else {
			m_pBack = addNode(m_pFrontUnUsedCapacity, m_pFrontUnUsedCapacity->m_pNext,
				m_pBack, std::forward<_Vt>(data)...);
			m_pFrontUnUsedCapacity = m_pFrontUnUsedCapacity->m_pNext;
		}
		m_size.store(size() + 1, std::memory_order_release);
	}
	else {
		if (empty()) {
			m_pFront = m_pBack = addNode(new Node(),
				nullptr, nullptr, std::forward<_Vt>(data)...);
		}
		else if (size() == 1) {
			m_pBack = addNode(new Node(), nullptr,
				m_pFront, std::forward<_Vt>(data)...);
		}
		else {
			m_pBack = addNode(new Node(), nullptr,
				m_pBack, std::forward<_Vt>(data)...);
		}
		m_capacity.store(capacity() + 1, std::memory_order_release);
		m_size.store(size() + 1, std::memory_order_release);
	}
}

template<class T>
template<class..._Vt>
typename StealableQueue<T>::Node* StealableQueue<T>::addNode(StealableQueue<T>::Node* node,
	StealableQueue<T>::Node* next, StealableQueue<T>::Node* previous, _Vt&& ...data) {

	if (next)
		next->m_pPrevious = node;
	if (previous)
		previous->m_pNext = node;
	node->m_pPrevious = previous;
	node->m_pNext = next;
	new (&node->m_data) T(std::forward<_Vt>(data)...);
	return node;
}

template<class T>
void StealableQueue<T>::clear() {
	while(safeSize())pop<false>();
}

template<class T>
void StealableQueue<T>::shrinkToFit() {
	if (m_pFrontUnUsedCapacity) {
		Node* node = m_pBackUnUsedCapacity;
		for (; node != m_pFrontUnUsedCapacity; node = node->m_pPrevious)
			delete node->m_pNext;
		delete node;
		decCapacity(capacity() - size());
	}
}

template<class T>
void StealableQueue<T>::swap(StealableQueue& queue) {

	std::swap(queue.m_pFront, m_pFront);
	std::swap(queue.m_pBack, m_pBack); 
	std::swap(queue.m_pFrontUnUsedCapacity, m_pFrontUnUsedCapacity); 
	std::swap(queue.m_pBackUnUsedCapacity, m_pBackUnUsedCapacity);

	queue.m_size ^= m_size;
	m_size ^= queue.m_size;
	queue.m_size ^= m_size;

	queue.m_capacity ^= m_capacity;
	m_capacity ^= queue.m_capacity;
	queue.m_capacity ^= m_capacity;
}


template <class T>
StealableQueue<T>::StealableQueueNode::StealableQueueNode(Node* previous, Node* next,
	const T& data) : m_pPrevious(previous), m_pNext(next), m_data(data) {
}

template <class T>
StealableQueue<T>::StealableQueueNode::StealableQueueNode(Node* previous, Node* next,
	T&& data) : m_pPrevious(previous), m_pNext(next), m_data(std::forward(data)) {
}

} // namespace thread
} // namespace drak