#include"Namespaces.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
  Window::Init();
  Window::InitWin();
	glPointSize(2.0);
	glutDisplayFunc(Line::Display);
  glutMouseFunc(Line::MouseButton);
  Window::InitColor();
	glutMainLoop();
	return 0;
}
