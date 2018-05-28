#pragma once

#include <string>

namespace drak {
template<typename T>
class Resource;
class ModelManager;
namespace gfx {

struct Model final {
	friend class Resource<Model>;
public:
	Model(const std::string& meshName, const std::string& materialName, bool skinned);
	~Model() = default;

	using Manager = ModelManager;
	DK_GETTER_C(bool, isSkinned, m_skinned)

public:
	std::string meshName;
	std::string materialName;

private:
	Model() = default;

private:
	bool m_skinned = false;
};

} // namespace gfx
} // namespace drak