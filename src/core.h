#ifndef CORE_H
#define CORE_H

#include "raylib.h"

Vector2 operator+(const Vector2& a, const Vector2& b);

Vector2 operator-(const Vector2& a, const Vector2& b);

Vector2 operator*(const Vector2& a, const double& escalar);

Vector2 operator/(const Vector2& a, const double& escalar);

double mag(Vector2& a);

void normalize(Vector2& a);


class ball {
    
    public:
        Vector2 pos;
        Vector2 v;
        double radius;
        
        ball(Vector2 pos, Vector2 v, double radius);
        void check_bounds(int width, int height);
        void update();
};

#endif