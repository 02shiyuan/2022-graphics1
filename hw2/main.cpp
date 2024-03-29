#include <GL/glut.h>
#include <math.h>
void myCircle( float x , float y ,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a) , y+r*sin(a) );
    }
    glEnd();
}
void myCircle2( float x , float y ,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a) , y+1.5*r*sin(a) );
    }
    glEnd();
}
void myCircle3( float x , float y ,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+1.5*r*cos(a) , y+r*sin(a) );
    }
    glEnd();
}
void display()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1 , 1 , 1);
    myCircle(0,0,2);

    glColor3f(1, 1 , 0);
    myCircle3(0.00, 0.00, 0.05);

    glColor3f(252/255.0 , 185/255.0 , 216/255.0);
    myCircle3(0.4,0.1,0.05);
    myCircle3(-0.4,0.1,0.05);

    glColor3f(0 , 0 ,0);
    myCircle2(0.35, 0.3 ,0.1);
    myCircle2(-0.35, 0.3 ,0.1);


    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 �@�~");
    glutDisplayFunc(display);
    glutMainLoop();
}
