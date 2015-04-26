#include <cstdlib>
#include <sstream>
#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <string>
#include "Camera.h"
#include "Track1.h"
#include "Track2.h"
#include "Kart.h"

Camera myC;
Track * myTrack;
Kart * uKart;
float red = 0;
float green = 1;
float blue = 1;

float angle=90.;

int width = 960, height = 720;


int myrandom( int m ){
	return rand() % m;
}


void idle(){
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {
	// use escape key to exit
	if( key == 27 ){
		exit(0);
	}
	// use spacebar to activate mushroom
	else if( key == 32 ){
		uKart->useShroom();
	}	
}

void processSpecialKeys( int key, int x, int y ){
	switch(key){
	case GLUT_KEY_RIGHT:
		angle -= 1;
		uKart->setAngle(angle);
		if( uKart->getSpeed() > 0 )
			uKart->setSpeed( uKart->getSpeed() - 0.01 );
		else if( uKart->getSpeed() < 0 )
			uKart->setSpeed( uKart->getSpeed() + 0.01 ); 
		break;
	case GLUT_KEY_LEFT:
		angle += 1;
		uKart->setAngle(angle);
		if( uKart->getSpeed() > 0 )
			uKart->setSpeed( uKart->getSpeed() - 0.01 );
		else if( uKart->getSpeed() < 0 )
			uKart->setSpeed( uKart->getSpeed() + 0.01 ); 
		break;
	case GLUT_KEY_UP:
		if( uKart->getSpeed() < 4 )
			uKart->setSpeed( uKart->getSpeed() + 0.04 - (uKart->getSpeed()/100) );
		break;
	case GLUT_KEY_DOWN:
		if( uKart->getSpeed() > -4 )
			uKart->setSpeed( uKart->getSpeed() - 0.04 + (uKart->getSpeed()/100) );
		break;
	}

}

void OnReshape( int w, int h ){
	if( h == 0 )
		h = 1;
	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45, (float) w / h, 0.1, 100 );
	glMatrixMode( GL_MODELVIEW );
}

void OnDraw(){
	glClear( GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
	glColor3f( red, green, blue );
	glShadeModel( GL_FLAT );
	glEnable( GL_LIGHTING ); 
	glEnable( GL_LIGHT0 );
	glEnable( GL_COLOR_MATERIAL );
	float ambient[] = {1, 0, 0, 1}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	glLoadIdentity();
	if( uKart->getSpeed() > 0 )
		uKart->setSpeed( uKart->getSpeed() - 0.02 );
	else if( uKart->getSpeed() < 0 )
                uKart->setSpeed( uKart->getSpeed() + 0.02 );
	uKart->setLocation( uKart->getX() - uKart->getSpeed() * cos( uKart->getAngle() ), uKart->getY(), uKart->getZ() + uKart->getSpeed() * sin( uKart->getAngle() ) );
	myC.KartLocation( uKart->getX(), uKart->getY(), uKart->getZ(), uKart->getAngle() );// set camera to behind kart
	myC.updateLookAt();// update camera drawing
	uKart->time();
	uKart->lapFunc();
	glColor3d( red, green, blue );
	glPushMatrix();
	glTranslatef( uKart->getX(), uKart->getY(), uKart->getZ() );// move to kart location
	glRotatef( -90, 0, 1, 0 );// rotate so the kart faces forward initially
	glRotatef( angle - 90, 0, 1, 0 );// rotate the kart to the apropriate angle
	uKart->DrawKart();
	glPopMatrix();
	myTrack->draw();

	// display time to the window
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,width,height,0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	//glColor3f(1.0f,1.0f,1.0f);
	glRasterPos2f(50,50);
	std::stringstream s;
	s << "TIME: " << uKart->getLap_t();
	string text = s.str();
	for (int i = 0; i < text.size(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
	}
	s.str("");
	text.clear();
	glRasterPos2f(50,80);
	s << "LAP: " << uKart->getLap_n()+1;
	text = s.str();
	for (int i = 0; i < text.size(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glutSwapBuffers();
}

// do nothing on exit (for now)
void OnExit(){}

// part that actually runs
int main( int argc, char** argv ){
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE );
	glutInitWindowSize( width, height );
	glutCreateWindow( "Mario Kart" );
	glutDisplayFunc( OnDraw );// the important drawing function
	glutReshapeFunc( OnReshape );
	glEnable( GL_DEPTH_TEST );
	atexit( OnExit );
	glutIdleFunc( idle );
	glutKeyboardFunc( processNormalKeys );
	glutSpecialFunc( processSpecialKeys );
	//glutMotionFunc(mouse_motion);
	Track1 myTrack1;
	Track2 myTrack2;
	myTrack = &myTrack2;
	uKart = new Kart( 1, myTrack );
	uKart->setAngle(angle);
	uKart->setInitialTime();
	glutMainLoop();
	return 0;
}
