#include <Threading/Task/TaskSequence.hpp>

namespace drak {
namespace thread {
namespace task {

template<class T, class...VArgs>
void TaskSequence::addTasks(T&& first, VArgs&&...args) {
	m_taskList.emplace_back(std::forward<T>(first));
	if constexpr(sizeof...(args))
		addTasks(std::forward<VArgs>(args)...);
}

} // namespace task
} // namespace thread
} // namespace drak
