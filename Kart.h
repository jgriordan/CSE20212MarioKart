#ifndef KART_H
#define KART_H

#include <GL/glut.h>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include "Camera.h"
#include "Track.h"
#include "objloader.h"

class Kart{

public:
	Kart(int,Track*,int);
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
	void setInitialTime();
	clock_t getInitialTime();
	double time();
	void lapFunc();
	void setLap_t(int);
	double getLap_t();
	void setLap_n(int = 1);
	int getLap_n();
	void setChoice(int);
	std::string getBestTime();
	std::string getLastTime();
	int wrongWay();
private:
	int mushroom;
	int choice;
	float x_pos;
	float y_pos;
	float z_pos;
	float angle;
	float speed;
	objloader car;
	int cube;
	Track * myTrack;
	clock_t begin;
	int lap_n;
	double lap;
	double bestTimeD;
	std::string bestTimeS;
	std::string lastTime;
	int hasStarted;
	int pos[4];
	int pos_2[10];
	int trackSelect;
};

#endif	
