#include<iostream>
#include<GL/glut.h>

void Init()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex2i(100, 0);
		glVertex2i(0, 100);
		glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 900);
	glutInitWindowPosition(200, 180);
	glutCreateWindow("demo");
	glutDisplayFunc(Display);
	Init();	
	glutMainLoop();
	return 0;
}
