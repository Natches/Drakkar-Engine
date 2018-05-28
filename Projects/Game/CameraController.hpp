#pragma once
#include <Engine\Components\ABehavior.hpp>

namespace drak {
namespace behavior {

class CameraController : public ABehaviorVariables {
DK_SERIALIZED_OBJECT(CameraController)
function::MemberFunction<CameraController, void, const events::Event*> updateBind;
function::MemberFunction<CameraController, void, const events::Event*> startBind;
void bindUpdateToEngine();
void bindStartToEngine();
void update(const events::Event* pEvent);
void start(const events::Event* pEvent);
const F32 movementSpeed = 10.f;
public:
	CameraController();
	~CameraController();
	void init();
	template <typename T>
	T& getComponent() {
		return  CurrentLevel.getGameObjects()[gameObjectID].getComponent<T>();
	}
};
BHVR_TYPE(CameraController)
}
DK_METADATA_BEGIN(behavior::CameraController)
DK_PUBLIC_FIELDS(gameObjectID, name)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
}