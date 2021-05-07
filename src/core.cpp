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

void normalize(Vector2 &a) {
    double m = mag(a);
    a = a / m;
}

void limit(Vector2 &a) {
    double m = mag(a);
    if(m > MAX_ACC) {
        normalize(a);
        a = a * MAX_ACC;
    }
}

ball::ball(Vector2 pos, Vector2 vel, Vector2 acc, double radius) {
    this->pos = pos;
    this->vel = {0.0, 0.0};
    this->acc = acc;
    this->radius = radius;
}

void ball::check_bounds(int width, int height) {
    if(pos.x > width)
        pos.x = 0;
    else if(pos.x < 0)
        pos.x = width;
    

    if(pos.y < 0)
        pos.y = height;
    else if(pos.y > height)
        pos.y = 0;
}

void ball::update() {
    vel = vel + acc;
    limit(vel);
    pos = pos + vel;
}