#pragma once

#include <Core/Utils/ServiceUtils.h>

namespace drak {
namespace sys {

struct ServiceLocator {

	struct Services {
	};

	void Startup(Services* services, types::Type* tList) {
		m_service = services;
		m_tList = tList;
	}

	Services* m_service;
	types::Type* m_tList;
};

} // namespace sys
} // namespace drak
