// control the camera

#ifndef CAMERA_H
#define CAMERA_H

#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <cmath>

class Camera{
public:
	Camera();
	Camera(float,float,float,float,float,float);
	void updateLookAt();
	void rotateCCW(float);
	void rotateCW(float);
private:
	float eyeX, eyeY, eyeZ, centerX, centerY, centerZ;
	float angle, radius;
	void setAngle(float);
};

#endif
