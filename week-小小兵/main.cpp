#include <GL/glut.h>
#include <math.h>
void Circle(float x,float y,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0;a<3.1415926*2;a+=0.01)
    {
        glVertex2f(x+r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void Circle2(float x,float y,float r)
{
    glBegin(GL_POLYGON);
    for(float a=0;a<3.1415926*2;a+=0.01)
    {
        glVertex2f(x+r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);
        Circle(0,0,2);

        glColor3f(0.6,0.6,0.6);
        Circle(0,0,0.6);

        glColor3f(1,1,1);
        Circle(0,0,0.45);

        glColor3f(0,0,0);
        Circle(0,0,0.3);

        glColor3f(1,0,0);
        Circle2(0.8,-0.6,0.1);
        Circle2(-0.8,-0.6,0.1);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("¤p¤p§L");

    glutDisplayFunc(display);
    glutMainLoop();
}
