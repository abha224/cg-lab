//gcc filename.c -lGL -lGLU -lglut -lm
//g++ filename.cc -lGL -lGLU -lglut -lm  //c++ 


#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1,x2,y1,y2;
 
void display(void)
{
float dy,dx,step,x,y,k,Xin,Yin;

//find difference
dx=x2-x1;
dy=y2-y1;
 
//check which difference is more and assign to step 
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);

//find increment values
Xin = dx/step;
Yin = dy/step;
 
x= x1;
y=y1;

//draw initial point
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
 
//draw other points 
for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;
 
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
 
glFlush();
}
 
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
 
int main(int argc, char** argv) 
{
	printf("Enter the value of x1 : ");
	scanf("%f",&x1);
	printf("Enter the value of y1 : ");
	scanf("%f",&y1);
	printf("Enter the value of x2 : ");
	scanf("%f",&x2);
	printf("Enter the value of y2 : ");
	scanf("%f",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("DDA Line Algo");

init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}
