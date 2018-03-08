#include "Core/SceneSystem.h"
#include <iostream>
int main() {
	drak::core::SceneSystem sceneSystem;
	sceneSystem.Startup();
	drak::core::MyTestSceneBlueprint blueprint;
	sceneSystem.LoadScene(blueprint);
	sceneSystem.Shutdown();
	std::cin.get();
}