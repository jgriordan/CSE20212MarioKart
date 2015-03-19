#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
int myrandom(int m) {
 
	return rand()%m;
 
} 
void idle(){
	glClearColor((double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255, (double)myrandom(255)/255);
	glutPostRedisplay();
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
	gluPerspective( 45, (float)w / h, .1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void OnDraw(){
	static double angle = 0.0;
	glClear( GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
        angle +=  360./100000;
	int red = 1;
	int green = 1;
	int blue = 0;
	glColor3f(red, green, blue);
	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	GLdouble eyeX=20.*cos(angle);
	GLdouble eyeY=1.*sin(angle);
	GLdouble eyeZ=1.*cos(angle);
	float ambient[] = {1, 0, 0, 1}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	glLoadIdentity();
	gluLookAt( eyeX, eyeY, 5, 0, 0, 0, 0, 1, 0 );
	glutWireTeapot(1.);
	glTranslatef(-2.,0.0,-7.); //This is for drawing anoter teapot.
	glRotatef(45, 0, 1, 0);	//It got pretty tricky so I took it out.
	glutWireTeapot(1.);
	glutSwapBuffers();
}
// do nothing on exit (for now)
void OnExit(){}
// part that actually runs
int main( int argc, char** argv ){
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize( 640, 480 );
	glutCreateWindow( "This will become A teapot kart" );
	glutDisplayFunc(OnDraw);
	glutReshapeFunc(OnReshape);
	glEnable( GL_DEPTH_TEST );
	atexit(OnExit);
	glutIdleFunc(idle);
	//glutMouseFunc(mouse_button);
	//glutMotionFunc(mouse_motion);
	glutMainLoop();
	return 0;
}
