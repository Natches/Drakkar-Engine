#pragma once
#include <Core/Core.hpp>
namespace drak {
namespace core {

/*!
* \class ISystem
* \ingroup Core
* \brief Engine system interface
*
*/
class DRAK_API ISystem {
public:
	ISystem() = default;
	virtual ~ISystem() = default;
	
	virtual bool Startup() = 0;
	virtual void Shutdown() = 0;
};

} // namespace core
} // namespace drak