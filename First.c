#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

void init() {
    //same across all the program
    glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
    glColor3f(1, 1, 0);
    glPointSize(5.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1080, 0, 720); // top = 0, width = 800, bottom = 0, height = 600
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3ub(255,0,0); // r = 255, g = 0, b = 0
    glVertex2i(50,50); // x = 0, y = 0 [ bottom-left ]
    glVertex2i(250, 250);
    glEnd();
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080,720); // width = 800, height = 600
    glutInitWindowPosition(100,100); // x = 0, y = 0 [ top-left corner of screen ]
    glutCreateWindow("My Window");
    init();
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
}
/*
argc - command line operations - argument counter
argv - it will actually contain the arguments passed
*/