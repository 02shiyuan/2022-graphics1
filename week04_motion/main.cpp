#include <GL/glut.h>
float angle=0,oldX=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份矩陣 (備份舊的地址)
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();
    glutSwapBuffers();///還原矩陣(還原舊地址)
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    display();///重畫畫面
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;///定錨
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);///week03 滑鼠 按下放開
    glutMainLoop();
}
