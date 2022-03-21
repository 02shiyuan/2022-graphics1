#include <GL/glut.h>
#include <stdio.h> ///printf()印東西用的
float mouseX=0, mouseY=0;///新加的!!!!
void myTeapot( float x , float y )
{
    glPushMatrix();///備份矩陣，他會記住舊的位置
        glTranslatef(x,y,0);
        glColor3f(1,1,0); ///黃色
        glutSolidTeapot(0.1); ///變成小茶壺
    glPopMatrix();///還原矩陣，會還原舊的位置
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot( (mouseX-150)/150.0, -(mouseY-150)/150.0);///新加的
    glutSwapBuffers();
}
void mouse( int button, int state, int x, int y ) ///滑鼠x座標,滑鼠y座標!!!!
{
    printf("%d %d %d %d\n", button, state, x, y);
    mouseX=x; mouseY=y;///新加的!!!!
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week03 移動");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加的 滑鼠事件!!!!
    glutMainLoop();
}
