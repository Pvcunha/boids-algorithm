#ifndef CORE_H
#define CORE_H

#include "raylib.h"
#include <vector>

const double MAX_SPEED = 4.0;
const double MAX_FORCE = 0.3;

Vector2 operator+(const Vector2& a, const Vector2& b);

Vector2 operator-(const Vector2& a, const Vector2& b);

Vector2 operator*(const Vector2& a, const double& escalar);

Vector2 operator/(const Vector2& a, const double& escalar);

double mag(Vector2 &a);

double dist(Vector2 a, Vector2 b);

void normalize(Vector2 &a);

void limit(Vector2 &a, double max);

void setMag(Vector2 &a, double val);


#endif