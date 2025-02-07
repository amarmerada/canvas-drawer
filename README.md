# canvas-drawer

Implements a simple drawing api

![poly](https://user-images.githubusercontent.com/67133103/221652947-cfd613ad-9022-4681-830e-bacea16bee2d.png)
![moons2](https://user-images.githubusercontent.com/67133103/221652984-31a58441-6265-4a8f-9df3-e10a86004448.png)


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

 circles, crescent, semicircle, stars, polygons

## Results
