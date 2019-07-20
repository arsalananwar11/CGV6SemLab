#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
int x1,x2,y11,y2;
void myInit()
{
glClearColor(0.0,0.0,0.0,1.0);
gluOrtho2D(-500,500,-500,500);
}
void draw_pixel(int x,int y)
{

glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void draw_text(float x,float y,char *s)
{
int i;
glRasterPos2f(x,y);
for(i=0;s[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,s[i]);
}
void draw_line(int x1,int x2,int y1,int y2)
{
int dx,dy,x,y,incx,incy,inc1,inc2,e,i;
dx=x2-x1;
dy=y2-y1;
if(dx<0) dx=-dx;
if(dy<0) dy=-dy;
incx=1;
if(x2<x1) incx=-1;
incy=1;
if(y2<y1) incy=-1;
x=x1;
y=y1;
if(dx>dy)
{
	draw_pixel(x,y);
	e=2*dy-dx;
	inc1=2*(dy-dx);
	inc2=2*dy;
	for(i=0;i<dx;i++)
	{
		if(e>=0)
		{
			y+=incy;
			e+=inc1;
		}
		else
			e+=inc2;
		x+=incx;
		draw_pixel(x,y);
	}
}
else
{
	draw_pixel(x,y);
	e=2*dx-dy;
	inc1=2*(dx-dy);
	inc2=2*dx;
	for(i=0;i<dy;i++)
	{
		if(e>=0)
		{
			x+=incx;
			e+=inc1;
		}
		else
			e+=inc2;
		y+=incy;

		draw_pixel(x,y);
	}
}
}
void myDisplay()
{
int k;
glClear(GL_COLOR_BUFFER_BIT);
draw_line(x1,x2,y11,y2);
draw_line(-500,500,0,0);
draw_line(0,0,-500,500);
draw_text(300,100,"USN:1BI16CS025 NAME:ARSALAN ANWAR BATCH:A2");
draw_text(x1,y11-10,"(-40,100)");
draw_text(x2,y2-15,"(200,150)");
glFlush();
}
int main(int argc,char** argv)
{
printf("Enter the end points of line(x1,x2,y1,y2)\n");
scanf("%d%d%d%d",&x1,&x2,&y11,&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutCreateWindow("Bresenham's Line");
myInit();
glutInitWindowPosition(0,0);
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}









