# Boid

# Intro  
This project is for leaning purpose only.

# What is?  

Boid is an program, developed by Craig Reynolds, to simulate the flocking behavior of birds. The simulation has to obey 3 rules:  
- Separation: steer to avoid crowding local flockmates.  
- Alignment: steer towards the avarage heading of local flockmates.  
- Cohesion: steer to move towards the average position of the local flockmates.  

# Compile  
To compile this program you will need the gcc and raylib installed. after that clone the repo and do the following steps:  
```
    $mkdir build && cd build
    $cmake ..
    $make
    $./bin/boid
```

# References  

 - [Wikipedia](https://en.wikipedia.org/wiki/Boids)    
 - [Craig Reynolds](http://www.red3d.com/cwr/)    
 - [Ben eater](https://eater.net/boids)
 - [Nature of code](https://natureofcode.com/book/chapter-1-vectors/)