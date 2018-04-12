#include <Engine/Engine.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Scene/LevelSystem.hpp>
namespace drak {
namespace core {
template <typename T>
void Engine::createAll() {
	T* t = new T();
	AGameObject* g = static_cast<AGameObject*>(t);
	if (g->getDTID() == 0) {
		// for each cube in file ie : Game object with same DTID
		//TEMP CODE
		for (int i = 0; i < 10; ++i) {
			AGameObject* newIstance = m_pLevelSystem->addGameObject<T>();
			//for each component of instance
			U32 id = 0;
			if (id == ComponentType<Transform>::id) {
				Transform& trans = newIstance->addComponent<Transform>();
				trans.position = math::Vec3f(0, i*15.f, 0);
				trans.scale = math::Vec3f(10, 10, 10);
				//set serialized variables of trans
			}
			if (id == ComponentType<RigidBody>::id) {
				RigidBody& rb = newIstance->addComponent<RigidBody>();
				rb.mass = 1.f;
				m_pPhysicsSystem->InitRigidBody(rb, *m_pLevelSystem);
			}
			if (id == ComponentType<Model>::id) {
				Model& model = newIstance->addComponent<Model>();
				model.albedo.r = 0.f;
				model.albedo.g = 1.f;
				model.albedo.b = 0.f;
			}
			if (id == ComponentType<BoxCollider>::id) {
				BoxCollider& boxCollider = newIstance->addComponent<BoxCollider>();
				boxCollider.width = 10;
				boxCollider.height = 10;
				boxCollider.depth = 10;
				boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
			}
#pragma region DELETE_TEST
			id = 1;
			if (id == ComponentType<Transform>::id) {
				Transform& trans = newIstance->addComponent<Transform>();
				trans.position = math::Vec3f(0, i*15.f, 0);
				trans.scale = math::Vec3f(10, 10, 10);
				//set serialized variables of trans
			}
			if (id == ComponentType<RigidBody>::id) {
				RigidBody& rb = newIstance->addComponent<RigidBody>();
				rb.mass = 1.f;
				m_pPhysicsSystem->InitRigidBody(rb, *m_pLevelSystem);
			}
			if (id == ComponentType<Model>::id) {
				Model& model = newIstance->addComponent<Model>();
				model.albedo.r = 0.f;
				model.albedo.g = 1.f;
				model.albedo.b = 0.f;
			}
			if (id == ComponentType<BoxCollider>::id) {
				BoxCollider& boxCollider = newIstance->addComponent<BoxCollider>();
				boxCollider.width = 10;
				boxCollider.height = 10;
				boxCollider.depth = 10;
				boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
			}
			id = 2;
			if (id == ComponentType<Transform>::id) {
				Transform& trans = newIstance->addComponent<Transform>();
				trans.position = math::Vec3f(0, i*15.f, 0);
				trans.scale = math::Vec3f(10, 10, 10);
				//set serialized variables of trans
			}
			if (id == ComponentType<RigidBody>::id) {
				RigidBody& rb = newIstance->addComponent<RigidBody>();
				rb.mass = 1.f;
				m_pPhysicsSystem->InitRigidBody(rb, *m_pLevelSystem);
			}
			if (id == ComponentType<Model>::id) {
				Model& model = newIstance->addComponent<Model>();
				model.albedo.r = 0.f;
				model.albedo.g = 1.f;
				model.albedo.b = 0.f;
			}
			if (id == ComponentType<BoxCollider>::id) {
				BoxCollider& boxCollider = newIstance->addComponent<BoxCollider>();
				boxCollider.width = 10;
				boxCollider.height = 10;
				boxCollider.depth = 10;
				boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
			}
			id = 3;
			if (id == ComponentType<Transform>::id) {
				Transform& trans = newIstance->addComponent<Transform>();
				trans.position = math::Vec3f(0, i*15.f, 0);
				trans.scale = math::Vec3f(10, 10, 10);
				//set serialized variables of trans
			}
			if (id == ComponentType<RigidBody>::id) {
				RigidBody& rb = newIstance->addComponent<RigidBody>();
				rb.mass = 1.f;
				m_pPhysicsSystem->InitRigidBody(rb, *m_pLevelSystem);
			}
			if (id == ComponentType<Model>::id) {
				Model& model = newIstance->addComponent<Model>();
				model.albedo.r = 0.f;
				model.albedo.g = 1.f;
				model.albedo.b = 0.f;
			}
			if (id == ComponentType<BoxCollider>::id) {
				BoxCollider& boxCollider = newIstance->addComponent<BoxCollider>();
				boxCollider.width = 10;
				boxCollider.height = 10;
				boxCollider.depth = 10;
				boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
			}
#pragma endregion
		}
	}
	delete t;
}
}
}