#include <vector>

#include <Video/VideoSystem.hpp>
#include <Video/RHI/OpenGL/GLRHI.hpp>
#include <Video/RHI/OpenGL/GLVertex.hpp>
#include <Video/RHI/OpenGL/GLVertexArray.hpp>
#include <Video/RHI/OpenGL/GLShader.hpp>

using namespace drak::video;

void testRun(ARenderWindow* pWin) {
#pragma region Test
	static const float points[3][3] =
	{
		{-0.25f, -0.25f, 0.f},
		{0.25f, -0.25f, 0.f},
		{0.25f, 0.5f, 0.f},
	};

	static const float colors[3][4] =
	{
		{ 1.f, 0.f, 0.f, 1.f },
		{ 0.f, 1.f, 0.f, 1.f },
		{ 0.f, 0.f, 1.f, 1.f }
	};

	std::vector<gl::GLVertex> verts = {
		gl::GLVertex(points[0], colors[0]),
		gl::GLVertex(points[1], colors[1]),
		gl::GLVertex(points[2], colors[2])
	};

	gl::GLShader fallback;
	fallback.loadFromFile("default.vs", "default.fs");
	fallback.use();

	gl::GLVertexArray mesh;
	mesh.create(verts);
#pragma endregion

	while (pWin->IsOpen()) {
		pWin->PollEvents();
		pWin->Clear();
		mesh.draw();
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