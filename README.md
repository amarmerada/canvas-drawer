# canvas-drawer

Implements a simple drawing api



## How to build

*Windows*

Open git bash to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake -G "Visual Studio 16 2019" ..
canvas-drawer/build $ start Draw-2D.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
canvas-drawer/build $ ../bin/Debug/draw_test
canvas-drawer/build $ ../bin/Debug/draw_art
```

*macOS*

Open terminal to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake ..
canvas-drawer/build $ make
```

To run each program from build, you would type

```
canvas-drawer/build $ ../bin/draw_test
canvas-drawer/build $ ../bin/draw_art
```

## Supported primitives

Triangles, circles, Left and right crescent, gibbous, semicircle, and polygons

## Results

![poly](https://user-images.githubusercontent.com/67133103/221354521-77585748-8458-40c8-a3c4-4f9a9da5a27d.png)
![moons](https://user-images.githubusercontent.com/67133103/221354549-85c2d7fd-4d28-4292-8e26-60eb6a1a9c6d.png)
