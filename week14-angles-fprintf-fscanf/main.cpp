#include <GL/glut.h>
#include <stdio.h>;
float angle[20],oldx=0;
int angleID=0;///0號關節，1號關節...

FILE * fout = NULL, * fin =NULL;
void myWrite()
{
    if(fout==NULL)fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f",angle[i]);///小黑印出來
        fprintf(fout,"%.1f",angle[i]);///檔案印出來
    }
    printf("\n");///myWrite中加入，每呼叫一次，小黑視窗跳行
    fprintf(fout,"\n");///每呼叫一次，檔案跳行
}
void myRead()
{
    if(fout!=NULL){fclose(fout);fout=NULL;}
    if(fin==NULL)fin=fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}

void keyboard(unsigned char key,int x,int y)
{
    if(key=='r')myRead();
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button,int state,int x,int y)
{
    oldx=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldx);
    myWrite();
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
        glRotatef(angle[0],0,0,1);///對Z軸旋轉
        glTranslatef(-0.3,-0.4,0);///把手臂的旋轉中心，放中心
        glColor3f(1,0,0);
        glRectd(0.3,0.5,0.7,0.3);///手臂

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手臂掛回紅色手臂
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);///旋轉中心放中心
            glColor3f(0,1,0);///綠色手臂
            glRectd(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///把手臂掛回身體
        glRotatef(angle[2],0,0,1);///對Z軸旋轉
        glTranslatef(0.3,-0.4,0);///把手臂的旋轉中心，放中心
        glColor3f(1,0,0);
        glRectd(-0.3,0.5,-0.7,0.3);///手臂

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///把手臂掛回紅色手臂
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);///旋轉中心放中心
            glColor3f(0,1,0);///綠色手臂
            glRectd(-0.7,0.5,-1.0,0.3);
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
    glutKeyboardFunc(keyboard);///呼叫前面的keyboard函式

    glutMainLoop();
}
