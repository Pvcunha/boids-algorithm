#include "boid.h"

boid::boid(Vector2 pos, Vector2 vel, Vector2 acc, double radius) {
    this->pos = pos;
    this->vel = vel;
    this->acc = acc;
    this->radius = radius;
}

void boid::check_bounds(int width, int height) {
    if(pos.x > width)
        pos.x = 0;
    else if(pos.x < 0)
        pos.x = width;
    

    if(pos.y < 0)
        pos.y = height;
    else if(pos.y > height)
        pos.y = 0;
}

void boid::alignment(std::vector<boid> &boids) {
    float radius = 20.0;
    Vector2 avg = {0,0};
    int cont = 0;

    for(boid &b : boids) {
        double d = dist(this->pos, b.pos);
        if(d > 0 && d < radius) {
            avg = avg + b.vel;
            cont++;
        }
    }

    if(cont > 0) {
        Vector2 steer;
        steer = avg / cont;
        setMag(steer, MAX_SPEED);
        steer = steer - this->vel;
        limit(steer, MAX_FORCE);
        this->acc = steer;
    }

    
}

void boid::update(std::vector<boid> boids) {
    pos = pos + vel;
    alignment(boids);
    vel = vel + acc;
}