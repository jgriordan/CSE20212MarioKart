#ifndef KART_H
#define KART_H

#include "Camera.h"
#include "Track.h"
#include <vector>
#include <GL/glut.h>
#include "objloader.h"


using namespace std;

class Kart{

public:
	Kart(int,Track&);
	void DrawKart();
	float getX();
	float getY();
	float getZ();
	void setLocation(float,float,float);
	float getAngle();
	void setAngle(float);
	void setSpeed(float);
	float getSpeed();
	void useShroom();
private:
	int mushroom;
	int choice;
	float x_pos;
	float y_pos;
	float z_pos;
	float angle;
	float speed;
	object_type car;
	Track& myTrack;
};

#endif	
