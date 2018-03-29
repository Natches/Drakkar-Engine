#include <Core/Core.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <Engine/Components/Components.h>
#include <Engine/Scene/SceneSystem.h>
#include <Math/Matrix4x4.hpp>
#include <PxPhysicsAPI.h>

using namespace drak;
using namespace core;
using namespace components;
DK_IMPORT(drak::math)

class Player : public AGameObject {

	Transform* transform;
	int counter = 0;
	virtual void Update() override {
		if (counter <= 50000) {
		}
		else {
			Engine::stopGame();
		}
		counter++;
	}

	virtual void Start() override {
		transform = myScene->getComponentByHandle<Transform>(getHandle(ComponentType<Transform>::id));
	}
};

class Cube : public AGameObject {
	virtual void Update() override {
	}

	virtual void Start() override {
	}
};

class MainScene : public IManualSceneBlueprint {
	// Inherited via IManualSceneBlueprint
	virtual void build(Scene & scene) override
	{
		for (int i = 0; i < 10; ++i) {
			Player* p1 = (Player*)scene.addGameObject<Player>();
			scene.addComponentToGameObject<Transform>(p1);
			Transform* transform = scene.getComponentByHandle<Transform>(p1->getHandle(ComponentType<Transform>::id));
			transform->position = math::Vec3f(0, i*10, 0);
			transform->rotation = math::Vec4f(0, 0, 0, 0);
			transform->scale = math::Vec3f(1, 1, 1);

			scene.addComponentToGameObject<RigidBody>(p1);
			RigidBody* rigid = scene.getComponentByHandle<RigidBody>(p1->getHandle(ComponentType<RigidBody>::id));
			rigid->rigidActor = Engine::Get().getPhysicsSystem().getPhysics()->createRigidDynamic(physx::PxTransform(0, i * 10, 0));
			rigid->material = Engine::Get().getPhysicsSystem().getPhysics()->createMaterial(0.5, 0.5, 0.5);
			rigid->rigidActor->createShape(physx::PxBoxGeometry(0.5, 0.5, 0.5), *rigid->material);
			physx::PxRigidBodyExt::updateMassAndInertia(*(physx::PxRigidDynamic*)rigid->rigidActor, 10.f);
			scene.m_pPhysXScene->addActor(*rigid->rigidActor);
		}

		Cube* ground = (Cube*)scene.addGameObject<Cube>();
		scene.addComponentToGameObject<Transform>(ground);
		Transform* transform = scene.getComponentByHandle<Transform>(ground->getHandle(ComponentType<Transform>::id));
		transform->position = math::Vec3f(0, -100, 0);
		transform->rotation = math::Vec4f(0, 0, 0, 0);
		transform->scale = math::Vec3f(10, 1, 10);
		
		scene.addComponentToGameObject<RigidBody>(ground);
		RigidBody* rigid = scene.getComponentByHandle<RigidBody>(ground->getHandle(ComponentType<RigidBody>::id));
		rigid->rigidActor = Engine::Get().getPhysicsSystem().getPhysics()->createRigidStatic(physx::PxTransform(transform->position.x, transform->position.y, transform->position.z));
		rigid->material = Engine::Get().getPhysicsSystem().getPhysics()->createMaterial(0.5, 0.5, 0.5);
		rigid->rigidActor->createShape(physx::PxBoxGeometry(transform->scale.x / 2.f, transform->scale.y / 2.f, transform->scale.z / 2.f), *rigid->material);
		scene.m_pPhysXScene->addActor(*rigid->rigidActor);

	}
};

int main(int argc, char** argv) {
	Engine::Get().startup();
	MainScene scene;
	Engine::Get().loadScene(scene);
	Engine::Get().startLoop();
	Engine::Get().shutdown();
	system("pause");
}