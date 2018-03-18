#include <vector>

#include <Video/VideoSystem.hpp>
#include <Video/Graphics/RHI/OpenGL/GLRHI.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertex.hpp>
#include <Video/Graphics/RHI/OpenGL/GLVertexArray.hpp>

using namespace drak::video;

void testRun(ARenderWindow* pWin) {
	std::vector<gl::GLVertex> quadVerts = {
		{{-0.28f, -0.5f, 0.f}, {0.f, 0.f, 1.f}, {0.f, 0.f}},
		{{ 0.28f, -0.5f, 0.f}, {0.f, 0.f, 1.f}, {1.f, 0.f}},
		{{ 0.28f,  0.5f, 0.f}, {0.f, 0.f, 1.f}, {1.f, 1.f}},
		{{-0.28f,  0.5f, 0.f}, {0.f, 0.f, 1.f}, {0.f, 1.f}},
	};

	U16 quadElems[] = {0, 1, 2, 0, 2, 3};
	
	gl::GLVertexBuffer vbo;
	vbo.create(quadVerts.data(), (U32)quadVerts.size() * sizeof(gl::GLVertex));

	gl::GLIndexBuffer ibo;
	ibo.create(quadElems, 6);

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