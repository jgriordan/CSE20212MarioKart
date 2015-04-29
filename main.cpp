#include <cstdlib>
#include <sstream>//For displaying the text to the screen.
#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <string>
#include "Camera.h"
#include "Track1.h"
#include "Track2.h"
#include "Kart.h"
#include <SDL/SDL_mixer.h>//For the music
Camera myC;
Track * myTrack;
Kart * uKart;
Track1 myTrack1;//Two possible tracks
Track2 myTrack2;
Mix_Music *music;

float angle=90.;

int width = 960, height = 720;

// control track and kart choices
// also control flow from menus to gameplay
int trackChoice = 0;
int kartChoice = 0;

int myrandom( int m ){//generates random integer for the music to be played
	srand(time(NULL));
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
	if (kartChoice) {
		// use spacebar to activate mushroom (only during gameplay)
		if( key == 32 ){
			uKart->useShroom();
		}
	}
	if (!trackChoice) {
		if (key == 49) {
			trackChoice = 1;
			myTrack = &myTrack1;//Easy track chosen
		} else if (key == 50) {
			trackChoice = 2;
			myTrack = &myTrack2;//Hard track chosen
			
		}
	} else {//Once the track has been chosen
		if (key == 49) {
			kartChoice = 1;
			uKart = new Kart( kartChoice, myTrack, trackChoice);
			uKart->setAngle(angle);
			uKart->setInitialTime();
		} else if (key == 50) {
			kartChoice = 2;
			uKart = new Kart( kartChoice, myTrack, trackChoice);
			uKart->setAngle(angle);
			uKart->setInitialTime();
		} else if (key == 51) {
			kartChoice = 3;
			uKart = new Kart( kartChoice, myTrack, trackChoice);
			uKart->setAngle(angle);
			uKart->setInitialTime();
		}
	}
}

void processSpecialKeys( int key, int x, int y ){
	if (kartChoice) {
		switch(key){
		case GLUT_KEY_RIGHT:
			angle -= 1;//adjust the angle
			uKart->setAngle(angle);
			if( uKart->getSpeed() > 0 )//Begin slowing down for the turn.
				uKart->setSpeed( uKart->getSpeed() - 0.01 );
			else if( uKart->getSpeed() < 0 )
				uKart->setSpeed( uKart->getSpeed() + 0.01 ); 
			break;
		case GLUT_KEY_LEFT:
			angle += 1;//Update the angle.
			uKart->setAngle(angle);
			if( uKart->getSpeed() > 0 )
				uKart->setSpeed( uKart->getSpeed() - 0.01 );
			else if( uKart->getSpeed() < 0 )
				uKart->setSpeed( uKart->getSpeed() + 0.01 ); 
			break;
		case GLUT_KEY_UP:
			if( uKart->getSpeed() < 4 )//Increase the speed if the up arrow is pressed.
				uKart->setSpeed( uKart->getSpeed() + 0.04 - (uKart->getSpeed()/100) );
			break;
		case GLUT_KEY_DOWN:
			if( uKart->getSpeed() > -4 )//Reverse of the up arrow.
				uKart->setSpeed( uKart->getSpeed() - ( 0.04 + (uKart->getSpeed()/100) ) );
			break;
		}
	}
}

void OnReshape( int w, int h ){
	if( h == 0 )
		h = 1;
	glViewport( 0, 0, w, h );//Viewport is the whole screen.
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 45, (float) w / h, 0.1, 100 );
	glMatrixMode( GL_MODELVIEW );
}

void OnDraw(){
	// only perform gameplay drawing and updating if a kart has been chosen
	if (kartChoice) {
		glClear( GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
		glColor3f( 0, 1, 1 );
		glShadeModel( GL_FLAT );
		glEnable( GL_LIGHTING ); 
		glEnable( GL_LIGHT0 );
		glEnable( GL_COLOR_MATERIAL );
		float ambient[] = {1, 0, 0, 1}; 
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
		glLoadIdentity();
		if( uKart->getSpeed() > 0 )//Natural deceleration
			uKart->setSpeed( uKart->getSpeed() - 0.02 );
		else if( uKart->getSpeed() < 0 )//Natural slowing of reverse
			uKart->setSpeed( uKart->getSpeed() + 0.02 );
		uKart->setLocation( uKart->getX() - uKart->getSpeed() * cos( uKart->getAngle() ), uKart->getY(), uKart->getZ() + uKart->getSpeed() * sin( uKart->getAngle() ) );
		myC.KartLocation( uKart->getX(), uKart->getY(), uKart->getZ(), uKart->getAngle() );// set camera to behind kart
		myC.updateLookAt();// update camera drawing
		uKart->time();//Update time,lap, and check for wrong direction.
		uKart->lapFunc();
		uKart->wrongWay();
		glPushMatrix();
		glTranslatef( uKart->getX(), uKart->getY(), uKart->getZ() );// move to kart location
		glRotatef( -90, 0, 1, 0 );// rotate so the kart faces forward initially
		glRotatef( angle - 90, 0, 1, 0 );// rotate the kart to the apropriate angle
		uKart->DrawKart();
		glPopMatrix();
		myTrack->draw();

		// display lap, time, speed, and best lap time to the window
		// text is displayed to the screen using glut bitmap and updating raster position
		// this allows text to be overlayed to the screen where raster position is set to
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0,width,height,0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glColor3f(0.9,1.0,1.0);
		glRasterPos2f(10,20);		// set raster position for text
		// string stream is used to concatenate number variables with text string
		std::stringstream s;
		s << "LAP: " << uKart->getLap_n()+1;
		std::string text = s.str();
		for (int i = 0; i < text.size(); ++i) {		// loop to display each character to the screen
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
		}
		// clear strings and reset raster position
		s.str("");
		text.clear();
		glRasterPos2f(10,50);
		s << "TIME: " << (int)uKart->getLap_t();
		text = s.str();
		for (int i = 0; i < text.size(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
		}
		// clear strings and reset raster position
		s.str("");
		text.clear();
		glRasterPos2f(10,80);
		s << "SPEED: " << (int)(uKart->getSpeed()*25) << " mph";
		text = s.str();
		for (int i = 0; i < text.size(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
		}
		// clear strings and reset raster position
		s.str("");
		text.clear();
		glRasterPos2f(10,110);
		s << "BEST: " << uKart->getBestTime();
		text = s.str();
		for (int i = 0; i < text.size(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
		}
		if( uKart->getLap_t() < 5 && uKart->getBestTime() != "-" ){
			s.str("");
			text.clear();
			glRasterPos2f(10,140);
			s << "LAP TIME: " << uKart->getLastTime();//Display lap time.
			text = s.str();
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
		}
		// display wrong way to the screen if wrongWay() function returns 1
		if (uKart->wrongWay() == 1) {
			s.str("");
			text.clear();
			glRasterPos2f(10, 170);
			s << "WRONG WAY!";
			text = s.str();
			for (int i = 0; i < text.size(); ++i)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
		}
		if (uKart->getLap_n()+1==4){
			std::cout << "Best Time: "<< uKart->getBestTime() << std::endl;
			exit(0);
		}
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	// if no kart has been chosen then a menu must still be on the screen
	} else {
		// code after this displays different menus
		// WELCOME TO MARIO KART always displays
		glClear( GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT );
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0,width,height,0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glDisable(GL_LIGHTING);
		glColor3f(0.9,1.0,1.0);
		glRasterPos2f(300,300);
		std::stringstream s;
		s << "WELCOME TO MARIO KART";
		std::string text = s.str();
		for (int i = 0; i < text.size(); ++i) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
		}
		s.str("");
		text.clear();
		// if no track has been chosen yet, then the track choice menu displays
		if (!trackChoice) {
			glRasterPos2f(300,400);
			text = "Choose your track:";
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glRasterPos2f(310,430);
			text = "Easy Track - 1";//Display the track choices
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glRasterPos2f(310,460);
			text = "Hard Track - 2";
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glPopMatrix();//Update the screen
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		// if track has been chosen, then the kart choice menu displays
		} else {
			glRasterPos2f(300,400);
			text = "Choose your kart:";
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glRasterPos2f(310,430);
			text = "Teapot - 1";//Display the Kart choices
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glRasterPos2f(310,460);
			text = "Cow - 2";
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glRasterPos2f(310,490);
			text = "Snowman - 3";
			for (int i = 0; i < text.size(); ++i) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text[i]);
			}
			s.str("");
			text.clear();
			glPopMatrix();//Update the screen.
			glMatrixMode(GL_PROJECTION);
			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		}
	}
	glutSwapBuffers();
}
	
// do nothing on exit (for now)
void OnExit(){}

// part that actually runs
int main( int argc, char** argv ){
	std::string song;
	int y=myrandom(3);
	if (y==1)//Randomly pick a song to play for the ride.
		song="Heman.wav";
	else if (y==2)
		song="Nyan.wav";
	else
		song="Troll.wav";
	Mix_OpenAudio(41000,MIX_DEFAULT_FORMAT,2,4096); 
        music=Mix_LoadMUS(song.c_str());

        Mix_PlayMusic(music, -1);

	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE );
	glutInitWindowSize( width, height );
	glutCreateWindow( "Mario Kart" );//Create a window
	glutDisplayFunc( OnDraw );// the important drawing function
	glutReshapeFunc( OnReshape );
	glEnable( GL_DEPTH_TEST );
	atexit( OnExit );
	glutIdleFunc( idle );//Re display when nothing is done.
	glutKeyboardFunc( processNormalKeys );//Process the key presses.
	glutSpecialFunc( processSpecialKeys );
	glutMainLoop();
	return 0;
}
