#include<GL/glut.h>
#include <GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
#define ROUND(x) ((int)(x+0.5))
#include<iostream>
using namespace std;

int x1,x2,y1,y2;
void display (void)
 {
 int dx=x2-x1,dy=y2-y1,steps,k;
 float xIncrement,yIncrement,x=x1,y=y1;

 glColor3f (0.0, 1.0, 0.0);
 if(abs(dx)>abs(dy)) //Taking Modulo as done in class
    steps=abs(dx);
 else
    steps=abs(dy);

 xIncrement=dx/(float)steps;  //X inc
 yIncrement=dy/(float)steps;  //Y inc

 glBegin(GL_POINTS);
 glVertex2s(ROUND(x),ROUND(y));  //Using Round function
for(k=0;k<steps;k++)
 {
 x+=xIncrement;
 y+=yIncrement;
 glVertex2s(ROUND(x),ROUND(y));
 printf("%f %f\n",x,y);
 //cout<<x<<y<<endl;
 }
 glColor3f (1.0, 1.0, 1.0);

 glEnd();
 glFlush();
 }
 void init(void)
 {
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }

int main(int argc, char** argv)
{
 printf("Enter the points\n");
 scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (500, 500);
 glutInitWindowPosition (100, 100);
 glutCreateWindow ("DDA ");
 init ();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}

-lGL -lGLU -lglut
