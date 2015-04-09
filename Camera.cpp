#include "Camera.h"

Camera::Camera(){
	eyeX = 0;
	eyeY = 10;
	eyeZ = -20;
	centerX = 0;
	centerY = 0;
	centerZ = 0;
	angle = 0;
	radius = 5;
}

Camera::Camera( float eX, float eY, float eZ, float cX, float cY, float cZ ){
	eyeX = eX;
	eyeY = eY;
	eyeZ = eZ;
	centerX = cX;
	centerY = cY;
	centerZ = cZ;
	if( eX == 0 && eZ > 0 )
		angle = 90;
	else if( eX == 0 && eZ < 0 )
		angle = 270;
	else if( eZ == 0 )
		angle = 0;
	else
		angle = atan( eZ / eX ) / M_PI * 180;
	radius = sqrt( eX*eX + eZ*eZ );
}

void Camera::updateLookAt(){
	gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0, 1, 0 );
}

void Camera::KartLocation( float x, float y, float z ){
	centerX = x;
	centerY = y;
	centerZ = z;
	eyeY = y+5;
	eyeZ = z-10;
	eyeX = x;
}

void Camera::setAngle( float n ){
	angle = n;
	while( angle >= 360 )
		angle -= 360;
	while( angle < 0 )
		angle += 360;
	eyeX = radius * cos( angle / 180 * M_PI );
	eyeZ = radius * sin( angle / 180 * M_PI );
}

void Camera::rotateCCW( float degrees ){
	setAngle( angle - degrees );
}

void Camera::rotateCW( float degrees){
	setAngle( angle + degrees );
}

void Camera::moveForward( float units ){
	centerZ += units;
	eyeZ += units;
}
