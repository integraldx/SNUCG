# SNUCG
This is repository for managing 2019s Computer Graphics Homeworks.  
This repository uses OpenGL, GLU, GLUT. And tested on Arch Linux, with GNOME.

## How to compile & Run
$ make run  
// Automatically feeds iceCream.txt into program

## How to use
- W, A, S, D to move camera
- Left click and drag to rotate camera view (FPS style)
- 'X' to exit

## What I did in HW#4
### Shading opaque and translucent surfaces
- Enabled Z-buffering in opengl library to correctly render intersected objects
- Enabled Blend function to render translucent surfaces.
- Disabled backface culling to see 3-dimensional translucent object
- Enabled Material on polygonal swept surface to shade it.
- Enabled Lighting and smooth shading

### Material
- From initial view, from left, number spheres 1 to 6.
#### Sphere 1
- Targeted black rubber 
  - Diffuse = (0.05, 0.05, 0.05, 1)
  - Ambient = (0.01, 0.01, 0.01, 1)
  - Specular = (0.2, 0.2, 0.2, 1)
  - Shininess = 10

#### Sphere 2
- Targeted green emerald
  - Diffuse = (0.4, 0.8, 0.4, 0.7)
  - Specular = (0.2, 0.4, 0.2, 1)
  - Shininess = 76
  - Emission = (0.1, 0.2, 0.1)

#### Sphere 3
- Targeted red rubber - red cloth
  - Diffuse = (0.4, 0.2, 0.2, 1)
  - Specular = (0.1, 0.1, 0.1, 1)
  - Shininess = 10

#### Sphere 4
- Targeted darkish metal
  - Diffuse = (0.2, 0.2, 0.2, 1)
  - Specular = (0.8, 0.8, 0.8, 1)
  - Shininess = 12

#### Sphere 5
- Targeted Opal - Pearl
  - Diffuse = (0.8, 0.6, 0.6, 1)
  - Ambient = (0.1, 0.1, 0.1, 1)
  - Specular = (0.2, 0.2, 0.2, 0.2)
  - Shininess = 30

#### Sphere 6
- Targeted blue plastic
  - Diffuse = (0.3, 0.3, 0.6, 1)
  - Specular = (0.5, 0.5, 0.5, 1)
  - Shininess = 50

### Depth Ordering
- Used std::sort to sort models and faces to be rendered in order
    - For Model, used distance with the viewer(camera) to evaluate depth
    - For Face(in translucent cubes), averaged three vertices and used dot product with view direction to evaluate depth
- When objects are visually intersecting, current depth ordering worked pretty well.
- When objects are phisically intersecting, couldn't render both intersected surfaces. But just one, which is more closer, was correctly rendering.

### Lighting
- I used three lights, light red, light green, light blue.
  - Red light position = (25, 50, 50)
  - Red light lightcolor = (1, 0.8, 0.8)
  - Red light specular = (1, 0.9, 0.9)
  - Green light position = (-40, 40, 0)
  - Green light lightcolor = (0.8, 1, 0.8)
  - Green light specular = (0.9, 1, 0.8)
  - Blue light position = (20, 40, -40)
  - Blue light lightcolor = (0.8, 0.8, 1)
  - Blue light specular = (0.9, 0.9, 1)
- Marked each light position with spheres having corresponding emission value