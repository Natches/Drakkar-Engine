#pragma once
#include <Serialization/MetaData.hpp>
#include <Engine/Components/ABehavior.hpp>
#include <Game/Cube.hpp>
#include <Game/CameraController.hpp>
#include <Game/Player.hpp>

namespace drak {
#define BEHAVIOR_CONTAINER(c)																				\
std::vector<behavior::##c*> c##BehaviorContainer;															\
public:																										\
std::vector<behavior::##c*>& get##c##BehaviorContainer() {return c##BehaviorContainer;}						\
private:

#define GET_BHVR_CONTAINER(c) get##c##BehaviorContainer()
#define BHVR_CONTAINER_PROPER(c) c##BehaviorContainer
#define BHVR BehaviorMonolith::Get()

//AKA S. Freud
class BehaviorMonolith {
DK_SERIALIZED_OBJECT(BehaviorMonolith)
	template <U32 n, class c>
	inline void* __bcByID() {}
	//#include "BehaviorContainers.gen"
	BEHAVIOR_CONTAINER(Cube)
	BEHAVIOR_CONTAINER(CameraController)
	BEHAVIOR_CONTAINER(Player)
	BehaviorMonolith();
public:
	static BehaviorMonolith& Get() {
		static BehaviorMonolith instance;
		return instance;
	}
	void load();
	void save();
	void init();
	void serializeEvent(const events::Event* pEvent);

};
}
DK_METADATA_BEGIN(drak::BehaviorMonolith)
DK_PUBLIC_FIELDS(BHVR_CONTAINER_PROPER(Cube), BHVR_CONTAINER_PROPER(CameraController), BHVR_CONTAINER_PROPER(Player))
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END