OBJS = main.o Camera.o Track.o Kart.o objloader.o
CC = g++
INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include
LIBRARY_PATHS = -L/usr/local/lib -I/opt/X11/lib
COMPILER_FLAGS = -w
LINKER_FLAGS = -lGL -lGLU -lglut
OBJ_NAME = main
all: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
main.o: main.cpp
	$(CC) main.cpp -c
Camera.o: Camera.cpp
	$(CC) Camera.cpp -c
Track.o: Track.cpp
	$(CC) Track.cpp -c
Kart.o: Kart.cpp
	$(CC) Kart.cpp -c
objloader.o:
	$(CC) objloader.cpp -c
clean:
	rm *.o $(OBJ_NAME)
