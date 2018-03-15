#pragma once

#include <Core/ServiceUtils.h>

namespace drak {
namespace sys {

struct ServiceLocator {

	struct Services {
	};

	void Startup(Services* services, Type* tList) {
		m_service = services;
		m_tList = tList;
	}

	using T = Type;

	Services* m_service;
	Type* m_tList;
};

} // namespace sys
} // namespace drak
