// .h file to control the camera

#ifndef CAMERA_H
#define CAMERA_H

#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <cmath>

class Camera{
public:
	// default constructor
	Camera();
	// non-default constructor
	Camera(float,float,float,float,float,float);
	// update the camera (for in draw)
	void updateLookAt();
	// set camera based on kart location and angle
	void KartLocation(float,float,float,float);
private:
	// the locations of the camera look at and look from
	float eyeX, eyeY, eyeZ, centerX, centerY, centerZ;
	// distance x,z away from the look at to look from
	float radius;
};

#endif
