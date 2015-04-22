#include "Track.h"
Track::Track(){

}
void Track::draw(){
	int x, z;
	float col;
	glPushMatrix();
	glTranslatef(-9.75,-1,0);
	for( z=0; z<2640; z++ ){
		//determine colors for rainbow
		col = ((float)(z%20))/20;
		if( z%120 < 20 ){
			glColor3f(1,col,0);
		}else if( z%120 < 40 ){
			glColor3f(1-col,1,0);
		}else if( z%120 < 60 ){
			glColor3f(0,1,col);
		}else if( z%120 < 80 ){
			glColor3f(0,1-col,1);
		}else if( z%120 < 100 ){
			glColor3f(col,0,1);
		}else{
			glColor3f(1,0,1-col);
 		}
		 // initial straight section (0<z<120 -10<x<10)
		if( z<240 ){
			for( x=0; x<40; x++ ){
				// make checkered start/finish line
				if( z == 0 || z == 2 ){
					if( x % 2 )
						glColor3f(0.9,0.9,0.9);
					else
						glColor3f(0.1,0.1,0.1);
				}else if( z == 1 ){
					if( x % 2 )
						glColor3f(0.1,0.1,0.1);
					else
						glColor3f(0.9,0.9,0.9);
				}
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			 }
			glTranslatef(-20,0,0.5);
		}
		 // first turn (120<z<140, z-130<x<10)
		else if( z<280 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<280-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
 			}
			glTranslatef(-0.5*(float)x+0.5,0,0.5);
 		}
 		// straight section (120<z<140, 10<x<90)
		else if( z<440 ){
			if( z == 520 )
				glTranslatef(0,0,-0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,20);
		}
		// second turn (150<x<170, 240<z<410-x)
		else if( z<840 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<840-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,0.5*(float)x-0.5);
		}
		// straight section (150<x<170, -240<z<240)
		else if( z<1800 ){
			if( z == 840 )
				glTranslatef(-0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(20,0,-0.5);
		}
		// third turn (-260<z<-240, 150<x<410+z)
		else if( z<1840 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<1840-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(0.5*(float)x-0.5,0,-0.5);
		}
		// straight section (-260<z<-240, 10<x<150)
		else if( z<2120 ){
			if( z == 1840 )
				glTranslatef(0,0,0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-20);
		}
		// fourth turn (-10<x<10, -250-x<z<-240-x)
		else if( z<2160 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<2160-z; x++ ){
				glutSolidCube(0.5);	
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-0.5*(float)x+0.5);
		}
		// final straight section (-10<x<10, -240<z<0)
		else{
			if( z == 2160 )
				glTranslatef(0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-20,0,0.5);
		}
	}
	glPopMatrix();
}

int Track::isOnTrack( float x, float z ){
	if( x > -10 && x < 10 && z >= -240 && z <= 120 )
		return 1;
	else if( z >= 120 && z < 140 && x <= 10 && x > z-130 )
		return 1;
	else if( z > 140 && z < 260 && x >=10 && x <= 150 )
		return 1;
	else if( x >= 150 && x < 170 && z >= 240 && z < 410-x )
		return 1;
	else if( x > 150 && x < 170 && z <= 240 && z >= -240 )
		return 1;
	else if( z <= -240 && z > -260 && x >=150 && x < z+410 )
		return 1;
	else if( z < -240 && z > -260 && x <= 150 && x >= 10 )
		return 1;
	else if( x <= 10 && x > -10 && z <= -240 && z > -250-x )
		return 1;
	else
		return 0;
}

float Track::toMiddleX(float x, float z){
	if( ( ( x <= -10 && x > -15 ) || ( x >= 10 && x < 15 ) ) && z >= -240 && z <= 240 )
		return 0;
	else if( z >= 240 && z < 260 && x < 10 && x > -10 )
		return 5;
	else if( ( ( z <= 240 && z > 235 ) || ( z >= 260 && z < 265 ) ) && x >= 10 && x <= 150 )
		return x;
	else if( x > 150 && x < 170 && z > 240 && z < 260 )
		return 155;
	else if( ( ( x <= 150 && x > 145 ) || ( x >= 170 && x < 175 ) ) && z <= 240 && z >= -240 )
		return 160;
	else if( z < -240 && z > -260 && x > 150 && x < 170 )
		return 155;
	else if( ( ( z >= -240 && z < -235 ) || ( z <= -260 && z > -265 ) ) && x <= 150 && x >= 10 )
		return x;
	else if( x < 10 && x > -10 && z < -240 && z > -260 )
		return 5;
	else
		return 0;
}

float Track::toMiddleZ(float x, float z){
	if( ( ( x <= -10 && x > -15 ) || ( x >= 10 && x < 15 ) ) && z >= -240 && z <= 240 )
		return z;
	else if( z >= 240 && z < 260 && x < 10 && x > -10 )
		return 245;
	else if( ( ( z <= 240 && z > 235 ) || ( z >= 260 && z < 265 ) ) && x >= 10 && x <= 150 )
		return 250;
	else if( x > 150 && x < 170 && z > 240 && z < 260 )
		return 245;
	else if( ( ( x <= 150 && x > 145 ) || ( x >= 170 && x < 175 ) ) && z <= 240 && z >= -240 )
		return z;
	else if( z < -240 && z > -260 && x > 150 && x < 170 )
		return -245;
	else if( ( ( z >= -240 && z < -235 ) || ( z <= -260 && z > -265 ) ) && x <= 150 && x >= 10 )
		return -250;
	else if( x < 10 && x > -10 && z < -240 && z > -260 )
		return -245;
	else
		return 0;
}
