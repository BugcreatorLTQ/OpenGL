#ifndef WINDOW_H
#define WINDOW_H
#include<GL/glut.h>
#include"Point.h"

///Window
namespace Window {
	const point<GLint> size(800, 800);
	const point<GLint> position(20, 20);
  GLint DisplayMode = GLUT_SINGLE;
	void Init(void);
  void InitWin(void);
  void InitColor(void);
}

void Window::Init(void)
{
  glutInitDisplayMode(DisplayMode | GLUT_RGB);
	glutInitWindowSize(size.x,size.y);
	glutInitWindowPosition(position.x, position.y);
	glutCreateWindow("OpenGL");
}

void Window::InitColor(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 0.0, 0.0);	//Set Point Color	)
}

void Window::InitWin()
{
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-size.x / 2, size.x / 2, -size.y / 2, size.y / 2);
}

#endif // !WINDOW_H

