#pragma once

#include <memory>
#include <unordered_map>

#include <Core/Core.hpp>

namespace drak {

//////////////////////////////////////////////////////////////////////////
// Forward Declarations

namespace gfx {
class Model;
}

namespace geom {
class Mesh;
}

//////////////////////////////////////////////////////////////////////////

template<class T>
using ResourcePtr	= std::shared_ptr<T>;
using ModelPtr		= ResourcePtr<gfx::Model>;
using MeshPtr		= ResourcePtr<geom::Mesh>;

template<class T>
using ResourceMap	= std::unordered_map<std::string, ResourcePtr<T>>;
using ModelMap		= ResourceMap<gfx::Model>;
using MeshMap		= ResourceMap<geom::Mesh>;

}