#pragma once
#include "Core.hpp"
#include <vector>

namespace drak {
namespace components {

template <typename T>
inline int UniqueID() {
	static int i = 0;
	return i++;
}

template <typename T>
inline constexpr int ComponentID() {
	constexpr int id = 0;
	return id;
}

struct AComponent {
public:
	AComponent();
	~AComponent();
	int id;
private:
};

//DELETE AND REPLACE AS SOON AS MATH IS ADDED
struct vec3TEMP {
	F32 x;
	F32 y;
	F32 z;
};

struct Transform : AComponent {
	std::vector<Transform*> children;
	vec3TEMP pos;
	Transform* parent;
	Transform();
	~Transform();
};



} //components
} //drak
