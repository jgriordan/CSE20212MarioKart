#include "Track.h"

Track::Track(){

}

void Track::draw(){
	int x, z;
	float col;
	glPushMatrix();
	glTranslatef(-2.5,-1,0);
	for( z=0; z<2640; z++ ){

		// determine colors for rainbow
		col = ((float)(z%20))/10;
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

		// initial straight section (480)
		if( z<480 ){
			for( x=0; x<40; x++ ){
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
			glTranslatef(-20,0,0.5);
		}

		// first turn (left,10)
		else if( z<520 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<520-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0.5,0,0);
			}
			glTranslatef(-0.5*(float)x+0.5,0,0.5);
		}

		// straight section (70)
		else if( z<800 ){
			if( z == 520 )
				glTranslatef(0,0,-0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,20);
		}

		// second turn (left,10)
		else if( z<840 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<840-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,-0.5);
			}
			glTranslatef(0.5,0,0.5*(float)x-0.5);
		}

		// straight section (240)
		else if( z<1800 ){
			if( z == 840 )
				glTranslatef(-0.5,0,0);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(20,0,-0.5);
		}

		// third turn (left,10)
		else if( z<1840 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<1840-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(-0.5,0,0);
			}
			glTranslatef(0.5*(float)x-0.5,0,-0.5);
		}

		// straight section (70)
		else if( z<2120 ){
			if( z == 1840 )
				glTranslatef(0,0,0.5);
			for( x=0; x<40; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-20);
		}

		// fourth turn (left,10)
		else if( z<2160 ){
			glColor3f(0,0.5,0.5);
			for( x=0; x<2160-z; x++ ){
				glutSolidCube(0.5);
				glTranslatef(0,0,0.5);
			}
			glTranslatef(-0.5,0,-0.5*(float)x+0.5);
		}

		// final straight section (120)
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
