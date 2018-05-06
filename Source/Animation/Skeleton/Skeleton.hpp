#pragma once

#include <Animation/Skeleton/Bone/Bone.hpp>

namespace drak {
namespace animation {

class Skeleton final {

	DK_NONCOPYABLE(Skeleton)

public:
	Skeleton() = delete;
	Skeleton(const Bone& b) = delete;
	Skeleton(Bone&& b);
	Skeleton(Skeleton&& skTon);

	Skeleton& operator=(Skeleton&& skTon);

	Joint jointByName(const std::string& name) const;

private:
	void buildBoneList(const Bone& b);
	void optimizeBoneList(const std::map<std::string, bool>& bonesUsefulness);
	void eraseFromHierarchy(Bone& b);

private:
	Bone m_base;
	std::map<std::string, Bone> m_boneList;
	std::vector<Animation> m_animList;
};

} // namespace animation
} // namespace drak