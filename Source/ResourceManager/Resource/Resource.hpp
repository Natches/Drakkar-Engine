#pragma once

#include <memory>
#include <string>
#include <Core/Core.hpp>

namespace drak {

template<typename T>
class Resource {

	friend class REMOVE_ALL_TYPE_MODIFIER(T)::Manager;

	DK_NONCOPYABLE(Resource)

public:
	enum ELoadState : U8 {
		UNKNOWN,
		PENDING,
		LOADING,
		READY
	};

public:
	Resource() = delete;
	Resource(const std::string& filename);
	Resource(const std::string& filename, T&& resource);
	Resource(Resource&& resource);
	virtual ~Resource() = default;

	Resource& operator=(Resource&& resource);

	DK_GETTER_C(ELoadState, loadState, m_loadState)
	DK_GETTER_REF_C(std::string, filename, m_filename)
	DK_GETTER_REF_C(T, resource, m_resource)

private:
	DK_SETTER(ELoadState, loadState, m_loadState)
	T m_resource;
	std::string m_filename;
	ELoadState	m_loadState;
};

} // namespace drak