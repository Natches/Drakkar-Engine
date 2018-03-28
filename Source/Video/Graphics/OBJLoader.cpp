#include <fstream>
#include <sstream>
#include <map>

#include <Video/Graphics/OBJLoader.hpp>

using namespace drak::math;
using namespace drak::geom;

namespace drak {
namespace video {

//-------------------------------------------------------------------------------------------------
// Vertex Attribute Formats
const char*	OBJ_PARSE_VEC2F	= "%f %f\n";
const char*	OBJ_PARSE_VEC3F	= "%f %f %f\n";

// Face Assembly Formats
const char*	OBJ_PARSE_FACE_IND1 = "%hu %hu %hu\n";
const char*	OBJ_PARSE_FACE_IND2 = "%hu/%hu %hu/%hu %hu/%hu\n";
const char*	OBJ_PARSE_FACE_IND3 = "%hu/%hu/%hu %hu/%hu/%hu %hu/%hu/%hu\n";
//-------------------------------------------------------------------------------------------------


bool OBJLoader::load(const std::string& objPath, Mesh& outMesh) {
	std::vector<Vec2f>	uvs;
	std::vector<Vec3f>	positions, normals;

	std::map<IndexedVertex, U16, IndexComparison> vertexLookup; 
	U16	indexCount = 0u;

	std::ifstream objFile(objPath);
	if (!objFile.is_open())
		return false;

	std::string	word, line, mtlFilePath;
	while (!objFile.eof()) {
		objFile >> word;
		if (word == "mtllib") {
			objFile >> mtlFilePath;
		}
		else if (word == "v")	positions.push_back	(readVec3(objFile));
		else if (word == "vn")	normals.push_back	(readVec3(objFile));
		else if (word == "vt")	uvs.push_back		(readVec2(objFile));
		else if (word == "f") {  
			IndexedVertex iv[3];
			std::getline(objFile, line);
			sscanf_s(line.c_str(), OBJ_PARSE_FACE_IND3,
				&iv[0].pos, &iv[0].uv, &iv[0].normal,
				&iv[1].pos, &iv[1].uv, &iv[1].normal,
				&iv[2].pos, &iv[2].uv, &iv[2].normal);
			
			for (int i = 0; i < 3; ++i) {
				if (vertexLookup.find(iv[i]) == vertexLookup.end()) {
					outMesh.addVertex({
						positions	[iv[i].pos		- 1],
						normals		[iv[i].normal	- 1],
						uvs			[iv[i].uv		- 1]});
					vertexLookup[iv[i]] = indexCount++;
				}
				outMesh.addIndex(vertexLookup[iv[i]]);
			}
		}
	}
	objFile.close();
	return true;
}

Vec2f OBJLoader::readVec2(std::ifstream& fs) {
	Vec2f v2;
	std::string	line;

	std::getline(fs, line);
	sscanf_s(line.c_str(), OBJ_PARSE_VEC2F, &v2.x, &v2.y);
	return v2;
}


Vec3f OBJLoader::readVec3(std::ifstream& fs) {
	Vec3f v3;
	std::string	line;

	std::getline(fs, line);
	sscanf_s(line.c_str(), OBJ_PARSE_VEC3F, &v3.x, &v3.y, &v3.z);
	return v3;
}

} // namespace video
} // namespace drak