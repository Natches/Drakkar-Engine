#include <PrecompiledHeader/pch.hpp>

namespace drak {
namespace gfx {

Texture::Texture(const std::string& name, std::vector<U8>&& pixels,
	U32 width, U32 height,
	U16 format, U8 channels)
:	m_name(name), m_pixels(std::move(pixels)),
	m_width(width), m_height(height),
	m_format(format), m_channels(channels) {
}

} //namespace gfx
} //namespace drak

