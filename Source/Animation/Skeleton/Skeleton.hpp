#pragma once

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

	DK_GETTER_REF_C(Bone, base, m_boneList.at(m_base))
	DK_GETTER_C(math::Mat4f, invGlobal, m_invGlobalPos)
	DK_GETTER_C(U32, boneCount, (U32)m_boneList.size())

	core::EError jointByName(const std::string& name, Joint& j) const;
	const Animation* animationByName(const std::string& name) const;

private:
	std::string m_base;
	std::map<std::string, Bone> m_boneList;
	std::map<std::string, Animation> m_animList;
	math::Mat4f m_invGlobalPos;
};

} // namespace animation
} // namespace drak