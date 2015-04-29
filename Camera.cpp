// .cpp file for camera control
#include "Camera.h"

// default constructor
Camera::Camera(){
	// look from (0, 10, -20)
	eyeX = 0;
	eyeY = 10;
	eyeZ = -20;
	// look at (0, 0, 0)
	centerX = 0;
	centerY = 0;
	centerZ = 0;
	// x,y distance from look at is 20
	radius = 20;
}

Camera::Camera( float eX, float eY, float eZ, float cX, float cY, float cZ ){
	// look from choice
	eyeX = eX;
	eyeY = eY;
	eyeZ = eZ;
	// look at choice
	centerX = cX;
	centerY = cY;
	centerZ = cZ;
	// calculate distance from look at based on x and z
	radius = sqrt( eX*eX + eZ*eZ );
}

// call glut function to update camera
void Camera::updateLookAt(){
	gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0, 1, 0 );
}

// given a kart location, decide values to look at and from
void Camera::KartLocation( float x, float y, float z, float a ){
	// look at kart
	centerX = x;
	centerY = y;
	centerZ = z;
	// look from up 10, and behind the kart radius away
	eyeY = y+10;
	eyeZ = z-radius*sin(a);
	eyeX = x+radius*cos(a);
}
