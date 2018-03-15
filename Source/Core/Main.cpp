#include "Core/SceneSystem.h"
#include <iostream>
#include <vector>

template <int T>
inline int foo();

template <>
inline int foo<2>() {}

int main() {
	drak::core::SceneSystem sceneSystem;
	sceneSystem.Startup();
	drak::core::MyTestSceneBlueprint blueprint;
	sceneSystem.loadScene(blueprint);
	sceneSystem.Shutdown();
	std::cin.get();
}