#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include<stdio.h>
#include<stdlib.h>

int x_point = 100, y_point = 100;

void init()
{
	glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );
	glColor3f( 1,1,0);
	
	glPointSize( 25.0f );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	
	gluOrtho2D( 0, 800, 0, 600);
}

void MyDisplay()
{
	glClear( GL_COLOR_BUFFER_BIT );

	glBegin( GL_POINTS );
	
		glColor3ub(0,0,0);
		glVertex2i(x_point, y_point);
	
	glEnd();
	
	glFlush();
}

void processSpecialKeys(int key, int x, int y) 
{
	switch(key) 
	{
		case GLUT_KEY_UP :
			y_point = y_point + 10;
			if( y_point>600 )
			{
				y_point = 0;
			}
			MyDisplay();				
			break;
	}
}

void keyboard( unsigned char key, int x, int y )
{
	if( key=='a' || key=='A' )
	{
		x_point = x_point - 10;
		if( x_point<0 )
		{
			system("poweroff");
		}
	}	
	else if( key=='w' | key=='W' )
	{
		y_point = y_point + 10;
		if( y_point>600 )
		{
			y_point = 0;
		}
		
	}
	else if( key=='d' || key=='D' )
	{
		x_point = x_point + 10;
		
		if( x_point>800 )
		{
			x_point = 0;
		}
	}
	else if( key=='x' || key=='X' )
	{
		y_point = y_point - 10;
		
		if( y_point<0 )
		{
			y_point = 600;
		}
	}
	else if( key=='q' || key=='Q' )
	{
		x_point = x_point - 10;
		y_point = y_point + 10;		
		
		
	}
	
	
	MyDisplay();

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
	glutSpecialFunc(processSpecialKeys);

	
	glutMainLoop();			
}














