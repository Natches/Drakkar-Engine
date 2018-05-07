#pragma once

#include <Core/Engine/Error.hpp>
#include <Animation/Skeleton/Bone/Bone.hpp>

namespace drak {
namespace animation {

class KeyFrame final {
public:
	KeyFrame() = default;
	~KeyFrame() = default;
	KeyFrame(const KeyFrame& kFrame);
	KeyFrame(KeyFrame&& kFrame);

	KeyFrame& operator=(const KeyFrame& kFrame);
	KeyFrame& operator=(KeyFrame&& kFrame);

	core::EError jointByName(const std::string& name, Joint& j) const;

private:
	std::map<std::string, Joint> m_jointList;
};

} // namespace animation
} // namespace drak