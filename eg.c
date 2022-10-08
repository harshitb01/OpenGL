#include<stdio.h>
#ifdef _APPLE_CC_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Clears the window and draws the torus.
int posx=4;
int posy=6;
void display() {

  glClear(GL_COLOR_BUFFER_BIT);

  // Draw a white torus of outer radius 3, inner radius 0.5 with 15 stacks
  // and 30 slices.
  glColor3f(1, 0, 0);
  glutWireTorus(0.5, 3, 15, 28);

  glFlush();
}

// Sets up global attributes like clear color and drawing color, and sets up
// the desired projection and modelview matrices.
void init() {

  // Set the current clear color to black and the current drawing color to
  // white.


  // Set the camera lens to have a 60 degree (vertical) field of view, an
  // aspect ratio of 4/3, and have everything closer than 1 unit to the
  // camera and greater than 40 units distant clipped away.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, 4.0/3.0, 1, 40);

  // Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
  // <0, 1, 0> pointing upward.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(posx, posy, 5, 0, 0, 0, 0, 1, 0);
}


void keyboard( unsigned char key, int x, int y )
{
switch(key) {
    case 'w' : posx += 10;
    break;
    case 'a' :posy += 10;
    break;
    case 's' :posx -= 10;
    break;
    case 'd' :posx -= 10;
    break;
	}
    glutPostRedisplay();
}


// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("A Moving Torus");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc( keyboard );
  glutMainLoop();
}