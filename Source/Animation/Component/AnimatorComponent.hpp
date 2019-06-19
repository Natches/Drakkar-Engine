#pragma once

#include <string>
#include <Animation/Animator.hpp>
#include <Core/Utils/AComponentUtils.hpp>
#include <Serialization/MetaData.hpp>
#include <Core/Utils/ClassUtils.hpp>

DRAK_COMPONENT_START(Animator)
DK_SERIALIZED_OBJECT(Animator)
DRAK_API virtual void deleteComponent() override { ; }
DRAK_API virtual  void initComponent() override { ; }
drak::animation::Animator animator;
F32 speed;
DK_GETTER_C(bool, dirty, m_dirty)
DK_GETTER_REF_C(std::string, animation, m_animation)
DK_SETTER_REF_C(std::string, animation, m_dirty = true; m_animation)
private:
	bool m_dirty;
	std::string m_animation;
DRAK_COMPONENT_END(Animator)

DK_METADATA_BEGIN(drak::components::Animator)
DK_PUBLIC_FIELDS(speed, m_animation, animator, m_dirty, idx, GameObjectID)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END