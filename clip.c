#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<GL/glut.h>


double xmin=50,ymin=50,xmax=100,ymax=100;

double xvmin=200,yvmin=200,xvmax=300,yvmax=300;

const int TOP=8;
const int BOTTOM=4;
const int RIGHT=2;
const int LEFT=1;

int computeOutCode(double x,double y);
void drawtext(float x,float y,char * s)
{
	int i;
	glColor3f(0.0,0.0,1.0);
	glRasterPos2f(x,y);
	for(i=0;s[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
}

void cslClipDraw(double x0,double y0,double x1,double y1)
{
	int outcode0,outcode1,outcodeout;
	bool accept=false,done=false;
	outcode0=computeOutCode(x0,y0);
	outcode1=computeOutCode(x1,y1);
	
	do
	{
	 if((outcode0|outcode1)==0)
	 {
	  accept=true;
	  done=true;
	 }
	 else if(outcode0 & outcode1)
	 {
	  done=true;
	 }
	 else
	 { 
	  double x,y;
	  outcodeout=outcode0?outcode0:outcode1;
	  float slope=(y1-y0)/(x1-x0);
	  
	  if(outcodeout & TOP)
	  {
	   x=x0+(1/slope)*(ymax-y0);
	   y=ymax;
	  }
	  else if(outcodeout & BOTTOM)
	  {
	   x=x0+(1/slope)*(ymin-y0);
	   y=ymin;
	  }
	   else if(outcodeout & RIGHT)
	  {
	   y=y0+(slope)*(xmax-x0);
	   x=xmax;
	  }
	    else
	  {
	   y=y0+(slope)*(xmin-x0);
	   x=xmin;
	  }
	  
	  if(outcodeout==outcode0)
	  {
	   x0=x;
	   y0=y;
	   outcode0=computeOutCode(x0,y0);
	  }
	  else
	  {
	   x1=x;
	   y1=y;
	   outcode1=computeOutCode(x1,y1);
	  }
	 }
	}while(!done);
	
	if(accept)
	{
	 double sx=(xvmax-xvmin)/(xmax-xmin);
	 double sy=(yvmax-yvmin)/(ymax-ymin);
	 double vx0=xvmin+(x0-xmin)*sx;
	 double vy0=yvmin+(y0-ymin)*sy;
	 double vx1=xvmin+(x1-xmin)*sx;
	 double vy1=yvmin+(y1-ymin)*sy;
	 
	 
	    
	 glColor3f(0.0,0.0,1.0);
	 glBegin(GL_LINES);
	 glVertex2d(vx0,vy0);
	 glVertex2d(vx1,vy1);



	  
	 glEnd();
	}
	glColor3f(1.0,0.0,0.0);
	 glBegin(GL_LINE_LOOP);
	 glVertex2f(xvmin,yvmin);
	 glVertex2f(xvmax,yvmin);
	 glVertex2f(xvmax,yvmax);
	 glVertex2f(xvmin,yvmax);
	 glEnd();
}

int computeOutCode(double x,double y)
{
	 int code=0;
	 if(y>ymax)
	 	code |=TOP;
	 else if(y<ymin)
	 	code |=BOTTOM;
	  
	 if(x>xmax)
	 	code |=RIGHT;
	 else if(x<xmin)
	  	code |=LEFT;
	 return code;
 }
 
 
 void display()

{
	


	double x0=55,y0=65,x1=75,y1=95;
	double x00=75,y00=60,x01=80,y01=85;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
	glVertex2d(x0,y0);
	glVertex2d(x1,y1);
	glEnd();
	glBegin(GL_LINES);
	glVertex2d(x00,y00);
	glVertex2d(x01,y01);
	glEnd();
	  
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmax,ymin);
	glVertex2f(xmax,ymax);
	glVertex2f(xmin,ymax);
	glEnd();
  	cslClipDraw(x0,y0,x1,y1);
	cslClipDraw(x00,y00,x01,y01);
	drawtext(50,450,"USN:1BI16CS025");
	drawtext(50,425,"NAME:ARSALAN ANWAR");
	drawtext(50,400,"BATCH:A2");
  	glFlush();
}


void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

void main(int argc,char ** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");
glutDisplayFunc(display);
myinit();
glutMainLoop();
}
	
