#pragma once

#include <Core/Core.hpp>

#include <atomic>
#include <mutex>

namespace drak {
namespace thread {

template<class T>
class StealableQueue {
	DK_NONCOPYABLE(StealableQueue)
	struct StealableQueueNode {
		StealableQueueNode() = default;
		StealableQueueNode(StealableQueueNode* previous, StealableQueueNode* next, const T& data);
		StealableQueueNode(StealableQueueNode* previous, StealableQueueNode* next, T&& data);
		~StealableQueueNode() = default;

		StealableQueueNode* m_pPrevious;
		StealableQueueNode* m_pNext;
		T m_data;
	};

	using Node = typename StealableQueueNode;

public:
	StealableQueue();
	StealableQueue(StealableQueue&& queue);
	~StealableQueue();

	StealableQueue& operator=(StealableQueue&& queue);

	template<bool DeallocateNode = true>
	void pop();

	void steal(U32 number, StealableQueue<T>& queue);

	void push(const T& Data);
	void push(T&& Data);
	template<class..._Vt>
	void emplace(_Vt&&...data);

	T front();
	T back();

	U32 capacity() const;
	U32 size() const;
	bool empty() const;

	U32 safeCapacity();
	U32 safeSize();
	bool safeEmpty();

	void reserve(U32 ui);
	void clear();
	void shrinkToFit();

	void swap(StealableQueue& queue);

private:
	auto steal(U32 number);

	template<class..._Vt>
	Node* addNode(Node* node, Node* next, Node* previous, _Vt&&...data);

private:
	bool emptyHasCapacity();
	bool emptyHasNoCapacity();
	bool capacityGreaterThanSize();
	bool sizeEqualOne();

private:
	void incSize();
	void incCapacity();
	void incSizeCapacity();

	void incSize(U32 ui);
	void incCapacity(U32 ui);
	void incSizeCapacity(U32 ui);

	void decSize();
	void decCapacity();
	void decSizeCapacity();

	void decSize(U32 ui);
	void decCapacity(U32 ui);
	void decSizeCapacity(U32 ui);

private:
	Node *m_pFront, *m_pBack;
	Node *m_pFrontUnUsedCapacity, *m_pBackUnUsedCapacity;
	std::mutex m_mutex;
	std::atomic<U32> m_size;
	std::atomic<U32> m_capacity;
};

//TODO Better Mutex implementation for this queue

} // namespace thread
} // namespace drak
#include <Threading/StealableQueue.inl>