hello world, how to compile

install glfw, gl
then download glad, make sure you select opengl 3.3 or newer
extract glad.zip, generate static lib using

make object: `clang -c glad.c`.

generate library:`ar rcs libglad.a glad.o`

place generated glad.a to /lib, and glad/glad.h to /usr/include

installing glfw: `sudo pacman -Sy glfw`