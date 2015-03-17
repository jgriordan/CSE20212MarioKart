#include <stdlib.h>
#include <GL/glut.h>

void OnReshape( int w, int h ){
	if( h == 0 )
		h = 1;
	glViewport( 0, 0, w, h );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45, (float)w / h, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
}

void OnDraw(){
	glClear( GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
	glLoadIdentity();
	gluLookAt( 1, 1, 10, 0, 0, 0, 0, 1, 0 );
	glutWireSphere( 1, 10, 10 );
	glutSwapBuffers();
}

// do nothing on exit (for now)
void OnExit(){}

// part that actually runs
int main( int argc, char** argv ){
	glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize( 640, 480 );
	glutCreateWindow( "This will become Mario Kart" );
	glutDisplayFunc(OnDraw);
	glutReshapeFunc(OnReshape);
	glEnable( GL_DEPTH_TEST );
	atexit(OnExit);
	glutMainLoop();
	return 0;
}
