#include <GL/glut.h>
#include <math.h>

void myCircle( float x ,float y, float r )  ////圓形
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void myCircle1( float x ,float y, float r )  ////橢圓形
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f( x+r*cos(a),y+2*r*sin(a)/1.5);
    }
    glEnd();
}
void myCircle2( float x ,float y, float r )  ////橢圓形
{
    glBegin(GL_POLYGON);
    for(float a=0; a>-3.1415926; a-=0.01){
        glVertex2f( x+2*r*cos(a),y+r*sin(a));
    }
    glEnd();
}
void myCircle3( float x ,float y, float r )  ////下半圓形
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

    glColor3f(175/255.0 ,175/255.0 ,175/255.0); ///灰底
    myCircle(0,0,2);

    glColor3f(0,0,0); ///黑色框
    myCircle(0,0,1.01);
    glColor3f(40/255.0 ,175/255.0 ,236/255.0); ///藍色
    myCircle(0,0,1);

    glColor3f(0 ,0 ,0); ///黑邊
    myCircle(0,-0.6,1.221);

    glColor3f(1 ,1 ,1); ///白邊
    myCircle(0,-0.6,1.2);

       glColor3f(0 ,0 ,0); ///下黑邊
    myCircle3(0,0,1.02);

    glColor3f(1 ,1 ,1); ///下白邊
    myCircle3(0,0,1);

    glColor3f(0 ,0 ,0);///紅色框
    myCircle(0,0.28,0.135);

    glColor3f(1 ,0 ,0);///紅色鼻
    myCircle(0,0.28,0.125);

    glColor3f(0,0 ,0); ///眼眶左框
    myCircle1(-0.15,0.55,0.165);

    glColor3f(1,1 ,1); ///眼眶左
    myCircle1(-0.15,0.55,0.15);

    glColor3f(0,0,0); ///眼眶右框
    myCircle1(0.15,0.55,0.165);

    glColor3f(1,1 ,1); ///眼眶右
    myCircle1(0.15,0.55,0.15);

     glColor3f(0,0 ,0); ///眼球左
    myCircle1(0.125,0.45,0.05);

    glColor3f(0,0,0);  ///眼球右
    myCircle1(-0.125,0.45,0.05);

    glColor3f(1,1,1);  ///眼白左
    myCircle1(0.125,0.45,0.025);

    glColor3f(1,1,1);  ///眼白右
    myCircle1(-0.125,0.45,0.025);


    glColor3f(0 ,0 ,0); ///鬍鬚1
    glBegin(GL_POLYGON);
    glVertex2f( 0.25, 0.1);
    glVertex2f( 0.25, 0.08);
    glVertex2f(0.9,0.25);
    glEnd();

    glColor3f(0 ,0 ,0); ///鬍鬚2
    glBegin(GL_POLYGON);
    glVertex2f( 0.25, -0.03);
    glVertex2f( 0.25, -0.045);
    glVertex2f(0.9,0.02);
    glEnd();

    glColor3f(0 ,0 ,0); ///鬍鬚3
    glBegin(GL_POLYGON);
    glVertex2f( 0.25, -0.17);
    glVertex2f( 0.25, -0.19);
    glVertex2f(0.9,-0.25);
    glEnd();

        glColor3f(0 ,0 ,0); ///鬍鬚-1
    glBegin(GL_POLYGON);
    glVertex2f( -0.25, 0.1);
    glVertex2f( -0.25, 0.08);
    glVertex2f(-0.9,0.25);
    glEnd();

    glColor3f(0 ,0 ,0); ///鬍鬚2-1
    glBegin(GL_POLYGON);
    glVertex2f( -0.25, -0.03);
    glVertex2f( -0.25, -0.045);
    glVertex2f(-0.9,0.02);
    glEnd();

    glColor3f(0 ,0 ,0); ///鬍鬚3-1
    glBegin(GL_POLYGON);
    glVertex2f( -0.25, -0.17);
    glVertex2f( -0.25, -0.19);
    glVertex2f(-0.9,-0.25);
    glEnd();

    glColor3f(0,0,0); ///嘴八
    myCircle2(0,-0.3,0.42);
    glColor3f(1,1,1); ///嘴八
    myCircle2(0,-0.3,0.4);

    glColor3f(0 ,0 ,0); ///上巴
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
