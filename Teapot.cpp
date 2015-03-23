#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
#include "Camera.h"

static GLdouble eyeX=5;
static GLdouble eyeY=10;
static GLdouble eyeZ=5;
static double angle=0;

Camera myC;

int red = 1;
int green = 0;
int blue = 0;

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
                        angle += (float)360/1000; //Someone figure out the camera
                        eyeZ = eyeZ + sin(angle);
                        red = 0.0;
                        blue = 1.0;
			green = 0.0;
                        break;
                case GLUT_KEY_LEFT:
                        angle -= 360./1000; //Please!!!
                        eyeZ -= sin(angle);
			red = 0.0;
                        blue = 0.0;
                        green = 1.0;
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
	//gluLookAt( eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0 ); // moved to Camera class
	myC.updateLookAt();
	glutSolidTeapot(1);
	//glTranslatef(-2.,0.0,-7.); //This is for drawing anoter teapot.
	//glRotatef(45, 0, 1, 0);	//It got pretty tricky so I took it out.
	//glutWireTeapot(1.);
	glutSwapBuffers();
}

// do nothing on exit (for now)
void OnExit(){}

// part that actually runs
int main( int argc, char** argv ){
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
