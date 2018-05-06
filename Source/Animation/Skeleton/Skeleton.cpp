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

Joint Skeleton::jointByName(const std::string& name) const {
	return m_boneList.at(name).joint;
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

void Skeleton::optimizeBoneList(const std::map<std::string, bool>& bonesUsefulness) {
	for (auto& p : bonesUsefulness) {
		if (!p.second)
			eraseFromHierarchy(m_boneList[p.first]);
	}
}

} // namespace animation
} // namespace drak