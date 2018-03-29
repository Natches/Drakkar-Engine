#include <vector>

#include <Video/VideoSystem.hpp>

#include <Video/Graphics/OBJLoader.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>

using namespace drak::video;
using namespace drak::video::geom;

void testRun(ARenderWindow* pWin) {
	OBJLoader loader;

	Mesh mesh;
	loader.load("cube.obj", mesh);

	const std::vector<Vertex>& verts = mesh.vertices();
	const std::vector<U16>& indices = mesh.indices();
	
	gl::GLVertexBuffer vbo;
	vbo.create(verts.data(), verts.size());

	gl::GLIndexBuffer ibo;
	ibo.create(indices.data(), indices.size());

	gl::GLVertexArray vao;
	vao.create(vbo, ibo);

	while (pWin->IsOpen()) {
		pWin->PollEvents();
		pWin->Clear();

		vao.draw();

		pWin->SwapBuffers();
	}
	pWin->Close();
}

int main() {
	WindowSettings	ws = {"DrakVideoTest", 1280, 720};
	VideoSettings	settings = {ws};

	bool okVideo = VideoSystem::Startup(settings);

	if (okVideo)
		testRun(VideoSystem::MainWindow());

	VideoSystem::Shutdown();

	system("pause");
	return okVideo;
}