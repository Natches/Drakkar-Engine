#include <Engine/Engine.hpp>
#include <Engine/Physics/PhysicsSystem.hpp>
#include <Engine/Scene/LevelSystem.hpp>
#include <Serialization\Serializer.hpp>
namespace drak {
namespace core {
template <typename T>
void Engine::createAll() {
	T* t = new T();
	GameObject* g = static_cast<GameObject*>(t);

	if (g->getDTID() == 0) {
		// for each cube in file ie : Game object with same DTID
		//TEMP CODE
		for (int i = 0; i < 100; ++i) {
			GameObject* newIstance = m_pLevelSystem->addGameObject<T>();
			//for each component of instance
			int id[4] = { 0,1,2,3 };
			for (int j = 0; j < 4; ++j) {
				if (id[j] == ComponentType<Transform>::id) {
					Transform& trans = newIstance->addComponent<Transform>();
					trans.position = math::Vec3f(0, i*15.f, 0);
					trans.scale = math::Vec3f(10, 10, 10);
					//set serialized variables of trans
				}
				if (id[j] == ComponentType<RigidBody>::id) {
					RigidBody& rb = newIstance->addComponent<RigidBody>();
					rb.mass = 1.f;
				}
				if (id[j] == ComponentType<Model>::id) {
					Model& model = newIstance->addComponent<Model>();
					model.albedo.r = 0.f;
					model.albedo.g = 1.f;
					model.albedo.b = 0.f;
				}
				if (id[j] == ComponentType<BoxCollider>::id) {
					BoxCollider& boxCollider = newIstance->addComponent<BoxCollider>();
					boxCollider.width = 10;
					boxCollider.height = 10;
					boxCollider.depth = 10;
					boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
				}
			}
		}
	}
	if (g->getDTID() == 1) {
		// for each floor in file ie : Game object with same DTID
		//TEMP CODE
		for (int i = 0; i < 1; ++i) {
			GameObject* newIstance = m_pLevelSystem->addGameObject<T>();
			//for each component of instance
			int id[4] = { 0,1,2 };
			for (int j = 0; j < 4; ++j) {
				if (id[j] == ComponentType<Transform>::id) {
					Transform& trans = newIstance->addComponent<Transform>();
					trans.position = math::Vec3f(0, -200, 0);
					trans.scale = math::Vec3f(10, 10, 10);
					//set serialized variables of trans
				}
				if (id[j] == ComponentType<RigidBody>::id) {
					RigidBody& rb = newIstance->addComponent<RigidBody>();
					rb.mass = 1.f;
					rb.isKinematic = true;
				}
				if (id[j] == ComponentType<Model>::id) {
					Model& model = newIstance->addComponent<Model>();
					model.albedo.r = 0.f;
					model.albedo.g = 1.f;
					model.albedo.b = 0.f;
				}
				if (id[j] == ComponentType<BoxCollider>::id) {
					BoxCollider& boxCollider = newIstance->addComponent<BoxCollider>();
					boxCollider.width = 3000;
					boxCollider.height = 100;
					boxCollider.depth = 3000;
					boxCollider.material = PhysicsMaterial{ 0.5f, 0.5f, 0.5f };
				}
			}
		}
	}
	delete t;
}
}
}