#pragma once

#include <Core/Core.hpp>

#include <atomic>
#include <mutex>

namespace drak {
namespace thread {

template<class T>
class StealableQueue {

	DK_NONMOVABLE_NONCOPYABLE(StealableQueue)
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
	~StealableQueue();

	template<bool DeallocateNode = true>
	void pop();

	void steal(U32 number, T* result);
	void steal(U32 number, StealableQueue<T>& queue);

	void push(const T& Data);
	void push(T&& Data);
	template<class..._Vt>
	void emplace(_Vt&&...data);

	T front();
	T back();

	U32 capacity();
	U32 size();
	bool empty();

	U32 safeCapacity();
	U32 safeSize();
	bool safeEmpty();

	void reserve(U32 ui);
	void clear();

private:
	Node* steal(U32 number);

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
	Node* m_pFront;
	Node* m_pBack;
	std::mutex m_frontMutex, m_backMutex, m_sizeMutex, m_capacityMutex;
	std::atomic<U32> m_size;
	std::atomic<U32> m_capacity;
};

} // namespace thread
} // namespace drak
#include <Threading/StealableQueue.inl>