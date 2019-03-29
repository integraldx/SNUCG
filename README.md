# SNUCG
This is repository for managing 2019s Computer Graphics Homeworks.  
This repository uses OpenGL, GLU, GLUT. And tested on Ubuntu 18.04, with X-window.  

## How to compile & Run
$ make run

## How to use
- w, a, s, d to move camera
- i, k to move camera vertically
- q, e, to rotate camera horizontally
- x to exit

## What I did
### HW#1
- Implementation of hierarchical 3d model and animation.
  - With the use of shared_ptr in c++, each Object(Model) has sub-tree structure.
  - Draw call acts as stack-based dfs, iterating through vector of childs.
  - Animation control is handled by SceneManager, holding shared_ptr of target Object.
- Implementation of simple camera movement
  - Each draw call uses current state of Camera object. So by modifying it in keyboardCallback, camera movement was easily implemented.
