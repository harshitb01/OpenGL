#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
 
#include<stdio.h>

 

int x_location = 100;
int y_location = 100;
int window_width = 800;
int window_height= 600;

 

int is_first_time = 1; // 1: yes it is first time
int n_clicks = 0; // click count initially set to 0

 

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
    if( is_first_time==1 )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        is_first_time = 0;
    }
    
    glBegin( GL_POINTS );
        
        glColor3ub(rand()%256,rand()%256,rand()%256);
        glVertex2i(rand()%window_width, rand()%window_height);
    
    glEnd();
    
    glFlush();
}

 

void mouse( int button, int state, int x, int y )
{
    int i;
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
    {
            x_location = x;
            
            y_location = window_height-y;
            
            n_clicks++;
        
        for( i=0; i<n_clicks; i++ )
         {               
                MyDisplay();
            }
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