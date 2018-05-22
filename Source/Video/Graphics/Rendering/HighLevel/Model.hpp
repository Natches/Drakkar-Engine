#pragma once

#include <string>

namespace drak {
class ModelManager;
namespace gfx {

struct Model final {
public:
	Model() = delete;
	Model(const std::string& meshName, const std::string& materialName);
	~Model() = default;

	using Manager = ModelManager;

public:
	std::string m_meshName;
	std::string m_materialName;
};

} // namespace gfx
} // namespace drak