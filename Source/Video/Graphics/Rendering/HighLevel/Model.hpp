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
	Model(const std::string& meshName, const std::string& materialName);
	~Model() = default;

	using Manager = ModelManager;

public:
	std::string meshName;
	std::string materialName;

private:
	Model() = default;
};

} // namespace gfx
} // namespace drak