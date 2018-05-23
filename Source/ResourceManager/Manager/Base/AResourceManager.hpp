#pragma once

#include <ResourceManager/Manager/Base/IResourceManager.hpp>

namespace drak {

template<typename T, typename Map>
class AResourceManager : public IResourceManager<T> {
protected:
	virtual ~AResourceManager() {};

protected:
	virtual ResourcePtr<T> get(const std::string& name) override;
	virtual typename Resource<T>::ELoadState state(const std::string& name) const override;
	virtual void preload(const std::string& filename) override;
	virtual void unload(const std::string& name) override;
	virtual bool contain(const std::string& name) const override;

	Map m_map;
};

} //namespace drak

#include <ResourceManager/Manager/Base/AResourceManager.inl>