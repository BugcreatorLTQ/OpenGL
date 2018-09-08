#include<GL/glut.h>
#include"Point.h"

namespace LinePoint {
	Point<GLint> start;
	Point<GLint> end;
}

void Init()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
}

void Display()
{
	using LinePoint::start;
	using LinePoint::end;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2i(start.X(),start.Y());
	glVertex2i(end.X(),end.Y());
	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("demo");	
	LinePoint::start.SetPoint(100, 100);
	LinePoint::end.SetPoint(10, 300);
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();
	return 0;
}
