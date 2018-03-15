#pragma once

#include <Core/Core.hpp>
#include <Core/ServiceLocator/ServiceLocator.hpp>

namespace drak {
namespace io {
/*!
* \class ResourceManager
* \ingroup IO
* \brief Class used to reference different services, used to manage different resource
*/
class ResourceManager final : public sys::ServiceLocator {
	DK_NONMOVABLE_NONCOPYABLE(ResourceManager)

public:
	static ResourceManager& instance() {
		static ResourceManager s_instance;
		return s_instance;
	}

private:
	ResourceManager();
	~ResourceManager() = default;
};

} //namespace io
} //namespace drak
