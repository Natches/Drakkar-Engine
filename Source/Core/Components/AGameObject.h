#pragma once
#include <Core/Core.hpp>
#include <map>

namespace drak {
class Scene;
class AGameObject
{
public:
	AGameObject() = default;
	~AGameObject() = default;
	void setComponentFlag(int id, bool value);
	bool getComponentFlag(int id);
	void setHandleIDPair(int id, int handle);
	inline int getHandle(int id) { return m_handlesToComponents[id]; }
	virtual void Update() = 0;
	virtual void Start() = 0;
	U64 m_componentFlags;
	std::map<U32, U32> m_handlesToComponents;
	drak::Scene* myScene;
	U32 id;
};
}