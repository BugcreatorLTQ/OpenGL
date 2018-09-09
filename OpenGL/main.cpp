#include<iostream>
#include<GL/glut.h>
#include"Point.h"
#include"Point2D.h"
#include"Point3D.h"
#include"Line.h"

namespace LinePoint {
	Point2D<GLint> start;
	Point2D<GLint> end;
	const Point2D<GLint> size(400, 200);
}

template <typename Type>
void CreateLine(const Point<Type> & start, const Point<Type> &end)
{ 
	void (* function)(Type, Type) = NULL;
	switch (Type) {
	case GLint:function = &glVertex2i; break;
	case GLfloat:function = &glVertex2f; break;
	case GLdouble:function = &glVertex2d; break;
	}
	glBegin(GL_LINES);
	function(start.X(), start.Y());
	function(end.X(), end.Y());
	glEnd();
}

void Init()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
}

void Display()
{
	using namespace LinePoint;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 10; i++) {
		start.SetPoint(size.X()/20*i, 0);
		end.SetPoint(size.X()/2 - size.X() / 20 * i, size.Y());
	}
	glFlush();
}

int main(int argc, char *argv[])
{
	using LinePoint::size;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2 * size.X(), 2 * size.Y());
	glutInitWindowPosition(500, 500);
	glutCreateWindow("demo");	
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();
	return 0;
}
