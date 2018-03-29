#include <vector>

#include <Video/VideoSystem.hpp>
#include <Video/Graphics/OBJLoader.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/RHI/OpenGL/GLTexture.hpp>
#include <Video/Graphics/Camera.hpp>

#include <Video/Graphics/Geometry/Vertex.hpp>
#include <Windowing/Window/AWindow.hpp>
#include <Windowing/Input/Keyboard.hpp>

#include <Math/Vec2.hpp>

using namespace drak::video;
using namespace drak::math;
using namespace drak::geom;
using namespace drak::events;

//Camera c;
void cameraControl(const Event* pEvt) {
	auto k = static_cast<const KeyEvent*>(pEvt);
	//DK_SELECT(k->key)
	//	DK_CASE(Key::KEY_Q, c.move({ 0.f, -1.f, 0.f }))
	//	DK_CASE(Key::KEY_E, c.move({ 0.f, 1.f, 0.f }))
	//DK_END
}

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
	Keyboard::Get().addEventListener(Keyboard::KEY_PRESSED, cameraControl);

	Camera c;
	c.view({ 0.f, 10.f, -10.f }, { 0.f, 0.f, 0.f }, { 0.f, 1.f, 0.f });
	c.perspective(60.f, 16.f / 9.f, 0.1f, 1000.f);

	Mat4f mvp = c.viewPerspective() * Scale<F32>({ 256.f, 1.f, 256.f });
	#pragma endregion

	gl::GLRHI::s_gridShader.use();
	gl::GLRHI::s_gridShader.setUniform("MVP", mvp);
	gl::GLRHI::s_gridShader.setUniform("resolution", Vec2f{ 256.f, 256.f});
	
	while (pWin->isOpen()) {
		//mvp = c.viewPerspective() * Scale<F32>({ 256.f, 1.f, 256.f });
		//gl::GLRHI::s_gridShader.setUniform("MVP", mvp);

		pWin->pollEvents();
		pWin->clear();

		vao.draw();

		pWin->swapBuffers();
	}
	pWin->close();
}


int main() {
	WindowSettings	ws = {"DrakVideoTest", 1600, 900};
	VideoSettings	settings = {ws};
	VideoSystem		video;

	bool okVideo = video.startup(settings);

	if (okVideo)
		testRun(VideoSystem::MainWindow());

	video.shutdown();

	system("pause");
	return okVideo;
}