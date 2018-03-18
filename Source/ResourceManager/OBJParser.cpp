#include <fstream>
#include <sstream>

#include <ResourceManager/OBJParser.hpp>

using namespace drak::math;

namespace drak {
namespace io {

const char*	OBJ_PARSE_VEC2F	= "%f %f\n";
const char*	OBJ_PARSE_VEC3F	= "%f %f %f\n";
const char*	OBJ_PARSE_TRI	= "%u/%u/%u %u/%u/%u %u/%u/%u\n";

bool ParseOBJ(const std::string& objFilePath, MeshData& meshData, std::string& texturePath) {
	Vec3f				v3f;	
	Vec2f				v2f;

	std::vector<Vec2f>	uvs;
	std::vector<Vec3f>	positions, normals;

	VertexLookupTable	vertexLookup; // map a set of indexed vertex attribs to a unique vertex ID
	U16	indexCount = 0u;

	std::ifstream objFile(objFilePath);
	if (!objFile.is_open())
		return false;

	std::string	word, line, mtlFilePath;
	while (!objFile.eof()) {
		objFile >> word;
		if (word == "mtllib") {
			objFile >> mtlFilePath;
		}
		else if (word == "v") {
			std::getline(objFile, line);
			sscanf_s(line.c_str(), OBJ_PARSE_VEC3F, &v3f.x, &v3f.y, &v3f.z);
			positions.push_back(v3f); 
		}
		else if (word == "vn") {
			std::getline(objFile, line);
			sscanf_s(line.c_str(), OBJ_PARSE_VEC3F, &v3f.x, &v3f.y, &v3f.z);
			normals.push_back(v3f);
		}
		else if (word == "vt") {
			std::getline(objFile, line);
			sscanf_s(line.c_str(), OBJ_PARSE_VEC2F, &v2f.x, &v2f.y);
			uvs.push_back(v2f);
		}
		else if (word == "f") { // assume that the face is a triangle 
			IndexedVertex iv[3];
			std::getline(objFile, line);
			sscanf_s(line.c_str(), OBJ_PARSE_TRI,
				&iv[0].pos, &iv[0].uv, &iv[0].normal,
				&iv[1].pos, &iv[1].uv, &iv[1].normal,
				&iv[2].pos, &iv[2].uv, &iv[2].normal);

			for (int i = 0; i < 3; ++i) {
				if (vertexLookup.end() == vertexLookup.find(iv[i])) {
					meshData.AddPosition(positions[iv[i].pos - 1]);
					meshData.AddUV(uvs[iv[i].uv - 1]);
					meshData.AddNormal(normals[iv[i].normal - 1]);
					vertexLookup[iv[i]] = indexCount++;
				}
				meshData.indices.push_back(vertexLookup[iv[i]]);
			}
		}
	}
	objFile.close();
	return true;
}

const char*	ERROR_OPEN = "Error: Input file could not be opened.";
const char*	ERROR_PARSE = "Error: Input file could not be parsed.";

} // namespace io
} // namespace drak