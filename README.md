#CUB3D

## Intro

I tried to build a functionning version to have a better understanding of how the raycasting thing is working.

...and I managed to build something that works thanks to an awesome tutorial (linked below).

The raycasting part is based on this awesome tutorial :

- [RayCasting Tutorial](https://github.com/vinibiavatti1/RayCastingTutorial/wiki/RayCasting)
	- This tutorial contains everything we need, from simple ray casting to 3D representation, texture rendering, and all of that good stuff.
	- This tutorial is written for `JavaScript` so functions are not the same and all but you get a good grip of what you have to do and how in order to achieve what we want.


And also based on these sources :

- [AmyPlant's Cub3D](https://github.com/iciamyplant/Cub3d-Linux)
	- Her README gives a lot of information on how to do some things and some great reminders.

- [griffpatch - Scrath Raycasting tutorial](https://youtube.com/playlist?list=PLy4zsTUHwGJKolO9Ko_j6IStFIJnTYBul)
	- This one is to better understand principles, it's way harder to do everything he does in C but the principles stay the same. It gives a visual reprensentation and a quick and understandable way of implementing ray casting.

- [Lodev's raycasting](https://lodev.org/cgtutor/raycasting.html)

## Compiling

```sh
make
```

## Running

```sh
./cub3d maps/map.cub
```

## Controls

- `W` or `UP` to go forward.
- `S` or `DOWN` to go backward.
- `A` or `LEFT` to rotate counter clockwise.
- `D` or `RIGHT` to rotate clockwise.
- `M` toggles the minimap.
