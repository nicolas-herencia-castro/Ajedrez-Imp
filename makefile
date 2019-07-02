# Use like this:

OS := $(shell uname)

ifeq ($(OS),Darwin)
#MacOS
all:
	cc -framework OpenGL -framework GLUT -framework Cocoa -Wno-deprecated-declarations main.o chess.o $(HW).c -o $(HW)

else
#Linux
all:
	gcc main.o chess.o $(HW).c -lglut -lGL -lGLU -w -o $(HW)

endif
