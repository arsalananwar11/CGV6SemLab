#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#define PI 3.1416
GLsizei winWidth=600, winHeight=600;
GLfloat xwcmin=0,xwcmax=130,ywcmin=0,ywcmax=130;
int size, submenu;
GLint nctrlpts=4, nbezcurvepts=20;
static float theta=0;
struct wcPt3D
{
	GLfloat x,y,z;
};
struct wcPt3D ctrlpts[4]={{20,100,0},{20,110,0},{50,90,0},{60,100,0}};
typedef struct wcPt3D cp;
void drawtext(float x, float y, char *s)
{
glColor3f(0,1,0);
int i;
glRasterPos2f(x,y);
for(i=0;s[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
}
void bino(GLint n, GLint *C)
{
GLint k,j;
for(k=0;k<=n;k++)
{
C[k]=1;
for(j=n;j>=k+1;j--)
C[k]*=j;
for(j=n-k;j>=2;j--)
C[k]/=j;
}
}

void computebezpt(GLfloat u,cp *bezpt, GLint nctrlpts,cp * ctrlpts, GLint  *C)
{
GLint k,n=nctrlpts-1;
GLfloat bezblendfunc;
bezpt->x=bezpt->y=bezpt->z=0;
for(k=0;k<nctrlpts;k++)
{
bezblendfunc=C[k]*pow(u,k)*pow(1-u,n-k);
bezpt->x+=ctrlpts[k].x*bezblendfunc;
bezpt->y+=ctrlpts[k].y*bezblendfunc;
bezpt->z+=ctrlpts[k].z*bezblendfunc;
}
}

void bezier(cp *ctrlpts, GLint nctrlpts, GLint nbezcurvepts)
{
cp bezcurvept;
GLfloat u;
GLint C[nctrlpts],k;
bino(nctrlpts-1,C);
glBegin(GL_LINE_STRIP);
for(k=0;k<=nbezcurvepts;k++)
{
u=(GLfloat)k/(GLfloat)nbezcurvepts;
computebezpt(u,&bezcurvept,nctrlpts,ctrlpts, C);
glVertex2f(bezcurvept.x, bezcurvept.y);
}
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,1,1);
glPointSize(5);
glPushMatrix();
glLineWidth(5);
drawtext(30,20,"Arsalan Anwar");
drawtext(30,15,"1BI16CS025 A2");
glColor3f(1.0,153/255.0,51/255.0);
for(int i=0;i<8;i++)
{
glTranslatef(0,-0.8,0);
bezier(ctrlpts,nctrlpts,nbezcurvepts);
}
glColor3f(1,1,1);
for(int i=0;i<8;i++)
{
glTranslatef(0,-0.8,0);
bezier(ctrlpts,nctrlpts,nbezcurvepts);
}
glColor3f(19/255.0,180/255.0,8/255.0);
for(int i=0;i<8;i++)
{
glTranslatef(0,-0.8,0);
bezier(ctrlpts,nctrlpts,nbezcurvepts);
}

glPopMatrix();
glColor3f(0.7,0.5,0.3);
glLineWidth(5);
glBegin(GL_LINES);
glVertex2f(20,100);
glVertex2f(20,40);
glEnd();
glutPostRedisplay();
glutSwapBuffers();
}
void menufunc(int n)
{
switch(n)
{
case 1:
ctrlpts[1].x+=10*sin(theta*PI/180);
ctrlpts[1].y+=5*sin(theta*PI/180);
ctrlpts[2].x-=10*sin((theta+30)*PI/180);
ctrlpts[2].y-=10*sin((theta+30)*PI/180);
ctrlpts[3].x-=4*sin(theta*PI/180);
ctrlpts[3].y+=10*sin(theta*PI/180);
theta+=0.1;
break;

case 2:
ctrlpts[1].x+=10*sin(theta*PI/180);
ctrlpts[1].y-=5*sin(theta*PI/180);
ctrlpts[2].x+=10*sin((theta+30)*PI/180);
ctrlpts[2].y+=10*sin((theta+30)*PI/180);
ctrlpts[3].x+=4*sin(theta*PI/180);
ctrlpts[3].y-=10*sin(theta*PI/180);
theta+=0.1;
break;

case 3: exit(0);
}
}

void winreshapefunc(GLint newWidth, GLint newHeight)
{
glViewport(0,0, newWidth, newHeight);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(xwcmin, xwcmax,ywcmin, ywcmax);
glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
glutInitWindowSize(winWidth,winHeight);
glutInitWindowPosition(0,0);
glutCreateWindow("Arsalan's Bezier Curve");
submenu=glutCreateMenu(menufunc);
glutAddMenuEntry("Down Move",1);
glutAddMenuEntry("Up Move",2);
glutAddMenuEntry("Exit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(display);
glutReshapeFunc(winreshapefunc);
glutMainLoop();
return 0;
}
