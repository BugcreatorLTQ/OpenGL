#ifndef WINDOW_H
#define WINDOW_H
#include<GL/glut.h>
#include"MyTool.h"

///Window
namespace Window {
	const point<GLint> size(800, 800);
	const point<GLint> position(20, 20);
	void Init(void);
  void InitColor(void);
}

void Window::Init(void)
{
	using namespace Window;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
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

#endif // !WINDOW_H

