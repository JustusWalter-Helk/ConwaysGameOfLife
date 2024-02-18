#include <SDL2/SDL.h>
#include "Window.h"

#ifdef KYUUBI_PLATFORM_WINDOWS
#include "../Platform/WindowsWindow.h"
#endif

namespace Kyuubi {
	Scope<Window> Window::Create(const WindowProps& props) {
		SDL_SetMainReady();
		#ifdef KYUUBI_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
		#else
			return nullptr;
		#endif
	}
}