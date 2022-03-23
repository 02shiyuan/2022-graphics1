#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
    ///�ϯ����b������
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R G B A(���b�z���A�ثe�S�})
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�Ƥ��x�}
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);///���Y��scale��
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();

}
void keyboard(unsigned char key,int mousex,int mousey)
{

}
void mouse(int botton,int state,int mousex,int mousey)
{
    oldX=mousex; oldY=mousey;
}
void motion(int mousex,int mousey)///�ηƹ����ʯ���
{
    if((mousex-oldX)>0)scale*=1.01;
    if((mousex-oldX)<0)scale*=0.99;
    //x+=(mousex-oldX); y+=(mousey-oldY);
    oldX=mousex; oldY=mousey;
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05_keyboard_mouse_motion");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
