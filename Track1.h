// The "easy track" inheriting from the abstract track

#ifndef TRACK1_H
#define TRACK1_H

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
