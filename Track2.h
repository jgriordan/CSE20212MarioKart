#ifndef TRACK2_H
#define TRACK2_H

#include "Track.h"

class Track2: public Track{
public:
	Track2();
	void draw();
	int isOnTrack(float,float);
	float toMiddleX(float,float);
	float toMiddleZ(float,float);
};

#endif
