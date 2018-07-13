#include<iostream>
#include<GL/glut.h>
using namespace std;

void Init()
{
	glClearColor(0, 0, 1, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 1);
	glRectf(50, 100, 150, 50);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Rectangular");
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();
	return 0;
}

