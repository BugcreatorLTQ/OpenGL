#include"Namespaces.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	Window::Init();
	glPointSize(5.0);
	//R_Polygon::SetCount(11);
	glutDisplayFunc(LoopPoint::Display);
	glutMouseFunc(LoopPoint::MouseButton);
  glutPassiveMotionFunc(LoopPoint::MouseMove);
  LoopPoint::CreateMenu();
  Window::InitColor();
	glutMainLoop();
	return 0;
}
