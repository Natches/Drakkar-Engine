#pragma once
#include <Engine\Components\ABehavior.hpp>
#include <Engine/Scene/LevelSystem.hpp>

namespace drak {
namespace behavior {

class Player : public ABehaviorVariables {
DK_SERIALIZED_OBJECT(Player)
function::MemberFunction<Player, void, const events::Event*> updateBind;
function::MemberFunction<Player, void, const events::Event*> startBind;
void bindUpdateToEngine();
void bindStartToEngine();
void update(const events::Event* pEvent);
void start(const events::Event* pEvent);
const F32 movementSpeed = 100.f;
const F32 rotateSpeed = 100.f;
const math::Vec3f cameraOffset = math::Vec3f(0,160,200);
//F32 oldMouseX;
public:
	Player();
	~Player();
	void init();
	template <typename T>
	T* getComponent() {
		return  EngineCurrentLevel.getGameObjects()[gameObjectID].getComponent<T>();
	}
};
BHVR_TYPE(Player)
}
DK_METADATA_BEGIN(behavior::Player)
DK_PUBLIC_FIELDS(gameObjectID, name)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
}