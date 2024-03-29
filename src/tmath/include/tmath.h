#pragma once

namespace PingPong {
    template<typename T>
    inline T clamp(T value, T min, T max) {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }
}
