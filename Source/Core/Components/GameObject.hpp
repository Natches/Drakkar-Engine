#pragma once
#include <Core/Core.hpp>
#include <Serialization\MetaData.hpp>
#include <unordered_map>
#include <vector>
#include <string>

namespace drak {
	class LevelSystem;
namespace components {
	struct Transform;
}

class GameObject
{
DK_SERIALIZED_OBJECT(GameObject)
public:
	GameObject() = default;
	~GameObject() = default;

	template <typename T>
	T& getComponent() {
		if (getComponentFlag(components::ComponentType<T>::id))
			return level->getComponentByHandle<T>(m_componentHandles[components::ComponentType<T>::id]);
	}

	template <typename T>
	T& addComponent() {
		if (!getComponentFlag(components::ComponentType<T>::id)) {
			componentCount++;
			return level->addComponentToGameObject<T>(*this);
		}
		else
			return level->getComponentByHandle<T>(getComponentIDX(components::ComponentType<T>::id));
	}

	void setComponentFlag(I64 id, bool value) {
		m_componentFlags = value ? m_componentFlags | (1LL << id) : m_componentFlags ^ (1LL << id);
	}
	bool getComponentFlag(I64 id) {
		return (m_componentFlags & (1LL << id)) == (1LL << id);
	}
	void setHandleIDPair(U64 id, U64 handle) {
		m_componentHandles.insert(std::make_pair(id, handle));
	}
	inline U64 getComponentIDX(U64 id) {
		if (getComponentFlag(id))
			return m_componentHandles[id];
		return -1;
	}
	inline U32 getIdx() {
		return idx;
	}
	inline void setIdx(U32 idx) {
		this->idx = idx;
	}
	inline void setLevel(LevelSystem* level) {
		this->level = level;
	}
	inline LevelSystem* getLevel() {
		return level;
	}
	inline bool isRoot() {
		return m_isRoot;
	}
	std::map<U64, U64>& getComponentHandles() {
		return m_componentHandles;
	}

	void makeRoot();
	void setParent(U32 parentIDX);
	void setParent(GameObject& parent);
	U64 componentCount;
	std::string name;
private:
	std::map<U64, U64> m_componentHandles;
	U64 m_componentFlags = 0;
	LevelSystem* level;
	std::vector<U32> childrenIDXs;
	U32 parentIDX;
	U32 idx;
	bool m_isRoot = true;
	void attachChild(U32 childIDX);
	void attachChild(GameObject& child);
	void removeChild(U32 childIDX);
	void removeChild(GameObject& child);
};
}

DK_METADATA_BEGIN(drak::GameObject)
DK_PUBLIC_FIELDS(name, m_componentHandles, m_componentFlags, childrenIDXs, parentIDX, idx, m_isRoot)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END