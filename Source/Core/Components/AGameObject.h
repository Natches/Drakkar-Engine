#pragma once
#include <Core/Core.hpp>
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
	 void setComponentFlag(int id, bool value);
	 bool getComponentFlag(int id);
	 void setHandleIDPair(int id, int handle);
	 int getHandle(int id);
	 virtual void Update() = 0;
	 virtual void Start() = 0;
	 drak::core::Scene* CurrentScene();
	drak::core::Scene* myScene;
private:
	U64 m_componentFlags;
	std::map<int, int> m_handlesToComponents;
};