#pragma once

#include <cassert>
#include <Animation/Skeleton/Bone/Bone.hpp>

namespace drak {
class SkinnedMeshManager;
namespace animation {

class Skeleton final {
	friend class SkinnedMeshManager;
public:
	Skeleton() = default;
	Skeleton(const Skeleton& skTon);
	Skeleton(Skeleton&& skTon);
	Skeleton& operator=(const Skeleton& skTon);
	Skeleton& operator=(Skeleton&& skTon);

	DK_GETTER_REF_C(Bone, base, m_boneList[0])
	DK_GETTER_C(math::Mat4f, invGlobal, m_invGlobalPos)
	DK_GETTER_C(U32, boneCount, (U32)m_boneList.size())

	const Bone& bone(int idx) const { assert(idx < m_boneList.size()); return m_boneList[idx]; }
	core::EError idxByName(const std::string& name, U32& i) const;
	core::EError jointByName(const std::string& name, Joint& j) const;
	const Animation* animationByName(const std::string& name) const;

private:
	std::vector<Bone> m_boneList;
	std::map<std::string, U32> m_handleList;
	std::map<std::string, Animation> m_animList;
	math::Mat4f m_invGlobalPos;
};

} // namespace animation
} // namespace drak