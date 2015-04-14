#include "Track.h"

Track::Track(){

}

void Track::draw(){
	int x, z;
	float col;
	glPushMatrix();
	glTranslatef(-2.5,-1,0);
	for( z=0; z<660; z++ ){

		// determine colors for rainbow
		col = ((float)(z%10))/10;
		if( z%60 < 10 ){
			glColor3f(1,col,0);
		}else if( z%60 < 20 ){
			glColor3f(1-col,1,0);
		}else if( z%60 < 30 ){
			glColor3f(0,1,col);
		}else if( z%60 < 40 ){
			glColor3f(0,1-col,1);
		}else if( z%60 < 50 ){
			glColor3f(col,0,1);
		}else{
			glColor3f(1,0,1-col);
		}

		// initial straight section (120)
		if( z<120 ){
			for( x=0; x<10; x++ ){
				// make checkered start/finish line
				if( z == 0 ||  z == 2  ){
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
			glTranslatef(-5,0,0.5);
		}

		// first turn (left,10)
		else if( z<130 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<130-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-0.5*(float)x+0.5,0,0.5);
		}

		// straight section (80)
		else if( z<210 ){
			if( z == 130 )
				glTranslatef(0,0,-0.5);
			for( x=0; x<10; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,5);
		}

		// second turn (left,10)
		else if( z<220 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<220-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,0.5*(float)x-0.5);
		}

		// straight section (240)
		else if( z<460 ){
			if( z == 220 )
				glTranslatef(-0.5,0,0);
			for( x=0; x<10; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(5,0,-0.5);
		}

		// third turn (left,10)
		else if( z<470 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<470-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(0.5*(float)x-0.5,0,0.5);
		}

		// straight section (80)
		else if( z<550 ){
			if( z == 470 )
				glTranslatef(0,0,0.5);
			for( x=0; x<10; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-5);
		}

		// fourth turn (left,10)
		else if( z<560 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<560-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-0.5*(float)x+0.5);
		}

		// final straight section (100)
		else{
			if( z == 560 )
				glTranslatef(0.5,0,0);
			for( x=0; x<10; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-5,0,0.5);
		}
	}
	glPopMatrix();
}
