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
private:
	int mushroom;
	int choice;
	bool objloader(const char*, vector < glm::vec3 >*, vector < glm::vec2 >*, vector < glm::vec3 >*);
}

#endif
	
	
	
