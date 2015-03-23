// control the camera

#ifndef CAMERA_H
#define CAMERA_H

class Camera{
public:
	Camera();
	Camera(float,float,float,float,float,float);
	void updateLookAt();
private:
	float eyeX, eyeY, eyeZ, centerX, centerY, centerZ;
};

#endif
