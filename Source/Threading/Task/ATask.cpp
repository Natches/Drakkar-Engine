#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace thread {
namespace task {

bool ATask::executed() const {
	return m_executed.load(std::memory_order_acquire);
}

void ATask::reset() {
	m_executed.store(false, std::memory_order_release);
}

} // namespace task
} // namespace thread
} // namespace drak