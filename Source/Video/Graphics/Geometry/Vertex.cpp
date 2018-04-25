#include <PrecompiledHeader/pch.hpp>

using namespace drak::math;

namespace drak {
namespace geom {

Vertex::Vertex(
	const Vec3f& aPos,
	const Vec3f& aNormal,
	const Vec2f& aUV)
	: pos(aPos), normal(aNormal), uv(aUV) {
}

} // namespace geom
} // namespace drak