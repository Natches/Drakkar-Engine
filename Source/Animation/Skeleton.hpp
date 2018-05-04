#pragma once

#include <Animation/Bone.hpp>

namespace drak {
namespace animation {

class Skeleton final {
public:
	Skeleton() = delete;
	Skeleton(const Bone& b) = delete;
	Skeleton(Bone&& b);
	Skeleton(const Skeleton& skTon);
	Skeleton(Skeleton&& skTon);

	Skeleton& operator=(const Skeleton& skTon);
	Skeleton& operator=(Skeleton&& skTon);

	Joint jointByName(const std::string& name);

private:
	Bone m_base;
};

} // namespace animation
} // namespace drak