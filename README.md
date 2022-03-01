# 2022-graphics1
#week02
##week02_color
```
#include <GL/glut.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUAD_STRIP);
        glColor3f(1,1,1);
        glVertex2f(-4,-4);

        glColor3f(0,1,1);
        glVertex2f(-4,4);

        glColor3f(0,1,0);
        glVertex2f(0,0);

        glColor3f(1,1,0);
        glVertex2f(0,0);

        glColor3f(0,1,0);
        glVertex2f(4,-4);

        glColor3f(1,0,0);
        glVertex2f(4,4);
    glEnd();
    glutSwapBuffers();
}
int main(int argc,char ** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("第二周的程式");
    glutDisplayFunc(display);
    glutMainLoop();
}
```
