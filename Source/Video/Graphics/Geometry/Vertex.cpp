#include <Video/Graphics/Geometry/Vertex.hpp>

using namespace drak::math;

namespace drak {
namespace geom {

const VertexAttribDesc g_VertexAttribDescs[] = {
	{ VERT_ATTR_POS,	FLOAT, 3u, false },
	{ VERT_ATTR_NORMAL, FLOAT, 3u, false },
	{ VERT_ATTR_UV,		FLOAT, 2u, false }
};

} // namespace geom
} // namespace drak