#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"///在專案目錄
GLMmodel*pmodel=NULL;///指標指到模型
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL)///如果是空指標
    {
        pmodel=glmReadOBJ("Gundam.obj");///讀取模型
        glmUnitize(pmodel);///換算成Unit單位大小，-1...+1
        glmFacetNormals(pmodel);///重新計算模型的面的法向量
        glmVertexNormals(pmodel,90);///重新計算頂點的法向量
    }
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel,GLM_TEXTURE);///有模型後，畫面要記得畫貼圖
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.3;
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundamtexture");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
