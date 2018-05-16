#pragma once

#include <memory>
#include <Core/Core.hpp>

namespace drak {

template<typename T>
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
	AResource(const std::string& filename);

protected:
	std::string filename;
	ELoadState	m_loadState;
};

template<typename T>
using AResourcePtr = std::shared_ptr<AResource<T>>;

} // namespace drak