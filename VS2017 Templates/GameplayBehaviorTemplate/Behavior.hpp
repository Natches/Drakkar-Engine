#pragma once
#include <Engine\Components\ABehavior.hpp>

namespace drak {
namespace behavior {

class $safeitemname$ : public ABehaviorVariables {
DK_SERIALIZED_OBJECT($safeitemname$)
function::MemberFunction<$safeitemname$, void, const events::Event*> updateBind;
function::MemberFunction<$safeitemname$, void, const events::Event*> startBind;
void bindUpdateToEngine();
void bindStartToEngine();
void update(const events::Event* pEvent);
void start(const events::Event* pEvent);
public:
	$safeitemname$();
	~$safeitemname$();
	void init();
	template <typename T>
	T& getComponent() {
		return  CurrentLevel.getGameObjects()[gameObjectID].getComponent<T>();
	}
};
BHVR_TYPE($safeitemname$)
}
DK_METADATA_BEGIN(behavior::$safeitemname$)
DK_PUBLIC_FIELDS(gameObjectID, name)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
}