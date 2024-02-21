#pragma once

#define SDL_MAIN_HANDLED

#include <memory>
#include "iostream"

#define KYEngine(str) do { std::cout << str << std::endl; } while(0);

namespace Kyuubi {
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}