#pragma once

#include <memory>
#include <unordered_map>

namespace drak {
namespace gfx {
	struct Model;
	class Material;
	class IShader;
	class Texture;
} // namespace gfx

namespace geom {
	class Mesh;
	class SkinnedMesh;
} // namespace geom

template<typename T>
class Resource;

template<class T>
using ResourcePtr		= std::shared_ptr<Resource<T>>;
using ModelPtr			= ResourcePtr<gfx::Model>;
using MaterialPtr		= ResourcePtr<gfx::Material>;
using ShaderPtr			= ResourcePtr<gfx::IShader*>;
using TexturePtr		= ResourcePtr<gfx::Texture>;
using MeshPtr			= ResourcePtr<geom::Mesh>;
using SkinnedMeshPtr	= ResourcePtr<geom::SkinnedMesh>;

template<class T>
using ResourceMap		= std::unordered_map<std::string, ResourcePtr<T>>;
using ModelMap			= ResourceMap<gfx::Model>;
using MaterialMap		= ResourceMap<gfx::Material>;
using ShaderMap			= ResourceMap<gfx::IShader*>;
using TextureMap		= ResourceMap<gfx::Texture>;
using MeshMap			= ResourceMap<geom::Mesh>;
using SkinnedMeshMap	= ResourceMap<geom::SkinnedMesh>;
} // namespace drak