#include <GL/glut.h>
#include <stdio.h>;
float angle[20],oldx=0;
int angleID=0;///0�����`�A1�����`...

FILE * fout = NULL, * fin =NULL;
void myWrite()
{
    if(fout==NULL)fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f",angle[i]);///�p�¦L�X��
        fprintf(fout,"%.1f",angle[i]);///�ɮצL�X��
    }
    printf("\n");///myWrite���[�J�A�C�I�s�@���A�p�µ�������
    fprintf(fout,"\n");///�C�I�s�@���A�ɮ׸���
}
void myRead()
{
    if(fout!=NULL){fclose(fout);fout=NULL;}
    if(fin==NULL)fin=fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///���e�e��
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
    glutPostRedisplay();///��glut���s��z
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectd(0.3,0.5,-0.3,-0.5);///����
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///����u���^����
        glRotatef(angle[0],0,0,1);///��Z�b����
        glTranslatef(-0.3,-0.4,0);///����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);
        glRectd(0.3,0.5,0.7,0.3);///���u

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///����u���^������u
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);///���त�ߩ񤤤�
            glColor3f(0,1,0);///�����u
            glRectd(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///����u���^����
        glRotatef(angle[2],0,0,1);///��Z�b����
        glTranslatef(0.3,-0.4,0);///����u�����त�ߡA�񤤤�
        glColor3f(1,0,0);
        glRectd(-0.3,0.5,-0.7,0.3);///���u

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///����u���^������u
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);///���त�ߩ񤤤�
            glColor3f(0,1,0);///�����u
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
    glutMotionFunc(motion);///�I�s�e��motion�禡
    glutMouseFunc(mouse);///�I�s�e��mouse�禡
    glutKeyboardFunc(keyboard);///�I�s�e����keyboard�禡

    glutMainLoop();
}
