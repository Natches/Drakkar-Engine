#pragma once

#include <string>
#include <Core/Engine/Types.hpp>

namespace drak {
class TextureManager;
namespace gfx {

class Texture final {
public:
	Texture() = delete;
	Texture(const std::string& name, std::vector<U8>&& pixels,
		U32 width, U32 height, U16 format, U8 channels);
	~Texture() = default;

	using Manager = TextureManager;

	DK_GETTER_REF_C(std::string, name, m_name)
	DK_GETTER_C(U32, width, m_width)
	DK_GETTER_C(U32, height, m_height)
	DK_GETTER_C(U16, format, m_format)
	DK_GETTER_C(U8, channels, m_channels)
	DK_GETTER_REF_C(std::vector<U8>, pixels, m_pixels)

private:
	std::string m_name;
	std::vector<U8> m_pixels;
	U32 m_width;
	U32 m_height;
	U16 m_format;
	U8  m_channels;
};

} // namespace gfx
} // namespace drak