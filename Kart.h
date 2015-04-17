#ifndef KART_H
#define KART_H

#include "Camera.h"
#include "Track.h"
#include <vector>
#include <GL/glut.h>


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
private:
	int mushroom;
	int choice;
	float x_pos;
	float y_pos;
	float z_pos;
	float angle;
	float speed;
	Track& myTrack;
	//bool objloader(const char*, vector < glm::vec3 >*, vector < glm::vec2 >*, vector < glm::vec3 >*);
};

#endif	
