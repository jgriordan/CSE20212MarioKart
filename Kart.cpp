#include "Kart.h"

Kart::Kart( int c, Track * track, int trackOpt ):myTrack(track){
	if (c > 3 || c < 1){  //check to see if kart slection is valid
		std::cout <<"Invalid choice! Defaulting to Kart 1." <<  std::endl;
		choice = 1;
	}
	else
		choice = c;
	mushroom = 3;//Mushroom increase Kart speed
	x_pos=0.0;//Set initial position
	y_pos=0.0;
	z_pos=0.0;
	angle=M_PI/4;
	speed=0;
	hasStarted = 0;//Determine if the Kart has started.
	lap_n = 0;//Lap Counter
	bestTimeD = 1000;
	bestTimeS = "-";
	lastTime = "no lap";
	for (int i = 0; i < 4; i++)	// initialize both position arrays to 0, 
		pos[i] = 0;
	for (int i = 0; i < 10; i++)	// these will be set to 1's as the kart successfully completes a lap
		pos_2[i] = 0;
	trackSelect = trackOpt;
}

void Kart::DrawKart(){
	switch (choice){
		case 1:
			glutSolidTeapot(1.);
			break;
		case 2:
			cube=car.load("cow.obj");      //load it
			glCallList(cube);       //and display it
                        break;
		case 3:
			//Draw Snowman code from class.
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslatef(0.0f ,0.75f, 0.0f);
			glutSolidSphere(0.75f,20,20);
			glTranslatef(0.0f, 1.0f, 0.0f);
			glutSolidSphere(0.25f,20,20);
			glPushMatrix();
			glColor3f(0.0f,0.0f,0.0f);
			glTranslatef(0.05f, 0.10f, 0.18f);
			glutSolidSphere(0.05f,10,10);
			glTranslatef(-0.1f, 0.0f, 0.0f);
			glutSolidSphere(0.05f,10,10);
			glPopMatrix();
			glColor3f(1.0f, 0.5f , 0.5f);
			glRotatef(0.0f,1.0f, 0.0f, 0.0f);
			glutSolidCone(0.08f,0.5f,10,2);
                        break;
	}
		
} 

void Kart :: setChoice(int c){
	choice=c;//Set Kart Choice
}			

// The following functions get the x,y, and z position of the kart.
float Kart::getX(){
	return x_pos;
}

float Kart::getY(){
	return y_pos;
}

float Kart::getZ(){
	return z_pos;
}

// update the kart's location
void Kart::setLocation( float x, float y, float z ){
	// location is on track- set it
	if( myTrack->isOnTrack( x, z ) ){
		x_pos = x;
		y_pos = y;
		z_pos = z;
	}
	// location isn't on track- kill speed and put kart in middle of track
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

void Kart::setAngle(float ang){ // function sets angle to value between 0 and 2pi
	int ang_w;
	int ang_int;
	if (ang > 360)
	{
		ang_w = ang/360;//Ensures that the angle is in the proper direction when resetting the Kart.
		ang = ang - 360*ang_w;
	}
	else if (ang <=0)
	{
		ang_int = ang;
		ang_w  = abs(ang_int/360)+1;
		ang = ang + 360*ang_w;
	}
	angle=ang*M_PI/180;
}

int Kart::wrongWay()
{
	int wrongway = 0;
	if (trackSelect == 1)	// the bounds correspond to the bounds for track1, given these limits, the angle must be within 110 degrees of due straight
	{
		if (x_pos >= -10 && x_pos <= 10)
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;	// indicate that the kart is in the wrong direction. Other functions will use this value to determine behavior
			else
				if (speed*25 > 0)	// this is the value displayed to the screen
					pos[0] = 1;	// this index corresponds to the first segment of the track, designated by the bounds above
		}
		else if (z_pos >= 240 && z_pos <= 260)	// second straight
		{
			if (angle > 5.06145 || angle < 1.22173)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos[1] = 1;
		}
		else if (x_pos >= 150 && x_pos <= 170)	// third straight
		{
			if (angle > .349065 && angle < 2.79252)
				wrongway = 1;	
			else
				if (speed*25 > 0)
					pos[2] = 1;
		}
		else if (z_pos <= -240 && z_pos >= -260)	// fourth straight
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos[3] = 1;
		} 
	}
	else
	{ 					
		if(x_pos >= -10 && x_pos <= 10)		// these bounds correspond to track2. Same deal as above, but just more segments to consider
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[0] = 1;
		}
		else if (z_pos >= 120 && z_pos <= 140)	//second straight
		{
			if (angle > 5.06145 || angle < 1.22173)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[1] = 1;
		}
		else if (x_pos >= 90 && x_pos <= 110)	//third straight
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[2] = 1;	
		}
		else if (z_pos >= 260 && z_pos <= 280)	// fourth straight
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[3] = 1;
		}
		else if (x_pos >= -90 && x_pos <= -70)	// fifth straight
		{
			if (angle > .349065 && angle < 2.79252)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[4] = 1;
		}
		else if (z_pos >= -120 && z_pos <= -100 && x_pos >= -170 && x_pos <= -90)	// sixth straight
		{
			if (angle > 1.91986 && angle < 4.36332)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[5] = 1;
		}
		else if (x_pos >= -190 && x_pos <= -170)	// seventh straight
		{
			if (angle > .349065 && angle < 2.79252)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[6] = 1;
		}
		else if (z_pos >= -220 && z_pos <= -200)	// eighth straight
		{
			if (angle > 5.06145 || angle < 1.22173)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[7] = 1;
		}
		else if (x_pos >= 70 && x_pos <= 90)	//ninth straight
		{
			if (angle > 3.49065 && angle < 5.93411)
				wrongway = 1;
			else
				if (speed*25 > 0)
					pos_2[8] = 1;
		}
		else if (z_pos >= -120 && z_pos <= -100 && x_pos >= 10 && x_pos <= 70) // tenth straight
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

double Kart::time()		// this function judges the time on a lap relative to the private data member begin. It also determines the best time
{
	clock_t now = clock();
	int sum_pos = 0;
	double elapsed = double(now-begin)/CLOCKS_PER_SEC;
	if (elapsed > 1)
	{
		hasStarted = 1;
		lap = elapsed;
	}
	else if( hasStarted == 1 && wrongWay() == 0 )
	{
		if (trackSelect == 1)
		{
			for (int i = 0; i < 4; i++) 
				sum_pos += pos[i]; //pos[] corresponds to track1 indexes
			if (sum_pos == 4)
			{
				lap_n++;
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
				sum_pos += pos_2[i]; //pos_2[] corresponds to track2 indexes
			if (sum_pos == 10)
			{
				lap_n++;
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
	if (getX() < 10 && getX() > -10)	// operates at the finish line...
	{
		if ( getZ() >= 0 && getZ() <= 4) //... which is actually a zone
		{
			if (wrongWay() == 0)
			{
				if (trackSelect == 1) // easy track conditions to reset the timer
				{
					for (int i = 0; i < 4; i++)  
						sum_pos += pos[i]; 
					if (sum_pos == 4 || sum_pos == 0) // actvate when full lap complete or when before the race starts
						begin = clock();
				}	
				else if (trackSelect == 2)	// hard track conditions to reset the timer
				{
					for (int i = 0; i < 10; i++)  
						sum_pos += pos_2[i]; 
					if (sum_pos == 10 || sum_pos == 0) // activate when full lap complete or when before the race starts
						begin = clock();
				}
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

int Kart::getShroom()
{
	return mushroom;
}

std::string Kart::getBestTime(){
	return bestTimeS;
}

std::string Kart::getLastTime(){
	return lastTime;
}
