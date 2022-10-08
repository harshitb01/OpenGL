#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include<stdio.h>

void init()
{
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );
	glColor3f( 1,1,0);
	
	glPointSize( 12.0f );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	
	gluOrtho2D( 0, 800, 0, 600);
}

void keyboard( unsigned char key, int x, int y )
{
	printf("\nKey Pressed: %c\tX: %d\tY: %d", key, x, y);
}

void MyDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glBegin( GL_POINTS );
	
		glColor3ub(0,0,0);
		glVertex2i(500,200);
	
	glEnd();
	
	glFlush();
}

void main( int argc, char **argv )
{
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	
	glutInitWindowSize( 800,600 );
	glutInitWindowPosition( 0,0 );
	glutCreateWindow("My Revision Window");
	
	init();
	glutDisplayFunc( MyDisplay );
	glutKeyboardFunc( keyboard );
	
	glutMainLoop();			
}














