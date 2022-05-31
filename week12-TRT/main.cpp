#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///白色茶壺當身體
    glPushMatrix();
        glTranslatef(0.2,0,0);///掛到右邊，把整個往右移動
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);///把手臂的旋轉中心移至中心
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///紅色茶壺當手臂
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12-TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();
}
