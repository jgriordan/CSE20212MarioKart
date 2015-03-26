#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

static float angle = 0.0,ratio;
static float x = 0.0, y = 1.75, z = 5.0;
static float lx = 0.0, ly = 0.0, lz = -1.0;
static GLint snowman_display_list;

void orientMe(float ang)
{
  lx = sin(ang);
  lz = -cos(ang);
  glLoadIdentity();
  gluLookAt(x,y,z,
		x+lx,y+ly,z+lz,
			0.0,1.0,0.0);
}

void moveMeFlat(int direction)
{
  x = x+direction*(lx)*0.1;
  z = z+direction*(lz)*0.1;
  glLoadIdentity();
  gluLookAt(x,y,z,
		x+lx,y+ly,z+lz,
			0.0,1.0,0.0);
}

void changeSize(int w, int h)
{
  // Prevent a divide by zero
  // (you can't make a window of zero width)
  if (h == 0)
    h = 1;

  float ratio = 1.0*w/h;

  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Set the viewport to be the entire window
  glViewport(0,0,w,h);

  // Set the correct perspective
  gluPerspective(45,ratio,1,1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(x,y,z,
		x+lx,y+ly,z+lz,
			0,1,0);
}

void drawSnowMan()
{
  glColor3f(1.0f,1.0f,1.0f);

  // Draw Body
  glTranslatef(0.0f,0.75f,0.0f);
  glutSolidSphere(0.75f,20,20);

  // Draw Head
  glTranslatef(0.0f,1.0f,0.0f);
  glutSolidSphere(0.25f,20,20);

  // Draw Eyes
  glPushMatrix();
  glColor3f(0.0f,0.0f,0.0f);
  glTranslatef(0.05f,0.10f,0.18f);
  glutSolidSphere(0.05f,10,10);
  glTranslatef(-0.1f,0.0f,0.0f);
  glutSolidSphere(0.05f,10,10);
  glPopMatrix();

  // Draw Nose
  glColor3f(1.0f,0.5f,0.5f);
  glRotatef(0.0f,1.0f,0.0f,0.0f);
  glutSolidCone(0.08f,0.5,10,2);
}

GLuint createDL()
{
  GLuint snowManDL;

  // Create the id for the list
  snowManDL = glGenLists(1);

  // start list
  glNewList(snowManDL,GL_COMPILE);

  // call the function that contains
  // the rendering commands
  drawSnowMan();

  // endList
  glEndList();

  return(snowManDL);
}

void initScene()
{
  glEnable(GL_DEPTH_TEST);
  snowman_display_list = createDL();
}

void renderScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw ground
  glColor3f(0.9f,0.9f,0.9f);
  glBegin(GL_QUADS);
    glVertex3f(-100.0f,0.0f,-100.0f);
    glVertex3f(-100.0f,0.0f,100.0f);
    glVertex3f(100.0f,0.0f,100.0f);
    glVertex3f(100.0f,0.0f,-100.0f);
  glEnd();

  // Draw 36 Snowmen
  for (int i = -3; i < 3; i++) {
    for (int j = -3; j < 3; j++) {
      glPushMatrix();
      glTranslatef(i*10.0,0,j*10.0);
      glCallList(snowman_display_list);
      glPopMatrix();
    }
  }
  glutSwapBuffers();
}

void inputKey(int key, int x, int y)
{
  switch (key) {
    case GLUT_KEY_LEFT:
      angle -= 0.01f;
      orientMe(angle);
      break;
    case GLUT_KEY_RIGHT:
      angle += 0.01f;
      orientMe(angle);
      break;
    case GLUT_KEY_UP:
      moveMeFlat(1);
      break;
    case GLUT_KEY_DOWN:
      moveMeFlat(-1);
      break;
  }
}

int main(int argc, char **argv) 
{
  glutInit(&argc,argv);

  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,360);
  glutCreateWindow("Snowmen");

  initScene();

  glutSpecialFunc(inputKey);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutDisplayFunc(renderScene);

  glutMainLoop();
}
