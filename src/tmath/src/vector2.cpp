#include "vector2.h"

namespace PingPong {
    Point2 Vector2::convert_to_point() {
        Point2 point2 { (int)x, (int)y };
        return point2;
    }
}
