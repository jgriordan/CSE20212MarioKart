#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

class Track{
public:
	Track();
	void draw();
	int isOnTrack(float,float);
	float toMiddleX(float,float);
	float toMiddleZ(float,float);
};

#endif
