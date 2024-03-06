#include "WindowsWindow.h"

namespace Kyuubi {
	WindowsWindow::WindowsWindow(const WindowProps& props) {
		KYEngine("Creating WindowsWindow");
		SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");

		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		SDL_DestroyWindow(window);
	}

	void WindowsWindow::OnUpdate() {

	}

	uint32_t WindowsWindow::GetWidth() const {
		return windowProperties.Width;
	}

	uint32_t WindowsWindow::GetHeight() const {
		return windowProperties.Height;
	}

	void WindowsWindow::SetVSync(bool enabled) {

	}

	void WindowsWindow::IsVsync() const {

	}

	void WindowsWindow::Init(const WindowProps& props) {
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			KYEngine(stderr << "SDL failed to initialise %s\n" << SDL_GetError());
			return;
		}

		window = SDL_CreateWindow(props.Title.c_str(),
			SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED,
			props.Width, 
			props.Height,
			0);

		if (window == nullptr) {
			KYEngine("Failed to create SDL window!");
			return;
		}
	}
}