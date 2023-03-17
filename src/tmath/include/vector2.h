#pragma once
#include "point2.h"

namespace PingPong {
    struct Vector2 {
        float x, y;

        Point2 convert_to_point();
    };
}
