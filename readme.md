# This is a base OpenGL boiler plate code that I will use for projects.
### This program will open a window, handle all shaders through the use of a shader class.
### It will also handle all buffers through the use of a buffers header file (VAO, VBO, EBO).

#

# Compilation
Compilation is handled through CMmake, but the following libraries are still required:
- glfw3
- glm
- OpenGL (typically handled through the installation of mesa on linux filesystems)

### To compile:
You can compile with these following commands.</br>
```
cmake -S . -B build && cmake --build
```
Then you can run the executable outputted from CMake.
```
./gl
```
> [!NOTE]
> CMake can be ran through Visual Studio Code or some other IDEs that have the extension installed.
