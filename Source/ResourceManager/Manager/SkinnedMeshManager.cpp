#include <PrecompiledHeader/pch.hpp>
#include <ResourceManager/Manager/SkinnedMeshManager.hpp>
#include <Converter/ResourceDefinitions.hpp>
#include <Animation/Skeleton/Skeleton.hpp>

namespace drak {

using namespace definition;

void SkinnedMeshManager::preload(const std::string& names, const std::string& filename) {
	Base::preload(names, filename);
}

void SkinnedMeshManager::preload(const ResourceName& rName, const std::string& filename) {
	for (auto& name : rName.names) {
		if ((name.second & EFileType::SKINNEDMESH) == EFileType::SKINNEDMESH && name.first.c_str() != "")
			m_map[name.first] = SkinnedMeshPtr(new Resource<geom::SkinnedMesh>(filename));
	}
}

void SkinnedMeshManager::load(const std::string& filename, std::vector<SkinnedMesh>& inSkinnedMeshes) {
	for (auto& skMesh : inSkinnedMeshes) {
		if (skMesh.name.c_str() != "") {
			if (!m_map[skMesh.name].get())
				m_map[skMesh.name].reset(new Resource<geom::SkinnedMesh>(filename));
			animation::Skeleton skeleton;
			skeleton.m_handleList = skMesh.skeleton.handles;
			skeleton.m_boneList.resize(skMesh.skeleton.bones.size());
			U32 i = 0;
			for (auto& bone : skMesh.skeleton.bones) {
				skeleton.m_boneList[i].joint.pos = bone.joint.pos;
				skeleton.m_boneList[i].joint.rot = bone.joint.rot;
				if (bone.joint.rot.quat.isNull())
					bone.joint.rot.m_scalar = 1.f;
				skeleton.m_boneList[i].offsetMatrix = bone.offsetMatrix;
				skeleton.m_boneList[i].name = bone.name;
				for (auto& bone2 : bone.children) {
					U32 idx = skeleton.m_handleList[bone2];
					skeleton.m_boneList[idx].joint.pos = skMesh.skeleton.bones[idx].joint.pos;
					skeleton.m_boneList[idx].joint.rot = skMesh.skeleton.bones[idx].joint.rot;
					if (skeleton.m_boneList[idx].joint.rot.quat.isNull())
						skeleton.m_boneList[idx].joint.rot.m_scalar = 1.f;
					skeleton.m_boneList[idx].offsetMatrix = skMesh.skeleton.bones[idx].offsetMatrix;
					skeleton.m_boneList[idx].name = bone2;
					skeleton.m_boneList[i].children.emplace_back(skeleton.m_boneList[idx]);
				}
				++i;
			}
			for (auto& animation : skMesh.skeleton.animations) {
				animation::Animation anim;
				anim.m_name = animation.second.name;
				anim.m_animationDuration = animation.second.animationDuration;
				anim.m_tickPerSecond = animation.second.tickPerSecond;
				U32 i = 0;
				anim.m_frames.resize(animation.second.frames.size());
				for (auto& frame : animation.second.frames) {
					for (auto& joint : frame.joints) {
						anim.m_frames[i].m_jointList[joint.first].pos = joint.second.pos;
						anim.m_frames[i].m_jointList[joint.first].rot = joint.second.rot;
						if (anim.m_frames[i].m_jointList[joint.first].rot.quat.isNull())
							anim.m_frames[i].m_jointList[joint.first].rot.m_scalar = 1.f;
					}
					++i;
				}
				skeleton.m_animList.insert({ animation.first, anim });
			}
			skeleton.m_invGlobalPos = skMesh.skeleton.invGlobalPos;
			new (m_map[skMesh.name].get())
				Resource<geom::SkinnedMesh>(filename, geom::SkinnedMesh(skMesh.name,
					std::move(*reinterpret_cast<std::vector<geom::Vertex1P1N1UV1B1W>*>(&skMesh.vertices)),
					std::move(skMesh.indices),
					std::move(skeleton)));

			m_map[skMesh.name]->loadState(Resource<geom::SkinnedMesh>::ELoadState::READY);
		}
	}
}

void SkinnedMeshManager::reload(std::vector<SkinnedMesh>& inSkinnedMeshes) {
	for (auto& skMesh : inSkinnedMeshes) {
		m_map[skMesh.name]->loadState(Resource<geom::SkinnedMesh>::ELoadState::LOADING);
		new (&m_map[skMesh.name]->m_resource)
			geom::SkinnedMesh(skMesh.name,
				std::move(*reinterpret_cast<std::vector<geom::Vertex1P1N1UV1B1W>*>(&skMesh.vertices)),
				std::move(skMesh.indices),
				std::move(*reinterpret_cast<animation::Skeleton*>(&skMesh.skeleton)));
		m_map[skMesh.name]->loadState(Resource<geom::SkinnedMesh>::ELoadState::READY);
	}
}

}