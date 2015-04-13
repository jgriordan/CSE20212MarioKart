#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
#include "Camera.h"
#include "Track.h"
#include "Kart.h"

//static GLdouble eyeX=5;
//static GLdouble eyeY=10;
//static GLdouble eyeZ=5;

Camera myC;
Track myTrack;
Kart uKart(1);
float red = 0;
float green = 1;
float blue = 1;

float angle=90.;
//static float x = 0.0, y = 1.75, z = 5.0;
//static float lx = 0.0, ly = 0.0, lz = -1.0;

int myrandom( int m ){
	return rand() % m;
}


void idle(){
	//glClearColor((double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255);
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);	
}

void processSpecialKeys(int key, int x, int y){
	switch(key){
	case GLUT_KEY_RIGHT:
		angle -= 45;
		uKart.setAngle(angle);
//		myC.rotateCW( angle );
		break;
	case GLUT_KEY_LEFT:
		angle += 45;
		uKart.setAngle(angle);
//		myC.rotateCCW( angle );
		break;
	case GLUT_KEY_UP:
//		myC.moveForward(uKart.getAcc()*sin(uKart.getAngle())+uKart.getAcc()*cos(uKart.getAngle()));
		uKart.setZ(uKart.getZ()+uKart.getAcc()*sin(uKart.getAngle()));
		uKart.setX(uKart.getX()-uKart.getAcc()*cos(uKart.getAngle()));	
		break;
	case GLUT_KEY_DOWN:
//		myC.moveForward((uKart.getAcc()*sin(uKart.getAngle())+uKart.getAcc()*cos(uKart.getAngle())));
                uKart.setZ(uKart.getZ()-uKart.getAcc()*sin(uKart.getAngle()));
		uKart.setX(uKart.getX()+uKart.getAcc()*cos(uKart.getAngle()));
		break;
	}
}

/*void mouse_button(int button, int state, int x, int y){
	
}
void mouse_motion(int x, int y){
	
	glutPostRedisplay();
}*/

void OnReshape( int w, int h ){
	if( h == 0 )
		h = 1;
	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45, (float)w / h, 0.1, 100);
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
	myC.KartLocation(uKart.getX(),uKart.getY(),uKart.getZ(),uKart.getAngle());
	myC.updateLookAt();
	glColor3d( red, green, blue );
	glPushMatrix();
	glTranslatef(uKart.getX(),uKart.getY(),uKart.getZ());
	glRotatef(-90,0,1,0);
	glRotatef(angle-90,0,1,0);
	uKart.DrawKart();
	glPopMatrix();
	myTrack.draw();
	glutSwapBuffers();
}

// do nothing on exit (for now)
void OnExit(){}

// part that actually runs
int main( int argc, char** argv ){
	uKart.setAngle(angle);
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE );
	glutInitWindowSize( 640, 480 );
	glutCreateWindow( "This will become A teapot kart" );
	glutDisplayFunc( OnDraw );
	glutReshapeFunc( OnReshape );
	glEnable( GL_DEPTH_TEST );
	atexit( OnExit );
	glutIdleFunc( idle );
	glutKeyboardFunc( processNormalKeys );
	glutSpecialFunc( processSpecialKeys );
	//glutMouseFunc(mouse_button);
	//glutMotionFunc(mouse_motion);
	glutMainLoop();
	return 0;
}
