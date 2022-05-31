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
    glutPostRedisplay();///��glut���s��z
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectd(0.3,0.5,-0.3,-0.5);///����
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///����u���^����
        glRotatef(angle,0,0,1);///��Z�b����
        glTranslatef(-0.3,-0.4,0);///����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);
        glRectd(0.3,0.5,0.7,0.3);///���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///����u���^������u
            glRotatef(angle,0,0,1);
            glTranslatef(-0.7,-0.4,0);///���त�ߩ񤤤�
            glColor3f(0,1,0);///�����u
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
    glutMotionFunc(motion);///�I�s�e��motion�禡
    glutMouseFunc(mouse);///�I�s�e��mouse�禡

    glutMainLoop();
}
