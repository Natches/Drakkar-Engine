#include <vector>

#include <Video/VideoSystem.hpp>
#include <Video/Graphics/Tools/OBJLoader.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTexture.hpp>
#include <Video/Graphics/Rendering/Camera.hpp>

#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Windowing/Window/AWindow.hpp>
#include <Windowing/Input/Keyboard.hpp>

#include <Math/Vec2.hpp>

using namespace drak::video;
using namespace drak::math;
using namespace drak::geom;
using namespace drak::events;
using namespace drak::gfx;

void testRun(AWindow* pWin) {

	#pragma region [TEST] Mesh Creation
	OBJLoader loader;

	Mesh mesh;
	loader.load("Models/quad.obj", mesh);

	const std::vector<Vertex>& verts = mesh.vertices();
	const std::vector<U16>& indices = mesh.indices();

	gl::GLVertexBuffer vbo;
	vbo.create(verts.data(), (U32)verts.size());

	gl::GLIndexBuffer ibo;
	ibo.create(indices.data(), (I32)indices.size());

	gl::GLVertexArray vao;
	vao.create(vbo, ibo);

	gl::GLTexture tex;
	tex.loadFromFile("Textures/grid_cell.png");
	tex.use();
	#pragma endregion

	#pragma region [TEST] Camera
	Camera c;
	drak::function::MemberFunction<Camera, void, const Event*> func(&c, &Camera::cameraControl, &Keyboard::Get().event());
	Keyboard::Get().addEventListener(Keyboard::KEY_DOWN, &func);

	c.view({ 0.f, 10.f, -10.f }, { 0.f, 0.f, 0.f }, { 0.f, 1.f, 0.f });
	c.perspective(60.f, 16.f / 9.f, 0.1f, 1000.f);

	Mat4f mvp = c.viewPerspective() * Scale<F32>({ 256.f, 1.f, 256.f });
	#pragma endregion

	//gl::GLRendering::s_gridShader.use();
	//gl::GLRendering::s_gridShader.setUniform("MVP", mvp);
	//gl::GLRendering::s_gridShader.setUniform("resolution", Vec2f{ 64.f, 64.f});
	//gl::GLRendering::s_gridShader.setUniform("tint", Vec4f{0.259f, 0.957f, 0.843f, 1.f });
	
	while (pWin->isOpen()) {
		mvp = c.viewPerspective() * Scale<F32>({ 256.f, 1.f, 256.f });
		//gl::GLRendering::s_gridShader.setUniform("MVP", mvp);

		pWin->pollEvents();
		pWin->clear();

		vao.draw();

		pWin->swapBuffers();
	}
	pWin->close();
}


int main() {
	//WindowSettings	ws = {"DrakVideoTest", 1600, 900};
	//VideoSettings	settings = {ws};
	//VideoSystem		video;

	bool okVideo = true;// = video.startup(settings);

	//if (okVideo)
	//	testRun(VideoSystem::MainWindow());

	//video.shutdown();

	system("pause");
	return okVideo;
}