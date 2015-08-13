# TECS: Tiny Entity-Component System

Install dependencies in Ubuntu (tested on `15.04`):
```bash
$ sudo apt-get install scons libglew-dev libglm-dev libbullet-dev libglfw3-dev
```

In the project's root directory, build and run:
```bash
$ scons
scons: done building targets.
$ ./ecs
```
## Info

Uses OpenGL, Bullet Physics, GLEW, GLFW3 and GLM, along with files from Tom Dalling's [modern OpenGL tutorial](http://www.tomdalling.com/blog/category/modern-opengl/).  Entity component system with nodes based on the idea explained [here](http://www.richardlord.net/blog/what-is-an-entity-framework).

## Usage

Use the WASD keys and mouse to move/look around.  Press 'e' to fire cups, 't' to delete all cups, and 'r' to reset the cubes.  Press 'f' to enable/disable the physics system (the rendering system will continue running).

## Todo

Change GLM degrees to radians.