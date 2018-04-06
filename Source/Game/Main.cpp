#include <Core/Core.hpp>
#include <Engine/Engine.hpp>
#include <Core/Components/AGameObject.hpp>
#include <Engine/Components/Components.hpp>
#include <Engine/Scene/SceneSystem.hpp>
#include <Engine/Physics/SimulationEvent.hpp>
#include <Math/Matrix4x4.hpp>
#include <PxPhysicsAPI.h>
#include <string>

using namespace drak;
using namespace core;
using namespace components;
using namespace events;
using namespace function;
DK_IMPORT(drak::math)

class Player : public AGameObject {
	virtual void Update() override {
		Transform& trans = myScene->getComponentByHandle<Transform>(transformIDX);
		Model& model = myScene->getComponentByHandle<Model>(trans.m_handlesToComponents[ComponentType<Model>::id]);
		model.albedo.r = trans.position.x/100.f+0.1;
		model.albedo.g = trans.position.y/100.f+0.1;
		model.albedo.b = trans.position.z/100.f+0.1;
	}

	virtual void Start() override {
		/*RigidBody& rb = myScene->getComponentByHandle<RigidBody>(myScene->getComponentByHandle<Transform>(transformIDX).m_handlesToComponents[ComponentType<RigidBody>::id]);
		Engine::Get().getPhysicsSystem().AddCollisionCallback(
			&rb,
			PhysicsEventDispatcher::COLLISION_IN,
			new MemberFunction<Player, void, const Event*>
			(this, &Player::OnCollisionEnter));
		Engine::Get().getPhysicsSystem().AddCollisionCallback(
			&rb,
			PhysicsEventDispatcher::COLLISION_OUT,
			new MemberFunction<Player, void, const Event*>
			(this, &Player::OnCollisionExit));
		Engine::Get().getPhysicsSystem().AddCollisionCallback(
			&rb,
			PhysicsEventDispatcher::COLLISION_STAY,
			new MemberFunction<Player, void, const Event*>
			(this, &Player::OnCollisionStay));*/
	}

	void Player::OnCollisionEnter(const Event* pEvent) {
		Model& model = myScene->getComponentByHandle<Model>(myScene->getComponentByHandle<Transform>(transformIDX).m_handlesToComponents[ComponentType<Model>::id]);
		model.albedo.r = 1.0f;
		model.albedo.g = 0.0f;
		model.albedo.b = 0.f;
	}

	void Player::OnCollisionExit(const Event* pEvent) {
		//Model* model = myScene->getComponentByHandle<Model>(myScene->getComponentByHandle<Transform>(transformIDX)->m_handlesToComponents[ComponentType<Model>::id]);
		//model->albedo.r = 0.5f;
		//model->albedo.g = 0.1f*(F32)id;
		//model->albedo.b = 0.f;
	}

	void Player::OnCollisionStay(const Event* pEvent) {
		//Model* model = myScene->getComponentByHandle<Model>(myScene->getComponentByHandle<Transform>(transformIDX)->m_handlesToComponents[ComponentType<Model>::id]);
		//model->albedo.r = 0.1f*(F32)id;;
		//model->albedo.g = 0.5f;
		//model->albedo.b = 0.5f;
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
		physx::PxMaterial* mat =  Engine::Get().getPhysicsSystem().getPhysics()->createMaterial(0.5, 0.5, 0);
		physx::PxShape* cube = Engine::Get().getPhysicsSystem().getPhysics()->createShape(physx::PxBoxGeometry(5, 5, 5), *mat);
		int numOfCubes = 1000;
		for (int i = 0; i < numOfCubes; ++i) {
			Player* p1 = (Player*)scene.addGameObject<Player>();
			Transform& t = scene.getComponentByHandle<Transform>(p1->transformIDX);
			t.position = math::Vec3f(0, i*15, 0);
			t.rotation = math::Vec4f(0, 0, 0, 0);
			t.scale = math::Vec3f(10, 10, 10);

			scene.addComponentToGameObject<Model>(p1);
			Model& model = scene.getComponentByHandle<Model>(t.m_handlesToComponents[ComponentType<Model>::id]);
			model.albedo.r = 1.f;
			model.albedo.g = 1.f;
			model.albedo.b = 1.f;

			scene.addComponentToGameObject<RigidBody>(p1);
			RigidBody& rigid = scene.getComponentByHandle<RigidBody>(t.m_handlesToComponents[ComponentType<RigidBody>::id]);
			rigid.rigidActor = Engine::Get().getPhysicsSystem().getPhysics()->createRigidDynamic(physx::PxTransform(
				t.position.x,
				t.position.y,
				t.position.z));
			rigid.rigidActor->attachShape(*cube);
			((physx::PxRigidDynamic*)rigid.rigidActor)->setSleepThreshold(0.010);
			rigid.rigidActor->userData = p1;
			physx::PxRigidBodyExt::updateMassAndInertia(*(physx::PxRigidDynamic*)rigid.rigidActor, 10.f);
			scene.m_pPhysXScene->addActor(*rigid.rigidActor);
		}

		Cube* ground = scene.addGameObject<Cube>();
		Transform& t = scene.getComponentByHandle<Transform>(ground->transformIDX);
		t.position = math::Vec3f(0, -350, 0);
		t.rotation = math::Vec4f(0, 0, 0, 0);
		t.scale = math::Vec3f(3000, 100, 3000);
		
		scene.addComponentToGameObject<RigidBody>(ground);
		RigidBody& rigid = scene.getComponentByHandle<RigidBody>(t.m_handlesToComponents[ComponentType<RigidBody>::id]);
		rigid.rigidActor = Engine::Get().getPhysicsSystem().getPhysics()->createRigidStatic(
			physx::PxTransform(t.position.x, t.position.y, t.position.z));
		rigid.material = Engine::Get().getPhysicsSystem().getPhysics()->createMaterial(0.5, 0.5, 0);
		rigid.rigidActor->createShape(physx::PxBoxGeometry(t.scale.x / 2.f,
			t.scale.y / 2.f, t.scale.z / 2.f), *rigid.material);
		rigid.rigidActor->userData = ground;

		scene.m_pPhysXScene->addActor(*rigid.rigidActor);

	}
};

int main(int argc, char** argv) {
	Engine::Get().startup();
	MainScene scene;
	Engine::Get().loadScene(scene);
	Engine::Get().startLoop();
	Engine::Get().shutdown();
}