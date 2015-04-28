#include "Kart.h"

Kart::Kart( int c, Track * track, int trackOpt ):myTrack(track){
	if (c > 4 || c < 1){
		std::cout <<"Invalid choice! Defaulting to Kart 1." <<  std::endl;
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
	hasStarted = 0;
	lap_n = 0;
	bestTimeD = 1000;
	bestTimeS = "-";
	lastTime = "no lap";
	for (int i = 0; i < 4; i++)
		pos[i] = 0;
	for (int i = 0; i < 10; i++)
		pos_2[i] = 0;
	trackSelect = trackOpt;
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
			//	std::cout << "Could not draw obj" << endl;
			//}
			//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
			break;
		case 2:
			cube=car.load("cow.obj");      //load it
			glCallList(cube);       //and display it
			//glutSwapBuffers(); //swap the buffers
			//car.render();
			//car.objdatadisplay();
			/*//bool res = objloader("Kart2.obj", vertices, uvs, normals);
                        if (res == false){
                                std::cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
		case 3:
			//car.objloader( "cow.obj");
			//car.render();
			/*//bool res = objloader("Kart3.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
		case 4:
			/*bool res = objloader("Kart4.obj", vertices, uvs, normals);
                        if (res == false){
                                std::cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
	}
		
} 

void Kart :: setChoice(int c){
	choice=c;
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
	if( myTrack->isOnTrack( x, z ) ){
		x_pos = x;
		y_pos = y;
		z_pos = z;
	}
	else{
		speed = 0;
		x_pos = myTrack->toMiddleX( x, z );
		z_pos = myTrack->toMiddleZ( x, z );
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
	int ang_w;
	int ang_int;
	if (ang > 360)
	{
		ang_w = ang/360;
		ang = ang - 360*ang_w;
	}
	else if (ang <=0)
	{
		ang_int = ang;
		ang_w  = abs(ang_int/360)+1;
		ang = ang + 360*ang_w;
	}
	angle=ang*M_PI/180;
//	std::cout << angle << std::endl;
}

int Kart::wrongWay()
{
	int wrongway = 0;
	if (trackSelect == 1)
	{
		if (x_pos >= -10 && x_pos <= 10)
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos[0] = 1;
		}
		else if (z_pos >= 240 && z_pos <= 260)
		{
			if (angle > 5.06145 || angle < 1.22173)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos[1] = 1;
		}
		else if (x_pos >= 150 && x_pos <= 170)
		{
			if (angle > .349065 && angle < 2.79252)
				wrongway = 1;	
			else
				if (speed*25 > 0)
					pos[2] = 1;
		}
		else if (z_pos <= -240 && z_pos >= -260)
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos[3] = 1;
		} 
	}
	else
	{ 						// use this stuff for track1
		if(x_pos >= -10 && x_pos <= 10)
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[0] = 1;
		}
		else if (z_pos >= 120 && z_pos <= 140)
		{
			if (angle > 5.06145 || angle < 1.22173)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[1] = 1;
		}
		else if (x_pos >= 90 && x_pos <= 110)
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[2] = 1;	
		}
		else if (z_pos >= 260 && z_pos <= 280)
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[3] = 1;
		}
		else if (x_pos >= -90 && x_pos <= -70)
		{
			if (angle > .349065 && angle < 2.79252)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[4] = 1;
		}
		else if (z_pos >= -120 && z_pos <= -100 && x_pos >= -170 && x_pos <= -90)
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[5] = 1;
		}
		else if (x_pos >= -190 && x_pos <= -170)
		{
			if (angle > .349065 && angle < 2.79252)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[6] = 1;
		}
		else if (z_pos >= -220 && z_pos <= -200)
		{
			if (angle > 5.06145 || angle < 1.22173)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[7] = 1;
		}
		else if (x_pos >= 70 && x_pos <= 90)
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[8] = 1;
		}
		else if (z_pos >= -120 && z_pos <= -100 && x_pos >= 10 && x_pos <= 70)
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[9] = 1;
		}
	}
	return wrongway;
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
//	for(int i = 0; i < 4; i++)
//		std::cout << pos[i];
//	std::cout << std::endl;
//	std::cout << hasStarted << " " << wrongWay() << std::endl;
	clock_t now = clock();
	int sum_pos = 0;
	double elapsed = double(now-begin)/CLOCKS_PER_SEC;
	if (elapsed > 1)
	{
		//std::cout << std::endl;
		//std::cout << elapsed << std::endl;
		hasStarted = 1;
		lap = elapsed;
	}
	else if( hasStarted == 1 && wrongWay() == 0 )
	{
		if (trackSelect == 1)
		{
			for (int i = 0; i < 4; i++) 
				sum_pos += pos[i]; 
			if (sum_pos == 4)
			{
				lap_n++;
				//std::cout << "lap " << lap_n << ": " << lap << endl;
				std::ostringstream stm;
       		 		stm << lap;
				lastTime = stm.str();
				if( bestTimeD > lap ){
					bestTimeD = lap;
        				bestTimeS = stm.str();
				}
				hasStarted = 0;
				for (int i = 0; i < 4; i++)
					pos[i] = 0;
			}
		}
		else if (trackSelect == 2)
		{
			for (int i = 0; i < 10; i++) 
				sum_pos += pos_2[i]; 
			if (sum_pos == 10)
			{
				lap_n++;
				//std::cout << "lap " << lap_n << ": " << lap << endl;
				std::ostringstream stm;
       		 		stm << lap;
				lastTime = stm.str();
				if( bestTimeD > lap ){
					bestTimeD = lap;
        				bestTimeS = stm.str();
				}
				hasStarted = 0;
				for (int i = 0; i < 10; i++) 
					pos_2[i] = 0; 
			}
		}

	}
	return elapsed;
}

clock_t Kart::getInitialTime()
{
	return begin;
}

void Kart::lapFunc()
{
	int sum_pos = 0;
	if (getX() < 10 && getX() > -10)
	{
		if ( getZ() >= 0 && getZ() <= 4)
		{
			if (wrongWay() == 0)
			{
				for (int i = 0; i < 10; i++)  // again using 10 here for track2, 4 for track1
					sum_pos += pos_2[i]; // also use pos_2 array for track2, pos for track1
				if (sum_pos == 10 || sum_pos == 0)
					begin = clock();
			}
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

double Kart::getLap_t()
{
	return lap;
}

std::string Kart::getBestTime(){
	return bestTimeS;
}

std::string Kart::getLastTime(){
	return lastTime;
}
