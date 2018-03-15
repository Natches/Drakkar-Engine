#pragma once

#include <map>
#include <string>
#include <ResourceManager/ResourceManager.hpp>

namespace drak {
namespace io {
/*!
* \class MeshManager
* \ingroup IO
* \brief Class that hold all mesh already loaded, and a FBX/OBJ parser
*/

/*
class OBJParser;
class FBXParser;*/

class MeshManager {
	friend ResourceManager;

public:
	~MeshManager() = default;

	void* getMesh(const std::string& str);
	void loadMesh(const std::string& str);
	static MeshManager Create();
private:
	MeshManager() = default;

private:
	std::map<std::string, void*> m_mesh;
	/*OBJParser& m_objParser;
	FBXParser& m_fbxParser;*/
};
} // namespace io
} // namespace drak