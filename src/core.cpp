#include "raylib.h"

Vector2 operator+(const Vector2& a, const Vector2& b) {
    Vector2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

Vector2 operator*(const Vector2& a, const Vector2& b) {
    Vector2 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    return r;
}
