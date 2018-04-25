#pragma once

#include <memory>
#include <unordered_map>

namespace drak {
namespace gfx {
	class Model;
	class Material;
	class Shader;
	class Texture;
} // namespace gfx

namespace geom {
	class Mesh;
} // namespace geom

template<class T>
using ResourcePtr	= std::shared_ptr<T>;
using ModelPtr		= ResourcePtr<gfx::Model>;
using MaterialPtr	= ResourcePtr<gfx::Material>;
using ShaderPtr		= ResourcePtr<gfx::Shader>;
using TexturePtr	= ResourcePtr<gfx::Texture>;
using MeshPtr		= ResourcePtr<geom::Mesh>;

template<class T>
using ResourceMap	= std::unordered_map<std::string, ResourcePtr<T>>;
using ModelMap		= ResourceMap<gfx::Model>;
using MaterialMap	= ResourceMap<gfx::Material>;
using ShaderMap		= ResourceMap<gfx::Shader>;
using TextureMap	= ResourceMap<gfx::Texture>;
using MeshMap		= ResourceMap<geom::Mesh>;
} // namespace drak