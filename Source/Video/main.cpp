#include <vector>

#include <Video/VideoSystem.hpp>

#include <Video/Graphics/OBJLoader.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/Camera.hpp>

using namespace drak::math;
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

	Camera c;
	c.lookAt({ 0.f, 0.f, -30.f }, { 0.f, 0.f, 0.f }, { 0.f, 1.f, 0.f });
	c.perspective(60.f, 16.f / 9.f, 0.1f, 100.f);

	Mat4f mvp = c.viewPerspective() * 
		Translate<F32>({5.f, 2.f, 8.f}) *
		Rotation({ 45.f, 25.f, 63.f }) *
		Scale<F32>({2.f, 6.f, 3.425f});

	gl::GLRHI::s_defaultShader.use();
	gl::GLRHI::s_defaultShader.setUniform("MVP", mvp);
	
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