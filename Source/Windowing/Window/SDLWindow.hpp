#pragma once

#include <Windowing/Window/AWindow.hpp>
#include <Windowing/Input/Keyboard.hpp>

// Fwd Declarations
union SDL_Event;

namespace drak {
namespace video {

/*!
* \class SDLWindow
* \ingroup DrakVideo
* \brief Inherits AWindow; builds on an SDL_Window
*
*/
class SDLWindow final : public AWindow {
public:
	SDLWindow(const WindowSettings& settings);
	virtual ~SDLWindow();

private:
	static bool InitSDLVideo();
	static void QuitSDLVideo();

private:
	void pollEvents()	override;
	void clear()		override;
	void swapBuffers()	override;
	void close()		override;

	events::Key keyConvert(int sdlKey) const;

private:
	void*		m_glContext;
	SDL_Event*	m_pEvt;

friend bool VideoSystem::startup(const VideoSettings& settings, AWindow*& pMainWindow);
friend void VideoSystem::shutdown();
};

} // namespace video
} // namespace drak