#include "core.h"
#include <iostream>

int main(void)
{

    Vector2 a = {1, 2};
    Vector2 b = {3, 4};
    Vector2 c = a + b;

    std::cout << c.x << c.y << std::endl;


    return 0;
}