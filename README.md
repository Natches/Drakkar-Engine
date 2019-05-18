# Drakkar-Engine
## Rules:
- Group : 3 people 
- Duration : 3 months
- Language : C++
- Framework : Scrum 

## Purpose:
This is our end of second year project at Isart Digital Montréal. The goal was to make à 3D Game Engine from scratch in C++ using whether PhysX or Bullet for the physics and whether OpenGL or DirectX for the graphic API. We chose to use PhysX and OpenGL in this project. This project was also used to conclude our two years of low-level programming and to validate our Game Engine Programming Diploma.

## What have I done:
- SIMD Accelerated 3D Math Library, with it you have access to Quaternion, Matrix4x4, Vector 2D/3D/4D/8D, everything in this library use SIMD instruction(SSE/AVX) if available and useful(there is no use of them in Vector 3D and 2D), this permit us to achieve very fast computation.
- Reflection in C++, there is a partial reflection implemented in this project using Meta-programming.
- Serialization, I use reflection to serialize easily class/struct, it support nested class / pointer / some std container serialization. It can output file in binary, Json, or Ini. Because Reflection and Serialization are linked, when you enable Reflection in a class, the Serialization code is outputed at the same time using Meta-programming.
- Multithreading, I implemented a Taskpool to manage efficiently access to other threads, there are a bunch of task available. There is also, a timer class used to trigger event at the end of it, it can loop.
- Asset Converter, it convert asset file (fbx, png, etc...) to a proprietary file format using Serialization, so it have only the needed information in it and it is lighter on the disk than before. It can also output file as package.
- Asset Manager, it's used to load and manage asset in memory.
- Animation, I implemented the animation in the animation branch, because of a bug in the matrices loading, it's not on the master branch. All the system is ready, there is only this bug that prevent us to merge.

# Authors:

- Simon Gleizes (@gleimon)
- Benjamin McDonald (@M3ALW0RM)
- Nathan Loeber (@Natches)
