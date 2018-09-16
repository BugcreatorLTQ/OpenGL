#include"Namespaces.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	Window::Init();
	glPointSize(5.0);
	glutDisplayFunc(LoopPoint::Display);
  LoopPoint::CreateMenu();
  Window::InitColor();
	glutMainLoop();
	return 0;
}
