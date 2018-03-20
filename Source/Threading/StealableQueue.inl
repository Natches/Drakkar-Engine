#include <Threading/StealableQueue.hpp>

#include <cassert>

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
	std::scoped_lock<std::mutex> lck(m_frontMutex);
	return m_pFront->m_data;
}

template<class T>
U32 StealableQueue<T>::safeCapacity(){
	std::scoped_lock<std::mutex> lck(m_capacityMutex);
	return m_capacity;
}

template<class T>
U32 StealableQueue<T>::safeSize(){
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	return m_size.load(std::memory_order_acquire);
}

template<class T>
bool StealableQueue<T>::safeEmpty(){
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
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
	: m_size(0u), m_capacity(0u) {

}

template<class T>
StealableQueue<T>::StealableQueue(StealableQueue<T>&& queue) 
	: m_pFront(std::forward<StealableQueue<T>>(queue).m_pFront),
	m_pBack(std::forward<StealableQueue<T>>(queue).m_pBack),
	m_capacity(std::forward<StealableQueue<T>>(queue).safeCapacity()),
	m_size(std::forward<StealableQueue<T>>(queue).safeSize()) {
	
	while (queue.safeCapacity())queue.pop();
}

template<class T>
StealableQueue<T>::~StealableQueue() {
	while (safeCapacity())pop();
}

template<class T>
StealableQueue<T>& StealableQueue<T>::operator=(StealableQueue&& queue) {
	m_pFront = std::forward<StealableQueue<T>>(queue).m_pFront;
	m_pBack = std::forward<StealableQueue<T>>(queue).m_pBack;
	m_capacity = std::forward<StealableQueue<T>>(queue).safeCapacity();
	m_size = std::forward<StealableQueue<T>>(queue).safeSize();
	while(queue.safeCapacity())queue.pop();
}

template<class T>
template<bool DeallocateNode>
void StealableQueue<T>::pop() {
	std::scoped_lock<std::mutex> lck(m_frontMutex);
	if (!safeEmpty()) {
		if constexpr(!DeallocateNode) {
			if (m_pFront) {
				if (!sizeEqualOne()) {
					m_pFront = m_pFront->m_pNext;
					std::scoped_lock<std::mutex> lck2(m_backMutex);
					if (m_pBack->m_pNext)
						m_pBack->m_pNext->m_pPrevious = m_pFront->m_pPrevious;
					m_pFront->m_pPrevious->m_pNext = m_pBack->m_pNext;
					m_pBack->m_pNext = m_pFront->m_pPrevious;
					m_pBack->m_pNext->m_pPrevious = m_pBack;
					m_pFront->m_pPrevious = nullptr;
				}
				decSize();
			}
		}
		else {
			if (m_pFront) {
				if (m_pFront->m_pNext) {
					m_pFront = m_pFront->m_pNext;
					delete m_pFront->m_pPrevious;
					m_pFront->m_pPrevious = nullptr;
				}
				else {
					std::scoped_lock<std::mutex> lck2(m_backMutex);
					delete m_pFront;
					m_pBack = m_pFront = nullptr;

				}
				decSizeCapacity();
			}
		}
	}
}

template <class T>
void StealableQueue<T>::steal(U32 number, T* result) {
	std::scoped_lock<std::mutex> lck(m_backMutex);
	assert(result || number <= safeSize());
	if (!result || number > safeSize())
		return;

	if (number == safeSize()) {
		decSize(number);
		std::scoped_lock<std::mutex> lck(m_frontMutex);
		for (U32 i = number - 1; i ^ static_cast<U32>(-1); --i) {
			result[i] = m_pBack->m_data;
			m_pBack = m_pBack->m_pPrevious;
		}
	}
	else {
		decSize(number);
		for (U32 i = number - 1; i ^ static_cast<U32>(-1); --i) {
			result[i] = m_pBack->m_data;
			m_pBack = m_pBack->m_pPrevious;
		}
	}
}

template<class T>
void StealableQueue<T>::steal(U32 number, StealableQueue<T>& queue) {
	T* arr = new T[number];
	Node* node = new Node[number];
	queue.steal(number, arr);
	if (safeSize()) {
		std::scoped_lock<std::mutex> lck(m_backMutex);
		if (sizeEqualOne()) {

			{
				std::scoped_lock<std::mutex> lck2(m_frontMutex);
				addNode(node, m_pBack->m_pNext, m_pBack, arr[0]);
			}
			if (number > 1) {
				for (U32 i = 1; i < number; ++i)
					addNode(node + i, m_pBack->m_pNext, m_pBack, arr[i]);
			}
		}
		else {
			for (U32 i = 0; i < number; ++i)
				addNode(node + i, m_pBack->m_pNext, m_pBack, arr[i]);
		}
	}
	else {
		std::scoped_lock<std::mutex> lck(m_backMutex);
		std::scoped_lock<std::mutex> lck2(m_frontMutex);
		addNode(node, nullptr, nullptr, arr[0]);
		for (U32 i = 1; i < number; ++i) {
			addNode(node, nullptr, m_pBack, arr[i]);
		}
	}
	if(m_capacity < number + safeSize())
		incCapacity(number + safeSize() - m_capacity);
	incSize(number);
	delete arr;
}

template<class T>
T StealableQueue<T>::back() {
	std::scoped_lock<std::mutex> lck(m_backMutex);
	return m_pBack->m_data;
}

template<class T>
bool StealableQueue<T>::emptyHasCapacity() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	return empty() && capacity();
}

template<class T>
bool StealableQueue<T>::emptyHasNoCapacity() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	return empty() && !capacity();
}

template<class T>
bool StealableQueue<T>::capacityGreaterThanSize() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	return size() < capacity();
}

template<class T>
bool StealableQueue<T>::sizeEqualOne() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	return m_size.load(std::memory_order_acquire) == 1;
}

template<class T>
void StealableQueue<T>::incSize() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	m_size.store(m_size.load(std::memory_order_acquire) + 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incCapacity() {
	std::scoped_lock<std::mutex> lck(m_capacityMutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incSizeCapacity() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	m_size.store(m_size.load(std::memory_order_acquire) + 1, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incSize(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	m_size.store(m_size.load(std::memory_order_acquire) + ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_capacityMutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::incSizeCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	m_size.store(m_size.load(std::memory_order_acquire) + ui, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) + ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSize() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	m_size.store(m_size.load(std::memory_order_acquire) - 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decCapacity() {
	std::scoped_lock<std::mutex> lck(m_capacityMutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSizeCapacity() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	m_size.store(m_size.load(std::memory_order_acquire) - 1, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - 1, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSize(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	m_size.store(m_size.load(std::memory_order_acquire) - ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_capacityMutex);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::decSizeCapacity(U32 ui) {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	m_size.store(m_size.load(std::memory_order_acquire) - ui, std::memory_order_release);
	m_capacity.store(m_capacity.load(std::memory_order_acquire) - ui, std::memory_order_release);
}

template<class T>
void StealableQueue<T>::reserve(U32 ui) {
	incCapacity(ui);
	std::scoped_lock<std::mutex> lck(m_backMutex);
	Node* node = new Node[ui];
	if (!capacity()) {
		addNode(node, nullptr, nullptr, T());
		for (U32 i = 1; i < ui; ++i) {
			addNode(node + i, nullptr, m_pBack, T());
			m_pBack = node;
		}
	}
	else {
		Node* n = m_pBack;
		for (; n->m_pNext; n = n->m_pNext);
		for (U32 i = 0; i < ui; ++i) {
			addNode(node + i, nullptr, n, T());
			n = node + i;
		}
	}

}

template<class T>
template<class ..._Vt>
void StealableQueue<T>::emplace(_Vt&&...data) {
	if (emptyHasNoCapacity()) {
		incSizeCapacity();
		{
			std::scoped_lock<std::mutex> lck(m_frontMutex);
			std::scoped_lock<std::mutex> lck2(m_backMutex);
			m_pFront = m_pBack = 
				addNode(new Node(), nullptr, nullptr, std::forward<T>(data...));
		}
	}
	else if (emptyHasCapacity()) {
		incSize();
		{
			std::scoped_lock<std::mutex> lck(m_frontMutex);
			m_pFront->m_data = std::forward<T>(data...);
			{
				std::scoped_lock<std::mutex> lck2(m_backMutex);
				m_pBack = m_pFront;
			}
		}
	}
	else if (capacityGreaterThanSize()) {
		{
			std::scoped_lock<std::mutex> lck(m_backMutex);
			if (m_pBack->m_pNext) {
				if (sizeEqualOne()) {
					std::scoped_lock<std::mutex> lck2(m_frontMutex);
					m_pBack = m_pBack->m_pNext;
				}
				else
					m_pBack = m_pBack->m_pNext;
				m_pBack->m_data = std::forward<T>(data...);
			}
			else {
				m_pBack = 
					addNode(new Node(), nullptr, m_pBack, std::forward<T>(data...));
				incCapacity();
			}
		}
		incSize();
	}
	else if (!empty()) {
		{
			std::scoped_lock<std::mutex> lck(m_backMutex);
			if (bool isBackFront = (sizeEqualOne()); isBackFront) {
				std::scoped_lock<std::mutex> lck2(m_frontMutex);
				m_pBack = addNode(new Node(), nullptr, isBackFront ?
					m_pFront : m_pBack, std::forward<T>(data...));
			}
			else
				m_pBack = addNode(new Node(), nullptr, isBackFront ?
					m_pFront : m_pBack, std::forward<T>(data...));
		}
		incSizeCapacity();
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
	node->m_data = std::forward<_Vt...>(data...);
	return node;
}

template<class T>
void StealableQueue<T>::clear() {
	std::scoped_lock<std::mutex> lck(m_sizeMutex);
	std::scoped_lock<std::mutex> lck2(m_capacityMutex);
	while (size())pop<false>();
}

template<class T>
typename StealableQueue<T>::Node* StealableQueue<T>::steal(U32 number) {
	std::scoped_lock<std::mutex> lck(m_backMutex);
	assert(number <= safeSize());
	if (number > safeSize())
		return nullptr;

	Node* node = m_pBack;
	node->m_pNext = nullptr;
	if (number == safeSize()) {
		std::scoped_lock<std::mutex> lck(m_frontMutex);
		node = m_pFront;
		m_pFront = nullptr;
	}
	else {
		for (U32 i = 0; i ^ number - 1; ++i)
			node = node->m_pPrevious;
	}
	decSizeCapacity(number);
	if (node->m_pPrevious)
		node->m_pPrevious->m_pNext = m_pBack->m_pNext;
	m_pBack = node->m_pPrevious;
	node->m_pPrevious = nullptr;
	return node;
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