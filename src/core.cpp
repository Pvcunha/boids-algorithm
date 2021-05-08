#include "core.h"
#include <iostream>
#include <math.h>

Vector2 operator+(const Vector2& a, const Vector2& b) {
    Vector2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

Vector2 operator-(const Vector2& a, const Vector2& b) {
    Vector2 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

Vector2 operator*(const Vector2& a, const double& scalar) {
    Vector2 r;
    r.x = a.x * scalar;
    r.y = a.y * scalar;
    return r;
}

Vector2 operator/(const Vector2& a, const double& scalar) {
    Vector2 r;
    r.x = a.x / scalar;
    r.y = a.y / scalar;
    return r;
}

double mag(Vector2 &a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

double dist(Vector2 a, Vector2 b) {
    return sqrt((a.x - b.x)*(a.x- b.x) + (a.y - b.y)*(a.y - b.y));
}

void normalize(Vector2 &a) {
    double m = mag(a);
    a = a / m;
}

void setMag(Vector2 &a, double val) {
    normalize(a);
    a = a * val;
}

void limit(Vector2 &a, double max) {
    double m = mag(a);
    if(m > max) {
        normalize(a);
        a = a * max;
    }
}