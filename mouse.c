#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
 
#include<stdio.h>
int x_location = 100;
int y_location = 100;
int window_width = 800;
int window_height= 600;
void init()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 0.0f );
    glColor3f( 1,1,0);
    
    glPointSize( 25.0f );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    gluOrtho2D( 0, window_width, 0, window_height);
}
 
void MyDisplay()
{
    glClear( GL_COLOR_BUFFER_BIT );
    
    glBegin( GL_POINTS );
        
        glColor3ub(0,0,0);
        glVertex2i(x_location,y_location);
    
    glEnd();
    glFlush();
}
void mouse( int button, int state, int x, int y )
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) {
    x_location = x;
    y_location=window_height-y;
        MyDisplay();
    }
}
 
void main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    
    glutInitWindowSize( window_width,window_height );
    glutInitWindowPosition( 0,0 );
    glutCreateWindow("My Revision Window");
    
    init();
    glutDisplayFunc( MyDisplay );
    glutMouseFunc( mouse );    
        
    glutMainLoop();            
}