// abstract class used to control the track

#ifndef TRACK_H
#define TRACK_H

#include <stdlib.h>
#include <GL/glut.h>

class Track{
public:
	Track(){};
	virtual void draw() = 0;
	virtual int isOnTrack(float,float) = 0;
	virtual float toMiddleX(float,float) = 0;
	virtual float toMiddleZ(float,float) = 0;
};

#endif
