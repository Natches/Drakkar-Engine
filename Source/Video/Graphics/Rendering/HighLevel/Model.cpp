#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {

Model::Model(const std::string& meshName, const std::string& materialName, bool skinned)
:	meshName(meshName), materialName(materialName), m_skinned(skinned) {
}

} //namespace gfx
} //namespace drak

