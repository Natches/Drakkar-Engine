#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace animation {

Skeleton::Skeleton(Bone&& b) : m_base(std::move(b)) {
	b = Bone();
	buildBoneList(m_base);
}

Skeleton::Skeleton(Skeleton&& skTon) : m_base(std::move(skTon.m_base)),
	m_boneList(std::move(skTon.m_boneList)) {
	skTon.m_base = Bone();
}

Skeleton& Skeleton::operator=(Skeleton&& skTon) {
	m_base = std::move(skTon.m_base);
	m_boneList = std::move(skTon.m_boneList);
	skTon.m_base = Bone();
	return *this;
}

core::EError Skeleton::jointByName(const std::string& name, Joint& j) const {
	if (m_boneList.find(name) != m_boneList.end()) {
		j = m_boneList.at(name).joint;
		return core::EError::NO_ERROR;
	}
	else
		return core::EError::JOINT_NOT_FOUND;
}

void Skeleton::buildBoneList(const Bone& b) {
	m_boneList[b.name] = b;
	for (auto child : m_base.children) {
		buildBoneList(child);
	}
}

void Skeleton::eraseFromHierarchy(Bone& b) {
	for (auto& child : b.children) {
		eraseFromHierarchy(child);
	}
	b.parent->children.erase(std::find(b.parent->children.begin(), b.parent->children.end(), b));
	m_boneList.erase(b.name);
}

void Skeleton::optimizeBoneList() {
	std::unordered_map<std::string, bool> neededBones;
	for (auto& bone : m_boneList)
		neededBones[bone.first] = false;
	for (auto& anim : m_animList) {
		anim.buildNecessaryBoneList(neededBones);
	}
	for (auto& nBone : neededBones) {
		if (!nBone.second)
			eraseFromHierarchy(m_boneList[nBone.first]);
	}
}

} // namespace animation
} // namespace drak