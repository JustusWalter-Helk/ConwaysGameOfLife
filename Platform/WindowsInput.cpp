#include "../Core/Input.h"

namespace Kyuubi {

	std::vector<bool> Input::prevKeyHeld(SDL_NUM_SCANCODES, false);
	std::vector<bool> Input::holdedKeys(SDL_NUM_SCANCODES, false);
	std::vector<bool> Input::pressedKeys(SDL_NUM_SCANCODES, false);
	std::vector<bool> Input::prevKeyPressed(SDL_NUM_SCANCODES, false);

	bool Input::disableHoldCheck = false;

	SDL_Window* Input::window;

	void Input::keyDown(SDL_Scancode keyCode) {
		if (!prevKeyHeld[keyCode]) {
			pressedKeys[keyCode] = true;
		}
		holdedKeys[keyCode] = true;
	}

	void Input::keyUp(SDL_Scancode keyCode) {
		pressedKeys[keyCode] = false;
		holdedKeys[keyCode] = false;
	}

	void Input::endFrame() {
		prevKeyHeld = holdedKeys;
		prevKeyPressed = pressedKeys;
	}

	void Input::setWindow(SDL_Window* window) {
		Input::window = window;
	}
	bool Input::isKeyHold(SDL_Scancode keyCode) {
		return holdedKeys[keyCode];
	}
	bool Input::isKeyPressed(SDL_Scancode keyCode) {
		if (disableHoldCheck) {
			return pressedKeys[keyCode];
		}
		return pressedKeys[keyCode] && !prevKeyPressed[keyCode];
	}
}