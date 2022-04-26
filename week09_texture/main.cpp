#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()///一個程式只能有一個main函式，所以要改檔名
{
    IplImage*img=cvLoadImage("earth.jpg");
    cvShowImage("opencv",img);
    cvWaitKey(0);///也可以不用寫，因為有glutMainloop()卡住
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
    myTexture();///呼叫前面的程式
    glutMainLoop();
}
