#include <vector>

#include <Video/VideoSystem.hpp>

#include <Video/Graphics/OBJLoader.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/RHI/OpenGL/GLTexture.hpp>
#include <Video/Graphics/Camera.hpp>
#include <Math/Vec2.hpp>

using namespace drak::math;
using namespace drak::video;
using namespace drak::video::geom;

void testRun(ARenderWindow* pWin) {
	OBJLoader loader;

	Mesh mesh;
	loader.load("Models/cube.obj", mesh);

	const std::vector<Vertex>& verts = mesh.vertices();
	const std::vector<U16>& indices = mesh.indices();

	gl::GLVertexBuffer vbo;
	vbo.create(verts.data(), (U32)verts.size());

	gl::GLIndexBuffer ibo;
	ibo.create(indices.data(), (I32)indices.size());

	gl::GLVertexArray vao;
	vao.create(vbo, ibo);

	gl::GLTexture tex;
	tex.loadFromFile("Textures/error.bmp");

	Camera c;
	c.view({ 0.f, 0.f, -10.f }, { 0.f, 0.f, 0.f }, { 0.f, 1.f, 0.f });
	c.perspective(60.f, 16.f / 9.f, 0.1f, 1000.f);

	Mat4f mvp = c.viewPerspective() *
		Translate<F32>({0.f, 0.f, 15.f}) *
		Rotation({45.f, 45.f, 0.f}) *
		Scale<F32>({ 15.f, 15.f, 15.f });

	gl::GLRHI::s_defaultShader.use();
	gl::GLRHI::s_defaultShader.setUniform("MVP", mvp);

	tex.use();
	
	while (pWin->IsOpen()) {
		pWin->PollEvents();
		pWin->Clear();

		vao.draw();

		pWin->SwapBuffers();
	}
	pWin->Close();
}

int main() {
	WindowSettings	ws = {"DrakVideoTest", 1600, 900};
	VideoSettings	settings = {ws};

	bool okVideo = VideoSystem::Startup(settings);

	if (okVideo)
		testRun(VideoSystem::MainWindow());

	VideoSystem::Shutdown();

	system("pause");
	return okVideo;
}