/*
https://www.opengl.org/resources/libraries/glut/spec3/node54.html#:~:text=The%20special%20keyboard%20callback%20is,when%20the%20key%20was%20pressed
*/

 


#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

 

#include<stdio.h>

 

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

 

void processSpecialKeys( int key, int x, int y) 
{
    switch( key )
    {
        case GLUT_KEY_F1: 
            system("xrandr --prop | grep ' connected'");
            system("HDMI-A-0 connected primary 1920x1080+0+0 (normal left inverted right x axis y axis) 510mm x 287mm");
            system("xrandr --prop --verbose | grep -A10 ' connected' | grep 'Brightness'");
            system("xrandr --output HDMI-A-0 --brightness 0.4");

 

            printf("\nFunction Key F1 Pressed");
            break;
    }
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
    glutSpecialFunc(processSpecialKeys);

 

    
    glutMainLoop();            
}