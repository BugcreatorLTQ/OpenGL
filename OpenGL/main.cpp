#include"Namespaces.h"

void Display()
{
  Circle circle;
  circle.Center.set(0, 0);
  circle.R = 100;
  circle.Display();
  glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
  //Window::DisplayMode = GLUT_DOUBLE;
  Window::Init();
  Window::InitWin();
	glPointSize(2.0);
  glutDisplayFunc(Display);
	//glutDisplayFunc(Test::Display);
 // glutMouseFunc(Test::MouseButton);
 // glutMotionFunc(Test::MouseButtonMove);
  Window::InitColor();
	glutMainLoop();
	return 0;
}
