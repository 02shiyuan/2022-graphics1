#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()///�@�ӵ{���u�঳�@��main�禡�A�ҥH�n���ɦW
{
    IplImage*img=cvLoadImage("earth.jpg");
    cvShowImage("opencv",img);
    cvWaitKey(0);///�]�i�H���μg�A�]����glutMainloop()�d��
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture();///�I�s�e�����{��
    glutMainLoop();
}
