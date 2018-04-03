#include <Core/Core.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.h>
#include <Engine/Components/Components.h>
#include <Engine/Scene/SceneSystem.h>
#include <Engine/Physics/SimulationEvent.h>
#include <Math/Matrix4x4.hpp>
#include <PxPhysicsAPI.h>

using namespace drak;
using namespace core;
using namespace components;
using namespace events;
using namespace function;
DK_IMPORT(drak::math)

class Player : public AGameObject {
	int counter = 0;
	virtual void Update() override {
		if (counter <= 1000) {
		}
		else {
			Engine::stopGame();
		}
		counter++;
	}

	virtual void Start() override {
		MemberFunction<Player, void, const Event*>
			func(this, &Player::OnCollision);
		Engine::Get().getPhysicsSystem().AddCollisionCallback(
			*myScene->getComponentByHandle<RigidBody>(getHandle(ComponentType<RigidBody>::id)),
			PhysicsEventDispatcher::COLLISION_IN,
			&func);
		//MemberFunction<Player, void, const Event*> 
		//	func(this, &Player::cameraControl, &Keyboard::Get().event());
		//Keyboard::Get().addEventListener(events::Keyboard::KEY_DOWN, &func);
	}

	void Player::OnCollision(const Event* pEvent) {
		myScene->getComponentByHandle<Model>(getHandle(ComponentType<Model>::id))->albedo.b = 1;
	}

	//void Player::cameraControl(const Event* pEvt) {
	//	auto k = static_cast<const KeyEvent*>(pEvt);
	//	DK_SELECT(k->key)
	//		DK_CASE(Key::KEY_Q, printf("Hello\n"))
	//	DK_END
	//}

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
		physx::PxMaterial* mat =  Engine::Get().getPhysicsSystem().getPhysics()->createMaterial(0.5, 0.5, 0.5);
		physx::PxShape* cube = Engine::Get().getPhysicsSystem().getPhysics()->createShape(physx::PxBoxGeometry(2.5, 2.5, 2.5), *mat);

		for (int i = 0; i < 10; ++i) {
			Player* p1 = (Player*)scene.addGameObject<Player>();
			scene.addComponentToGameObject<Transform>(p1);
			Transform* transform = scene.getComponentByHandle<Transform>(p1->getHandle(ComponentType<Transform>::id));
			transform->position = math::Vec3f(0, i*10, 0);
			transform->rotation = math::Vec4f(0, 0, 0, 0);
			transform->scale = math::Vec3f(5, 5, 5);

			scene.addComponentToGameObject<Model>(p1);
			Model* model = scene.getComponentByHandle<Model>(p1->getHandle(ComponentType<Model>::id));
			model->albedo.r = 0.1f*(F32)i;
			model->albedo.g = 0.2f;

			scene.addComponentToGameObject<RigidBody>(p1);
			RigidBody* rigid = scene.getComponentByHandle<RigidBody>(p1->getHandle(ComponentType<RigidBody>::id));
			rigid->rigidActor = Engine::Get().getPhysicsSystem().getPhysics()->createRigidDynamic(physx::PxTransform(0, i * 10, 0));
			rigid->rigidActor->attachShape(*cube);
			rigid->rigidActor->setName("1");
			physx::PxRigidBodyExt::updateMassAndInertia(*(physx::PxRigidDynamic*)rigid->rigidActor, 10.f);
			scene.m_pPhysXScene->addActor(*rigid->rigidActor);
		}

		Cube* ground = scene.addGameObject<Cube>();
		scene.addComponentToGameObject<Transform>(ground);
		Transform* transform = scene.getComponentByHandle<Transform>(ground->getHandle(ComponentType<Transform>::id));
		transform->position = math::Vec3f(0, -100, 0);
		transform->rotation = math::Vec4f(0, 0, 0, 0);
		transform->scale = math::Vec3f(100, 5, 100);
		
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
}