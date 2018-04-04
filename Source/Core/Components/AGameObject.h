#pragma once
#include <Core/Core.hpp>
#include <map>

namespace drak {
class Scene;
namespace components {
	class Transform;
}
class AGameObject
{
public:
	AGameObject() = default;
	~AGameObject() = default;
	//inline int getHandle(int id) { return m_handlesToComponents[id]; }

	virtual void Update() = 0;
	virtual void Start() = 0;
	U64 transformIDX;
	drak::Scene* myScene;
	U32 id;
};
}