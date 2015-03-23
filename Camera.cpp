#include <GL/glut.h>
#include "Camera.h"

Camera::Camera():eyeX(5),eyeY(10),eyeZ(5),centerX(0),centerY(0),centerZ(0){}

Camera::Camera( float eX, float eY, float eZ, float cX, float cY, float cZ ):eyeX(eX),eyeY(eY),eyeZ(eZ),centerX(cX),centerY(cY),centerZ(cZ){}

void Camera::updateLookAt(){
	gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0, 1, 0 );
}
