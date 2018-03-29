#pragma once

#include <Video/Graphics/Geometry/Mesh.hpp>

namespace drak {
namespace video {

class OBJLoader final {
public:
	OBJLoader() = default;
	~OBJLoader() = default;

	bool load(const std::string& objPath, geom::Mesh& outMesh);

private:
	math::Vec2f readVec2(std::ifstream& fs);
	math::Vec3f readVec3(std::ifstream& fs);

private:
	static const char* OBJ_PARSE_VEC2F;
	static const char* OBJ_PARSE_VEC3F;
	static const char* OBJ_PARSE_TRI;
};

} // namespace video
} // namespace drak