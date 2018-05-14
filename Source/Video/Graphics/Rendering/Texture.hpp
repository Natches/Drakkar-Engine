#pragma once

#include <Core/Engine/Types.hpp>

namespace drak {
namespace gfx {

class Texture {
public:
	virtual ~Texture() = default;

protected:
	U8* m_pixelData;
};

} // namespace gfx
} // namespace drak