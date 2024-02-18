#pragma once
#include <cstdint>

namespace Kyuubi {

    class Color {
    public:
        Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
            : r(red), g(green), b(blue), a(alpha) {}

        uint8_t r, g, b, a; // RGBA color values
    };
}