#include"Namespaces.h"

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
  Window::DisplayMode = GLUT_DOUBLE;
  Window::Init();
  Window::InitWin();
	glPointSize(2.0);
	glutDisplayFunc(Test::Display);
  glutMouseFunc(Test::MouseButton);
  glutMotionFunc(Test::MouseButtonMove);
  Window::InitColor();
  Test::CreateMenu();
	glutMainLoop();
	return 0;
}
