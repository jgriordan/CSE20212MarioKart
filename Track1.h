#ifndef TRACK1_H
#define TRACK1_H

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "Track.h"

class Track1: public Track{
public:
	Track1();
	void draw();
	int isOnTrack(float,float);
	float toMiddleX(float,float);
	float toMiddleZ(float,float);
};

#endif
