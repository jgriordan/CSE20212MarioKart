#include "Track2.h"

Track2::Track2(){
}

// draw the entire track by segment
void Track2::draw(){
	int x, z;
	float col;
	glPushMatrix();
	// set initial location to draw from
	glTranslatef(-9.75,-1,0.5);
	for( z=0; z<3362; z++ ){
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
		 // first straight (0<z<120 -10<x<10)
		if( z<240 ){
			for( x=0; x<40; x++ ){
				// make checkered start/finish line
				if( z == 0 || z == 2 ){
					glDisable(GL_LIGHTING);
					if( x % 2 )
						glColor3f(0.9,0.9,0.9);
					else
						glColor3f(0.1,0.1,0.1);
				}else if( z == 1 ){
					glDisable(GL_LIGHTING);
					if( x % 2 )
						glColor3f(0.1,0.1,0.1);
					else
						glColor3f(0.9,0.9,0.9);
				}
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
				glEnable(GL_LIGHTING);
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
 		// second straight (120<z<140, 10<x<90)
		else if( z<440 ){
			if( z == 280 )
				glTranslatef(0,0,-0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,20);
		}
		// second turn (90<x<110, x+30<z<140)
		else if( z<480 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<480-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,0.5*(float)x);
		}
		// third straight (90<x<110, 140<z<260)
		else if( z<720 ){
			if( z == 480 )
				glTranslatef(-0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(20,0,0.5);
		}
		// third turn (260<z<280, 90<x<370-z)
		else if( z<760 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<760-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(0.5*(float)x-0.5,0,0.5);
		}
		// fourth straight (260<z<280, -70<x<90)
		else if( z<1080 ){
			if( z == 760 )
				glTranslatef(0,0,-0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(-0.5,0,20);
		}
		// fourth turn (-90<x<-70, 260<z<x+350)
		else if( z<1120 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<1120-z; x++ ){
				glutSolidCube(0.5);	
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(-0.5,0,0.5*(float)x-0.5);
		}
		// fifth straight (-90<x<-70, -100<z<260)
		else if( z < 1840){
			if( z == 1120 )
				glTranslatef(0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-20,0,-0.5);
		}
		// fifth turn (-120<z<-100, -90<x<z+30)
		else if( z<1880 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<1880-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-0.5*(float)x,0,-0.5);
		}
		// sixth straight (-120<z<-100, -170<x<-90)
		else if( z<2040 ){
			if( z == 1880 )
				glTranslatef(0,0,0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-20);
		}
		// sixth turn (-190<x<-170, -120<z<x+70)
		else if( z<2080 ){
			glColor3f(0,0.5,0.5);
			if( z == 2040 )
				glTranslatef(0,0,19.5);
			for( x=0; x<2080-z; x++ ){
				glutSolidCube(0.5);	
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(-0.5,0,0.5*(float)x-0.5);
		}
		// seventh straight (-190<x<-170, -120<z<-200)
		else if( z < 2240){
			if( z == 2080 )
				glTranslatef(0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-20,0,-0.5);
		}
		// seventh turn (-220<z<-200, -390-z<x<-170)
		else if( z < 2280 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<2280-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-0.5*(float)x+0.5,0,-0.5);
		}
 		// eighth straight (-220<z<-200, -170<x<70)
		else if( z<2760 ){
			if( z == 2280 )
				glTranslatef(0,0,0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(0.5,0,-20);
		}
		// eighth turn (70<x<90, x-290<z<-200)
		else if( z<2800 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<2800-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(0.5,0,-0.5*(float)x+0.5);
		}
		// ninth straight (70<x<90, -200<z<-120)
		else if( z<2960 ){
			if( z == 2800 )
				glTranslatef(-0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(20,0,0.5);
		}
		// ninth turn (-100<z<-80, 70<x<-10-z)
		else if( z < 3000 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<3000-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(0.5*(float)x-0.5,0,0.5);
		}
		// tenth straight (-120<z<-100, 10<x<70)
		else if( z<3121 ){
			if( z == 3000 )
				glTranslatef(0,0,-0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(-0.5,0,20);
		}
		// tenth turn (-10<x<10, -10-x<z<-100)
		else if( z<3161 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<3161-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(-0.5,0,0.5*(float)x);
		}
		// last straight (-10<x<10, -100<z<0)
		else{
			if( z == 3161 )
				glTranslatef(0.5,0,0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-20,0,0.5);
		}

	}
	glPopMatrix();
}

// check by segment to see if the x,z location is on the track
int Track2::isOnTrack( float x, float z ){
	// first and last straight
	if( x > -10 && x < 10 && z >= -100 && z <= 120 )
		return 1;
	// first turn
	else if( z >= 120 && z < 140 && x <= 10 && x > z-130 )
		return 1;
	// second straight
	else if( z > 120 && z < 140 && x >=10 && x <= 90 )
		return 1;
	// second turn
	else if( x >= 90 && x < 110 && z >= x+30 && z < 140 )
		return 1;
	// third straight
	else if( x > 90 && x < 110 && z >= 140 && z <= 260 )
		return 1;
	// third turn
	else if( z >= 260 && z < 280 && x >= 90 && x < 370-z )
		return 1;
	// fourth straight
	else if( z < 280 && z > 260 && x <= 90 && x >= -70 )
		return 1;
	// fourth turn
	else if( x <= -70 && x > -90 && z < x+350 && z >= 260 )
		return 1;
	// fifth straight
	else if( x > -90 && x < -70 && z <= 260 && z >= -100 )
		return 1;
	// fifth turn
	else if( z <= -100 && z > -120 && x >= -90 && x < z+30 )
		return 1;
	// sixth straight
	else if( z < -100 && z > -120 && x <= -90 && x >= -170 )
		return 1;
	// sixth turn
	else if( x <= -170 && x >-190 && z < x+70 && z >= -120 )
		return 1;
	// seventh straight
	else if( x > -190 && x < -170 && z <= -120 && z >= -200 )
		return 1;
	// seventh turn
	else if( z > -220 && z <= -200 && x <= -170 && x > -390-z )
		return 1;
	// eighth straight
	else if( z > -220 && z < -200 && x >= -170 && x <= 70 )
		return 1;
	// eighth turn
	else if( x >= 70 && x < 90 && z <= -200 && z > x-290 )
		return 1;
	// ninth straight
	else if( x > 70 && x < 90 && z <= -120 && z >= -200 )
		return 1;
	// ninth turn
	else if( z >= -120 && z < -100 && x >= 70 && x < -30-z )
		return 1;
	// tenth straight
	else if( z > -120 && z < -100 && x <= 70 && x >= 10 )
		return 1;
	// tenth turn
	else if( x > -10 && x <= 10 && z <= -100 && z > -110-x )
		return 1;
	else
		return 0;
}

// looks by segment to return the center x value of the track nearest the kart
float Track2::toMiddleX(float x, float z){
	// first and last straight
	if( ( ( x <= -10 && x > -15 ) || ( x >= 10 && x < 15 ) ) && z >= -100 && z <= 120 )
		return 0;
	// first turn
	else if( z > 120 && z < 140 && x < 10 && x > -10 )
		return 5;
	// second straight
	else if( ( ( z <= 120 && z > 115 ) || ( z >= 140 && z < 145 ) ) && x >= 10 && x <= 90 )
		return x;
	// second turn
	else if( x > 90 && x < 110 && z > 120 && z < 140 )
		return 95;
	// third straight
	else if( ( ( x <= 90 && x > 85 ) || ( x >= 110 && x < 115 ) ) && z <= 260 && z >= 140 )
		return 100;
	// third turn
	else if( z < 280 && z > 260 && x > 90 && x < 110 )
		return 95;
	// fourth straight
	else if( ( ( z >= 280 && z < 285 ) || ( z <= 260 && z > 255 ) ) && x <= 90 && x >= -70 )
		return x;
	// fourth turn
	else if( x < -70 && x > -90 && z < 280 && z > 260 )
		return -75;
	// fifth straight
	else if( ( ( x <= -90 && x > -95 ) || ( x >= -70 && x < -65 ) ) && z <= 260 && z >= -100 )
		return -80;
	// fifth turn
	else if( z < -100 && z > -120 && x < -70 && x > -90 )
		return -85;
	// sixth straight
	else if( ( ( z >= -100 && z < -95 ) || ( z <= -120 && z > -125 ) ) && x <= -90 && x >= -170 )
		return x;
	// sixth turn
	else if( x < -170 && x > -190 && z < -100 && z > -120 )
		return -175;
	// seventh straight
	else if( ( ( x <= -190 && x > -195 ) || ( x >= -170 && x < -165 ) ) && z <= -120 && z >= -200 )
		return -180;
	// seventh turn
	else if( z < -200 && z > -220 && x < -170 && x > -190 )
		return -175;
	// eighth straight
	else if( ( ( z <= -220 && z > -225 ) || ( z >= -200 && z < -195 ) ) && x >= -170 && x <= 70 )
		return x;
	// eighth turn
	else if( x > 70 && x < 90 && z > -220 && z < -200 )
		return 75;
	// ninth straight
	else if( ( ( x <= 70 && x > 65 ) || ( x >= 90 && x < 95 ) ) && z <= -120 && z >= -200 )
		return 80;
	// ninth turn
	else if( z < -100 && z > -120 && x < 90 && x > 70 )
		return 75;
	// tenth straight
	else if( ( ( z <= -120 && z > -125 ) || ( z >= -100 && z < -95 ) ) && x >= 10 && x <= 70 )
		return x;
	// tenth turn
	else if( x > -10 && x < 10 && z > -120 && z < -100 )
		return 5;
	else
		return 0;
}

// looks by segment to return the center z value of the track nearest the kart
float Track2::toMiddleZ(float x, float z){
	// first and last straight
	if( ( ( x <= -10 && x > -15 ) || ( x >= 10 && x < 15 ) ) && z >= -100 && z <= 120 )
		return z;
	// first turn
	else if( z > 120 && z < 140 && x < 10 && x > -10 )
		return 125;
	// second straight
	else if( ( ( z <= 120 && z > 115 ) || ( z >= 140 && z < 145 ) ) && x >= 10 && x <= 90 )
		return 130;
	// second turn
	else if( x > 90 && x < 110 && z > 120 && z < 140 )
		return 135;
	// third straight
	else if( ( ( x <= 90 && x > 85 ) || ( x >= 110 && x < 115 ) ) && z <= 260 && z >= 140 )
		return z;
	// third turn
	else if( z < 280 && z > 260 && x > 90 && x < 110 )
		return 265;
	// fourth straight
	else if( ( ( z >= 280 && z < 285 ) || ( z <= 260 && z > 255 ) ) && x <= 90 && x >= -70 )
		return 270;
	// fourth turn
	else if( x < -70 && x > -90 && z < 280 && z > 260 )
		return 265;
	// fifth straight
	else if( ( ( x <= -90 && x > -95 ) || ( x >= -70 && x < -65 ) ) && z <= 260 && z >= -100 )
		return z;
	// fifth turn
	else if( z < -100 && z > -120 && x < -70 && x > -90 )
		return -105;
	// sixth straight
	else if( ( ( z >= -100 && z < -95 ) || ( z <= -120 && z > -125 ) ) && x <= -90 && x >= -170 )
		return -110;
	// sixth turn
	else if( x < -170 && x > -190 && z < -100 && z > -120 )
		return -115;
	// seventh straight
	else if( ( ( x <= -190 && x > -195 ) || ( x >= -170 && x < -165 ) ) && z <= -120 && z >= -200 )
		return z;
	// seventh turn
	else if( z < -200 && z > -220 && x < -170 && x > -190 )
		return -205;
	// eighth straight
	else if( ( ( z <= -220 && z > -225 ) || ( z >= -200 && z < -195 ) ) && x >= -170 && x <= 70 )
		return -210;
	// eighth turn
	else if( x > 70 && x < 90 && z > -220 && z < -200 )
		return -205;
	// ninth straight
	else if( ( ( x <= 70 && x > 65 ) || ( x >= 90 && x < 95 ) ) && z <= -120 && z >= -200 )
		return z;
	// ninth turn
	else if( z < -100 && z > -120 && x < 90 && x > 70 )
		return -115;
	// tenth straight
	else if( ( ( z <= -120 && z > -125 ) || ( z >= -100 && z < -95 ) ) && x >= 10 && x <= 70 )
		return -110;
	// tenth turn
	else if( x > -10 && x < 10 && z > -120 && z < -100 )
		return -105;
	else
		return 0;
}
