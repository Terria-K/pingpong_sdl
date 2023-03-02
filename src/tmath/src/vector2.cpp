#include "vector2.h"

Point2 Vector2::convert_to_point() {
    Point2 point2 { (int)x, (int)y };
    return point2;
}