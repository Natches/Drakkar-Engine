#pragma once
#include <Core\Core.hpp>
#include <map>

namespace drak {
namespace core {
	class Scene;
}
}

class AGameObject
{
public:
	AGameObject() = default;
	~AGameObject() = default;
	DRAK_API void setComponentFlag(int id, bool value);
	DRAK_API bool getComponentFlag(int id);
	DRAK_API void setHandleIDPair(int id, int handle);
	DRAK_API int getHandle(int id);
	DRAK_API virtual void Update() {};
	DRAK_API virtual void Start() {};
	DRAK_API drak::core::Scene* CurrentScene();
	drak::core::Scene* myScene;
private:
	U64 m_componentFlags;
	std::map<int, int> m_handlesToComponents;
};