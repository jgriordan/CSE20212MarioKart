#ifndef KART_H
#define KART_H
#include "Camera.h"
#include <vector>
#include <GL/glut.h>


using namespace std;

class Kart{

public:
	Kart();
	Kart(int);
	void DrawKart();
	float getX();
	float getY();
	float getZ();
	void setX(float);
	void setY(float);
	void setZ(float);
	float getAngle();
	void setAngle(float);
	void setAcc(float);
	float getAcc();
private:
	int mushroom;
	int choice;
	float x_pos;
	float y_pos;
	float z_pos;
	float angle;
	float acc;

	//bool objloader(const char*, vector < glm::vec3 >*, vector < glm::vec2 >*, vector < glm::vec3 >*);
};

#endif	