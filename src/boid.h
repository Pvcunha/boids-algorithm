#ifndef BOID_H
#define BOID_H
#include "core.h"

class boid {
    
    public:
        Vector2 pos;
        Vector2 vel;
        Vector2 acc;
        double radius;
        
        boid(Vector2 pos, Vector2 vel, Vector2 acc, double radius);

        void check_bounds(int width, int height);

        void update(std::vector<boid> boids);
        void separation(std::vector<boid> &boids);
        void alignment(std::vector<boid> &boids);
        void cohesion(std::vector<boid> &boids);
};



#endif