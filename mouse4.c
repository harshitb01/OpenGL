#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
 
#include<stdio.h>

 

int X1 = 300;
int Y1 = 0;

 

int X2 = 300;
int Y2 = 600;

 

int window_width = 600;
int window_height= 600;

 

int is_clicked = 0; // 0: no click
int is_first_time = 1; // 1; yes it is first time

 

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
    
    glLineWidth(5.0f);
    
    if( is_clicked==1 )
    {
        glBegin( GL_LINES );
           
           glColor3ub(rand()%256,rand()%256,rand()%256);
           glVertex2i(X1,600-Y1);
           glVertex2i(X2,600-Y2);
        
        glEnd();
    }
    else if( is_clicked>1 )
    {
        glBegin( GL_LINES );
           
           X1 = X1 + 20;
           Y1 = 0;
           X2 = X2 - 20;
           Y2 = Y2;
           
           glColor3ub(rand()%256,rand()%256,rand()%256);
           glVertex2i(X1,600-Y1);
           glVertex2i(X2,600-Y2);
        
        glEnd();
        
    }

 

        
    glFlush();
}

 

void mouse( int button, int state, int x, int y )
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
    {
          is_clicked++;

 

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