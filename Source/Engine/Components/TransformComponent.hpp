#pragma once
#include <Core/Utils/AComponentUtils.hpp>
#include <Serialization\MetaData.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
#include <Math/Quaternion.hpp>
#include <map>

DRAK_COMPONENT_START(Transform)
DK_SERIALIZED_OBJECT(Transform)
inline const math::Vec3f& getGlobalPosition()const {return m_globalPosition; }
inline const math::Vec3f& getLocalPosition()const { return m_localPosition; }
inline const math::Vec3f& getGlobalScale()const { return m_globalScale; }
inline const math::Vec3f& getLocalScale()const { return m_localScale; }
inline const math::Quaternion& getLocalRotation()const { return m_localRotation; }
inline const math::Quaternion& getGlobalRotation()const { return m_globalRotation; }
inline void setGlobalPosition(const math::Vec3f& globalPos) { m_globalPosition = globalPos; m_dirty = true;}
inline void setLocalPosition(const math::Vec3f& localPos) { m_localPosition = localPos; m_dirty = true;}
inline void setGlobalScale(const math::Vec3f& globalScale) {  m_globalScale = globalScale; m_dirty = true;}
inline void setLocalScale(const math::Vec3f& localScale) {  m_localScale = localScale; m_dirty = true;}
inline void setLocalRotation(const math::Quaternion& localRotation) {  m_localRotation = localRotation; m_dirty = true;}
inline void setGlobalRotation(const math::Quaternion& globalRotation) { m_globalRotation = globalRotation; m_dirty = true;}
inline bool& isRoot() { return m_isRoot; }
inline bool& isDirty() { return m_dirty; }
private:
math::Vec3f m_globalPosition = math::Vec3f(0, 0, 0);
math::Vec3f m_globalScale = math::Vec3f(1, 1, 1);
math::Quaternion m_globalRotation = math::Quaternion(1.f, math::Vec3f(0.f));
math::Vec3f m_localPosition = math::Vec3f(0, 0, 0);
math::Vec3f m_localScale = math::Vec3f(1, 1, 1);
math::Quaternion m_localRotation = math::Quaternion(1.f, math::Vec3f(0.f));
bool m_dirty = false;
bool m_isRoot = true;
DRAK_COMPONENT_END(Transform)


//TODO add incremetor functions
void setTransformPos(drak::components::Transform& t, drak::math::Vec3f newPos);
void setTransformRot(drak::components::Transform& t, drak::math::Quaternion newRot);

DK_METADATA_BEGIN(drak::components::Transform)
DK_PUBLIC_FIELDS(m_globalPosition, m_globalScale, m_globalRotation, m_localPosition, m_localScale, m_localRotation, m_isRoot, idx, GameObjectID)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
