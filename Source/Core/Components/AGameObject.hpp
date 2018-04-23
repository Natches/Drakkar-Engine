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

//Plural component array container
struct PAC {
	U64* componentIDXs;
	U64 count;
};

class AGameObject
{
DK_SERIALIZED_OBJECT(AGameObject)
public:
	AGameObject() = default;
	~AGameObject() = default;
	//inline int getHandle(int id) { return m_handlesToComponents[id]; }

	virtual void update() { ; }
	virtual void start() { ; }

	template <typename T>
	T* getComponent(U32 n = 0) {
		if (getComponentFlag(components::ComponentType<T>::id)) {
			if (!std::is_base_of<components::IPlural, T>::value)
				return &level->getComponentByHandle<T>(m_handlesToComponents[components::ComponentType<T>::id]);
			else
				return nullptr;
		}
		return nullptr;
	}

	template <typename T>
	PAC getComponents() {
		if (getComponentFlag(components::ComponentType<T>::id) && std::is_base_of<components::IPlural, T>::value) {
			PAC pac;
			pac.count = m_handlesToComponents.bucket_size(m_handlesToComponents.bucket(components::ComponentType<T>::id));
			pac.componentIDXs = new U64[pac.count];
			std::unordered_map<U64, U64>::local_iterator it = m_handlesToComponents.begin(m_handlesToComponents.bucket(components::ComponentType<T>::id));
			for (U32 i = 0; i < pac.count; ++i, std::advance(it, 1)) {
				if(it->first == components::ComponentType<T>::id)
					pac.componentIDXs[i] = it->second;
			}
			return pac;
		}
	}

	template <typename T>
	T& addComponent() {
		if (!std::is_base_of<components::IPlural, T>::value) {
			if (!getComponentFlag(components::ComponentType<T>::id)) {
				componentCount++;
				return level->addComponentToGameObject<T>(*this);
			}
			else
				return *getComponent<T>();
		}
		else {
			componentCount++;
			return level->addComponentToGameObject<T>(*this);
		}

	}

	void setComponentFlag(I64 id, bool value) {
		m_componentFlags = value ? m_componentFlags | (1LL << id) : m_componentFlags ^ (1LL << id);
	}
	bool getComponentFlag(I64 id) {
		return (m_componentFlags & (1LL << id)) == (1LL << id);
	}
	void setHandleIDPair(U64 id, U64 handle) {
		m_handlesToComponents.insert(std::make_pair(id, handle));
	}
	inline U64 getComponentIDX(U64 id) {
		if (getComponentFlag(id))
			return m_handlesToComponents[id];
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
	std::string& getName() {
		return name;
	}
	inline U64 getDTID() {
		return derivedTypeID;
	}
	std::unordered_map<U64, U64>& getComponentHandles() {
		return m_handlesToComponents;
	}


	void makeRoot();
	void setParent(U32 parentIDX);
	void setParent(AGameObject& parent);
	U64 componentCount;
protected:
	std::string name;
	U64 derivedTypeID;
private:
	std::unordered_map<U64, U64> m_handlesToComponents;
	U64 m_componentFlags = 0;
	LevelSystem* level;
	std::vector<U32> childrenIDXs;
	U32 parentIDX;
	U32 idx;
	bool m_isRoot = true;
	void attachChild(U32 childIDX);
	void attachChild(AGameObject& child);
	void removeChild(U32 childIDX);
	void removeChild(AGameObject& child);
};
}

DK_METADATA_BEGIN(drak::AGameObject)
DK_PUBLIC_FIELDS(derivedTypeID, componentCount)
DK_PUBLIC_FIELD_COMPLEMENT
DK_METADATA_END
#define Component_B_from_A(gameObjectArray, AComponent, BComponentType, BComponentArray) BComponentArray##[##gameObjectArray##[##AComponent##.GameObjectIDX]->getComponentIDX(ComponentType<##BComponentType##>::id)]
