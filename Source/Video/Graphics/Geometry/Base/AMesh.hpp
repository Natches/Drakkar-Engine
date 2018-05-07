#pragma once

#include <Core/Engine/Types.hpp>
#include <Core/Utils/ClassUtils.hpp>

namespace drak {
namespace geom {

class AMesh {
public:
	virtual ~AMesh() = default;

	DK_GETTER_C(I32, attributeNumber, m_attributeNumber)

private:
	I32 m_attributeNumber;

protected:
	AMesh() = delete;
	AMesh(I32 attributeN);
};

} // namespace geom
} // namespace drak