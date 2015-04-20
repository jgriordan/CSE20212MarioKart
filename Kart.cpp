#include "Kart.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include "objloader.h"
#include <ctime>

using namespace std;

Kart::Kart( int c, Track& track ):myTrack(track){
	if (c > 4 || c < 1){
		cout <<"Invalid choice! Defaulting to Kart 1." <<  endl;
		choice = 1;
	}
	else
		choice = c;
	mushroom = 3;
	x_pos=0.0;
	y_pos=0.0;
	z_pos=0.0;
	angle=M_PI/4;
	speed=0;
}

void Kart::DrawKart(){
	FILE * object;
	//vector< glm::vec3 > vertices;
	//vector< glm::vec2 > uvs;
	//vector< glm::vec3 > normals; // Won't be used at the moment.
	switch (choice){
		case 1:
			glutSolidTeapot(1.);
			//bool res = objloader("Kart1.obj", vertices, uvs, normals);
			//if (res == false){
			//	cout << "Could not draw obj" << endl;
			//}
			//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
			break;
		case 2:
			car.objloader("kk_kart.obj");
			car.render();
			//car.objdatadisplay();
			/*//bool res = objloader("Kart2.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
		case 3:
			/*//bool res = objloader("Kart3.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
		case 4:
			/*bool res = objloader("Kart4.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
	}
		
} 

			

float Kart::getX(){
	return x_pos;
}

float Kart::getY(){
	return y_pos;
}

float Kart::getZ(){
	return z_pos;
}

void Kart::setLocation( float x, float y, float z ){
	if( myTrack.isOnTrack( x, z ) ){
		x_pos = x;
		y_pos = y;
		z_pos = z;
	}
	else{
		speed = 0;
		x_pos = myTrack.toMiddleX( x, z );
		z_pos = myTrack.toMiddleZ( x, z );
	}
}

float Kart::getAngle(){
	return angle;
}

void Kart::setSpeed(float n){
	speed=n;
}

float Kart::getSpeed() {
	return speed;
}

void Kart::setAngle(float ang){
	angle=ang*M_PI/180;
}

void Kart::useShroom(){
	if( mushroom ){
		speed += 2;
		mushroom --;
	}
}

void Kart::setInitialTime()
{
	begin = clock();
}

double Kart::time()
{
	clock_t now = clock();
	double elapsed = double(now-begin)/CLOCKS_PER_SEC;
	if (elapsed > .2)
	{
		cout << endl;
		cout << elapsed << endl;
		lap = elapsed;
	}
	else
	{
		lap_n++;
		cout << lap << " " << lap_n << endl;
	}
	return elapsed;
}

clock_t Kart::getInitialTime()
{
	return begin;
}

void Kart::lapFunc()
{
	if (getX() < 10 && getX() > -10)
	{
		if ( getZ() >= 0 && getZ() <= 4)
		{
			begin = clock();
//			if (time() < .1)
//			{
//				lap[lap_n-1] = time();
//				begin[lap_n] = clock();
//				lap_n++;
//				cout << lap_n << endl;
//				cout << lap[lap_n-2] << endl;
//			}
		}
	}
}

void Kart::setLap_n(int l)
{
	lap_n = l;
}

int Kart::getLap_n()
{
	return lap_n;
}

void Kart::setLap_t(int l)
{
	lap = time();
}

double Kart::getLap_t(int l)
{
	return lap;
}
