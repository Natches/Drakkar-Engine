#pragma once
#include "Core.hpp"
#include <map>

struct ComponentIDHandlePair
{
	int id;
	int handle;
};

class AGameObject
{
public:
	AGameObject();
	~AGameObject();
	void setComponentFlag(int id, bool value);
	bool getComponentFlag(int id);
	void setHandleIDPair(int id, int handle);
	int getHandle(int id);
protected:
	U64 m_componentFlags;
	std::map<int, int> m_handlesToComponents;
};

class DebugCube : public AGameObject
{

};

