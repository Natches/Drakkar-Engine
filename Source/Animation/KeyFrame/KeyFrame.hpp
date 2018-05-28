#pragma once

#include <Core/Engine/Error.hpp>
#include <Animation/Skeleton/Bone/Bone.hpp>

namespace drak {
class SkinnedMeshManager;
namespace animation {

class Keyframe final {
	friend class SkinnedMeshManager;
public:
	Keyframe() = default;
	~Keyframe() = default;
	Keyframe(const Keyframe& kFrame);
	Keyframe(Keyframe&& kFrame);

	Keyframe& operator=(const Keyframe& kFrame);
	Keyframe& operator=(Keyframe&& kFrame);

	core::EError jointByName(const std::string& name, Joint& j) const;

private:
	std::map<std::string, Joint> m_jointList;
};

} // namespace animation
} // namespace drak