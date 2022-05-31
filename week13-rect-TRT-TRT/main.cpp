#include <GL/glut.h>
float angle=0,oldx=0;
void mouse(int button,int state,int x,int y)
{
    oldx=x;
}
void motion(int x,int y)
{
    angle+=(x-oldx);
    oldx=x;
    glutPostRedisplay();///請glut重新整理
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectd(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///把手臂掛回身體
        glRotatef(angle,0,0,1);///對Z軸旋轉
        glTranslatef(-0.3,-0.4,0);///把手臂的旋轉中心，放中心
        glColor3f(1,0,0);
        glRectd(0.3,0.5,0.7,0.3);///手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手臂掛回紅色手臂
            glRotatef(angle,0,0,1);
            glTranslatef(-0.7,-0.4,0);///旋轉中心放中心
            glColor3f(0,1,0);///綠色手臂
            glRectd(0.7,0.5,1.0,0.3);
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13-rect-TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMotionFunc(motion);///呼叫前面motion函式
    glutMouseFunc(mouse);///呼叫前面mouse函式

    glutMainLoop();
}
