#include<GL/glut.h>
#include<iostream>
#include"MyTool.h"

typedef GLfloat DataType;

void InitWindows(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("OpenGL");
}

void Init(void)
{
	glClearColor(1, 1, 1, 1);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 1.0, 1.0);	//Set Point Color	
	const GLint count = 10;
	glPointSize(4.0f);	//Set Point Size
	glLineWidth(2.0f);	//Set Line Width
	for (int i = 0; i < count; i++) {
		glColor3f(i*0.1f, i*0.1f, 1-i*0.1f);	//Change Color
		point<DataType>Pt = Circle<DataType>(i, count) * 0.7f;	//Outer circle
		glBegin(GL_POINTS);
		glVertex2f(Pt.x, Pt.y);		//Draw Circle Center
		glEnd();
		glBegin(i);
		for (int j = 0; j < count; j++) {
			Pt += Circle<DataType>(j, count) * 0.1f;	//Inner circle
			glVertex2f(Pt.x, Pt.y);
		}
		glEnd();
	}
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	InitWindows();
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();
	return 0;
}
