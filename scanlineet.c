#include<GL/glut.h>
#include<stdio.h>
float et[4][4]={{100,250,200,-1},{100,250,200,1},{200,150,300,1},{200,350,300,-1}};
int np=4;
float ae[4][3];
float js;
int iaet=0,ymax=0;
static int window;
static int menu_id;
static int submenu_id;
static int value=0;
void addet()
{
int i;
for(i=0;i<np;i++)
{
printf("Scanline=%f & iaet=%d\n",js,iaet);
if(js==et[i][0])
{
ae[iaet][0]=et[i][1]; 
ae[iaet][1]=et[i][2]; 
ae[iaet][2]=et[i][3]; 
if(ae[iaet][1]>ymax)
ymax=ae[iaet][1];
iaet++;
}
}
}
void upaet()
{
int i;
for(i=0;i<np;i++)
ae[i][0]=ae[i][0]+ae[i][2];
}
void draw_pixel(float x1,float x2)
{
int i;
float n;
for(n=x1;n<=x2;n++)
{
glBegin(GL_POINTS);
glVertex2f(n,js);
glEnd();
}
glFlush();
printf("x1=%f\tx2=%f\n",x1,x2);
}
void fill_poly()
{
float x[3]={0,0,0};
int i=0,j;
do{
i=0;
addet();
printf("1=%f 2=%f js=%f\n",ae[0][1],ae[1][1],js);
for(j=0;j<np;j++)
if(ae[j][1]>js)
{
x[i]=ae[j][0];
i++;
}
draw_pixel(x[0],x[1]);
upaet();
js++;
}while(js<=ymax);
}
void empty_ae()
{
js=et[0][0];
iaet=0;
}
void draw_text(int x,int y,char *s)
{
glRasterPos2f(x,y);
int i=0;
for(i=0;s[i]!='\0';i++)
{
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}
}
void display()
{
int i,j;
glClear(GL_COLOR_BUFFER_BIT);
draw_text(100,450,"USN:1BI16CS025  NAME:ARSALAN ANWAR");
switch(value)
{
case 1: return;
break;
case 2: glColor3f(1.0,0.0,0.0);
fill_poly();
empty_ae();
break;
case 3: glColor3f(0.0,1.0,0.0);
fill_poly();
empty_ae();
break;
case 4: glColor3f(0.0,0.0,1.0);
fill_poly();
empty_ae();
break;
case 5: glColor3f(1.0,1.0,0.0);
fill_poly();
empty_ae();
break;


}
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0,500.0,-500.0,500.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void menu(int num)
{
if(num==0)
{
glutDestroyWindow(window);
exit(0);
}
else
value=num;
}
void createMenu(void)
{
submenu_id=glutCreateMenu(menu);
glutAddMenuEntry("Red",2);
glutAddMenuEntry("Green",3);
glutAddMenuEntry("Blue",4);
glutAddMenuEntry("Yellow",5);
menu_id=glutCreateMenu(menu);
glutAddMenuEntry("Clear",1);
glutAddSubMenu("Color",submenu_id);
glutAddMenuEntry("Quit",0);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc,char** argv)
{
js=et[0][0];
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Polygon Filling Algorithm");
createMenu();
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
