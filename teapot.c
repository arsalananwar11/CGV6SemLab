#include<stdio.h>
#include<GL/glut.h>

GLfloat mat_ambient[]={0.7,0.7,1.0};
GLfloat mat_diffuse[]={0.5,0.5,1.0};
GLfloat mat_specular[]={1.0,1.0,1.0};
const GLfloat mat_shininess[]={50.0};
GLfloat light_intensity[]={0.7,0.7,1.0};
GLfloat light_position[]={2.0,6.0,3.0,0.0};

void init()
{
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
glLightfv(GL_LIGHT0,GL_POSITION,light_position);
glLightfv(GL_LIGHT0,GL_DIFFUSE,light_intensity);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(2.0,1.0,2.0,0.0,0.2,0.2,0.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void teapot()
{
//GLfloat mat_ambient[]={1.0,0.0,0.0};
GLfloat mat_diffuse[]={1.0,1.0,0.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
//glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glPushMatrix();
glTranslated(0.4,0.0,0.4);
glRotated(30,0,1,0);
glutSolidTeapot(0.2);
glPopMatrix();
}

void tabletop()
{
GLfloat mat_diffuse[]={1.0,0.0,0.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(0.0,-0.3,0.0);
glScaled(7.0,0.5,7.0);
glutSolidCube(0.2);
glPopMatrix();
}

void frontleg()
{
GLfloat mat_diffuse[]={1.0,0.0,0.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(0.5,-0.7,0.5);
glScaled(0.5,7.0,0.5);
glutSolidCube(0.1);
glPopMatrix();
}

void leftleg()
{
glPushMatrix();
glTranslated(-0.5,-0.7,0.5);
glScaled(0.5,7.0,0.5);
glutSolidCube(0.1);
glPopMatrix();
}

void rightleg()
{
glPushMatrix();
glTranslated(0.5,-0.7,-0.5);
glScaled(0.5,7.0,0.5);
glutSolidCube(0.1);
glPopMatrix();
}

void backleg()
{
glPushMatrix();
glTranslated(-0.5,-0.7,-0.5);
glScaled(0.5,7.0,0.5);
glutSolidCube(0.1);
glPopMatrix();
}

void leftwall()
{
GLfloat mat_diffuse[]={0.0,1.0,0.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(-1.0,-0.0,0.0);
glScaled(0.1,30.0,20.0);
glutSolidCube(0.2);
glPopMatrix();
}

void bottomfloor()
{
GLfloat mat_diffuse[]={0.0,1.0,1.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(0.0,-1.0,0.0);
glScaled(50.0,0.1,50.0);
glutSolidCube(0.2);
glPopMatrix();
}
void floormat()
{
GLfloat mat_diffuse[]={1.0,0.0,1.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(0.2,-1.0,0.2);
glScaled(10.0,0.2,10.0);
glutSolidCube(0.2);
glPopMatrix();
}

void rightwall()
{
GLfloat mat_diffuse[]={0.0,1.0,0.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(0.0,0.0,-1.0);
glScaled(20.0,30.0,0.1);
glutSolidCube(0.2);
glPopMatrix();
}

void rightwallframe()
{
GLfloat mat_diffuse[]={0.3,8.1,1.0};

glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glPushMatrix();
glTranslated(0.5,1.0,-0.5);
glScaled(5.0,5.0,0.0);
glutSolidCube(0.2);
glPopMatrix();
}
void display()
{
init();
teapot();
tabletop();
frontleg();
leftleg();
rightleg();
backleg();
floormat();
rightwallframe();
bottomfloor();
rightwall();
leftwall();
glFlush();
}

void main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowPosition(50,50);
glutInitWindowSize(400,300);
glutCreateWindow("Shaded Scene");
glutDisplayFunc(display);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glEnable(GL_NORMALIZE);
glClearColor(0.1,0.1,0.1,0.0);
glViewport(0,0,640,480);
glutMainLoop();
}








