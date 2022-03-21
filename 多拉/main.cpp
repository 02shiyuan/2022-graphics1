#include <GL/glut.h>
#include <math.h>

void myCircle( float x ,float y, float r )  ////���
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void myCircle1( float x ,float y, float r )  ////����
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a),y+2*r*sin(a)/1.5);
    }
    glEnd();
}
void myCircle2( float x ,float y, float r )  ////����
{
    glBegin(GL_POLYGON);
    for(float a=0; a>-3.1415926; a-=0.01){
        glVertex2f( x+2*r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void myCircle3( float x ,float y, float r )  ////�U�b���
{
    glBegin(GL_POLYGON);
    for(float a=0; a>-3.1415926; a-=0.01){
        glVertex2f( x+r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(175/255.0 ,175/255.0 ,175/255.0); ///�ǩ�
    myCircle(0,0,2);

    glColor3f(0,0,0); ///�¦��
    myCircle(0,0,1.01);
    glColor3f(40/255.0 ,175/255.0 ,236/255.0); ///�Ŧ�
    myCircle(0,0,1);

    glColor3f(0 ,0 ,0); ///����
    myCircle(0,-0.6,1.221);

    glColor3f(1 ,1 ,1); ///����
    myCircle(0,-0.6,1.2);

       glColor3f(0 ,0 ,0); ///�U����
    myCircle3(0,0,1.02);

    glColor3f(1 ,1 ,1); ///�U����
    myCircle3(0,0,1);

    glColor3f(0 ,0 ,0);///�����
    myCircle(0,0.28,0.135);

    glColor3f(1 ,0 ,0);///�����
    myCircle(0,0.28,0.125);

    glColor3f(0,0 ,0); ///��������
    myCircle1(-0.15,0.55,0.165);

    glColor3f(1,1 ,1); ///������
    myCircle1(-0.15,0.55,0.15);

    glColor3f(0,0,0); ///�����k��
    myCircle1(0.15,0.55,0.165);

    glColor3f(1,1 ,1); ///�����k
    myCircle1(0.15,0.55,0.15);

     glColor3f(0,0 ,0); ///���y��
    myCircle1(0.125,0.45,0.05);

    glColor3f(0,0,0);  ///���y�k
    myCircle1(-0.125,0.45,0.05);

    glColor3f(1,1,1);  ///���ե�
    myCircle1(0.125,0.45,0.025);

    glColor3f(1,1,1);  ///���եk
    myCircle1(-0.125,0.45,0.025);


    glColor3f(0 ,0 ,0); ///�GŽ1
    glBegin(GL_POLYGON);
    glVertex2f( 0.25, 0.1);
    glVertex2f( 0.25, 0.08);
    glVertex2f(0.9,0.25);
    glEnd();

    glColor3f(0 ,0 ,0); ///�GŽ2
    glBegin(GL_POLYGON);
    glVertex2f( 0.25, -0.03);
    glVertex2f( 0.25, -0.045);
    glVertex2f(0.9,0.02);
    glEnd();

    glColor3f(0 ,0 ,0); ///�GŽ3
    glBegin(GL_POLYGON);
    glVertex2f( 0.25, -0.17);
    glVertex2f( 0.25, -0.19);
    glVertex2f(0.9,-0.25);
    glEnd();

        glColor3f(0 ,0 ,0); ///�GŽ-1
    glBegin(GL_POLYGON);
    glVertex2f( -0.25, 0.1);
    glVertex2f( -0.25, 0.08);
    glVertex2f(-0.9,0.25);
    glEnd();

    glColor3f(0 ,0 ,0); ///�GŽ2-1
    glBegin(GL_POLYGON);
    glVertex2f( -0.25, -0.03);
    glVertex2f( -0.25, -0.045);
    glVertex2f(-0.9,0.02);
    glEnd();

    glColor3f(0 ,0 ,0); ///�GŽ3-1
    glBegin(GL_POLYGON);
    glVertex2f( -0.25, -0.17);
    glVertex2f( -0.25, -0.19);
    glVertex2f(-0.9,-0.25);
    glEnd();

    glColor3f(0,0,0); ///�L�K
    myCircle2(0,-0.3,0.42);
    glColor3f(1,1,1); ///�L�K
    myCircle2(0,-0.3,0.4);

    glColor3f(0 ,0 ,0); ///�W��
    glBegin(GL_POLYGON);
    glVertex2f(0.001,0.3);
    glVertex2f(0.015,-0.7);
    glVertex2f(0,-0.7);
    glEnd();

    glutSwapBuffers();
}

int main (int argc,char **argv)

{

    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);

    glutCreateWindow("week03");

    glutDisplayFunc(display);

    glutMainLoop();

}
