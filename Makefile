OBJS = main.o Camera.o Track1.o Track2.o Kart.o objloader.o
CC = g++
INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include 
LIBRARY_PATHS = -L/usr/local/lib -I/opt/X11/lib
COMPILER_FLAGS = -w
LINKER_FLAGS = -lGL -lGLU -lglut -lSDL -lSDL_mixer
OBJ_NAME = main
all: $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
main.o: main.cpp
	$(CC) main.cpp -c
Camera.o: Camera.cpp
	$(CC) Camera.cpp -c
Track1.o: Track1.cpp
	$(CC) Track1.cpp -c
Track2.o: Track2.cpp
	$(CC) Track2.cpp -c
Kart.o: Kart.cpp
	$(CC) Kart.cpp -c -Wno-write-strings
objloader.o:
	$(CC) objloader.cpp -c
clean:
	rm *.o $(OBJ_NAME)
