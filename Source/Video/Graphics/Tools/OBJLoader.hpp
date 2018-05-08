#pragma once

#include <Video/Graphics/Geometry/Mesh.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>

namespace drak {
namespace gfx {
namespace tools {

class OBJLoader final {
public:
	OBJLoader() = default;
	~OBJLoader() = default;

	bool load(const std::string& objPath, geom::Mesh<geom::Vertex1P1N1UV>& outMesh);

private:
	math::Vec2f readVec2(std::ifstream& fs);
	math::Vec3f readVec3(std::ifstream& fs);
};
} // namespace tools
} // namespace gfx
} // namespace drak