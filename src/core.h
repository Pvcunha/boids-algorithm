#ifndef CORE_H
#define CORE_H

#include "raylib.h"
#include <vector>

Vector2 operator+(const Vector2& a, const Vector2& b);

Vector2 operator-(const Vector2& a, const Vector2& b);

Vector2 operator*(const Vector2& a, const double& escalar);

Vector2 operator/(const Vector2& a, const double& escalar);

double mag(Vector2 &a);

double dist(Vector2 a, Vector2 b);

void normalize(Vector2 &a);

void limit(Vector2 &a, double max);

#endif