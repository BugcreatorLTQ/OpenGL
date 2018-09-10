#include<GL/glut.h>

void InitWindows()
{
	glutInitWindowSize(800,600);
	glutInitWindowPosition(20,20);
	glutCreateWindow("demo");
}

void Init()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 3.0);
	glVertex2f(3.0, 3.0);
	glVertex2f(4.0, 1.5);
	glVertex2f(3.0, 0.0);
	glEnd();
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
