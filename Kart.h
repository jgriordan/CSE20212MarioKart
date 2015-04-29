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
	Kart(int,Track*,int);//Non-default constructor instantiates the track.
	void DrawKart();
	float getX();//Return the position of the Kart
	float getY();
	float getZ();
	void setLocation(float,float,float);//Reset the Kart to the center of the track.
	float getAngle();//Determine the direction the Kart is facing.
	void setAngle(float);
	void setSpeed(float);
	float getSpeed();//Determine the speed of the Kart.
	void useShroom();//Use a mushroom. Don't do drugs.
	void setInitialTime();//Set the time of the lap start
	clock_t getInitialTime();
	double time();
	void lapFunc();
	void setLap_t(int);//Set the time for the current lap.
	double getLap_t();//Get the time for the current lap.
	void setLap_n(int = 1);//Set the lap number
	int getLap_n();//Determine the lap number
	void setChoice(int);//Set the choice of Kart
	std::string getBestTime();
	std::string getLastTime();
	int wrongWay();//Determine if the Kart is going the wrong way.
	int getShroom();
private:
	int mushroom;//Number of mushrooms available.
	int choice;//Kart Choice
	float x_pos;//Position of the Kart
	float y_pos;
	float z_pos;
	float angle;//Direction the Kart is facing.
	float speed;
	objloader car;//Objloader obj used to draw the specified Kart.
	int cube;
	Track * myTrack;//Determines what track the Kart is on.
	clock_t begin;//Begin timing signal.
	int lap_n;//lap number
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
