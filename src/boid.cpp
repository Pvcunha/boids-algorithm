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

Vector2 boid::alignment(std::vector<boid> &boids) {
    float radius = 50.0;
    Vector2 avg = {0,0};
    int cont = 0;

    for(boid &b : boids) {
        double d = dist(this->pos, b.pos);
        if(d > 0 && d < radius) {
            avg = avg + b.vel;
            cont++;
        }
    }

    Vector2 steer = {0.0, 0.0};
    if(cont > 0) {
        steer = avg / cont;
        setMag(steer, MAX_SPEED);
        steer = steer - this->vel;
        limit(steer, MAX_FORCE);
    }
    return steer;
}

Vector2 boid::cohesion(std::vector<boid> &boids) {
    float radius = 50.0;
    Vector2 avg = {0,0};
    int cont = 0;

    for(boid &b : boids) {
        double d = dist(this->pos, b.pos);
        if(d > 0 && d < radius) {
            avg = avg + b.pos;
            cont++;
        }
    }

    Vector2 steer = {0.0, 0.0};
    if(cont > 0) {
       
        steer = avg / cont;
        steer = steer - this->pos;
        setMag(steer, MAX_SPEED);
        steer = steer - this->vel;
        limit(steer, MAX_FORCE);
        
    }

    return steer;
}

Vector2 boid::separation(std::vector<boid> &boids) {
    float radius = 50.0;
    Vector2 avg = {0,0};
    int cont = 0;

    for(boid &b : boids) {
        double d = dist(this->pos, b.pos);
        if(d > 0 && d < radius ) {
            Vector2 diff = this->pos - b.pos; 
            diff = diff / d;
            avg = avg + diff;
            cont++;
        }
    }

    Vector2 steer = {0.0, 0.0};
    if(cont > 0) {
        steer = avg / cont;
        setMag(steer, MAX_SPEED);
        steer = steer - this->vel;
        limit(steer, MAX_FORCE);
        
    }

    return steer;    
}


void boid::update(std::vector<boid> boids) {
    Vector2 align_rule = alignment(boids);
    Vector2 cohesion_rule = cohesion(boids);
    Vector2 separation_rule = separation(boids);
    acc = separation_rule + align_rule + cohesion_rule;
    vel = vel + acc;
    pos = pos + vel;
    limit(vel, MAX_SPEED);
    acc = acc * 0;
}