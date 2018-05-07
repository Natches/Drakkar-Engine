#pragma once

#include <memory>
#include <Core/Core.hpp>

namespace drak {

class AResource {
public:
	enum ELoadState : U8 {
		PENDING,
		LOADING,
		READY
	};

public:
	virtual ~AResource() = default;

protected:
	//AResource(const std::string& filename);

protected:
	ELoadState	m_loadState;
};

using AResourcePtr = std::shared_ptr<AResource>;

} // namespace drak