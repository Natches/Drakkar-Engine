#pragma once

#include <Core/Engine/Error.hpp>
#include <Animation/Bone.hpp>

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

	core::EError jointByName(const std::string& name);

private:
	std::vector<Joint> m_jointList;
};

} // namespace animation
} // namespace drak