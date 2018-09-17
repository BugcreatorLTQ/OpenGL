#ifndef LOOPPOINT_H
#define LOOPPOINT_H
#include<GL/glut.h>
#include"point.h"
typedef GLfloat DataType;

///LoopPoint
namespace LoopPoint {
  bool MouseMoveFlag = false;
	point<DataType> Pt;
	point<DataType> step;
	void ChangeStep(void);
	GLboolean IsOk(void);
	void Display(void);
	void MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y);
	void MouseMove(GLint mouse_x, GLint mouse_y);
  void MouseMenu(int value);
  void CreateMenu(void);
}

void LoopPoint::ChangeStep(void)
{
	if (Pt.x <= -1.0f || Pt.x >= 1.0f)
		step.x = -step.x;
	if (Pt.y <= -1.0f || Pt.y >= 1.0f)
		step.y = -step.y;
	Pt += step;

}

GLboolean LoopPoint::IsOk(void)
{
	if (Pt.x > -1.0f&&Pt.x<1.0f && Pt.y>-1.0f&&Pt.y < 1.0f)
		return true;
	else
		return false;
}

void LoopPoint::Display(void)
{
	if (IsOk()) {
		Pt += step;
		Sleep(1);
		glBegin(GL_POINTS);
		glVertex2f(Pt.x, Pt.y);
		glEnd();
		glFlush();
	}
	else
	  ChangeStep();
  glutMouseFunc(LoopPoint::MouseButton);
  glutPassiveMotionFunc(LoopPoint::MouseMove);
	glutPostRedisplay();
}

void LoopPoint::MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y)
{
	using Window::size;
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
		point<DataType> Newstep;
		Newstep.x = 2.0f*mouse_x / size.x - 1.0f - Pt.x;
		Newstep.y = -2.0f*mouse_y / size.y + 1.0f - Pt.y;
		Newstep *= 1 / Newstep.abs();	//turn to eye vector
		step = Newstep * 0.01f;
		glutPostRedisplay();
	}
}

void LoopPoint::MouseMove(GLint mouse_x, GLint mouse_y)
{
  if (MouseMoveFlag == false)
    return;
	using Window::size;
	point<DataType> MPt;
	MPt.x = 2.0f*mouse_x / size.x - 1.0f;
	MPt.y = -2.0f*mouse_y / size.y + 1.0f;
	glBegin(GL_POINTS);
	glVertex2f(MPt.x, MPt.y);
	glEnd();
	glFlush();
}

void LoopPoint::MouseMenu(int value)
{
  switch (value) {
  case 1:MouseMoveFlag = true; break;
  case 2:MouseMoveFlag = false; break;
  case 3:step = point<DataType>(0, 0);
  default:break;
  }
}

void LoopPoint::CreateMenu(void)
{
  glutCreateMenu(LoopPoint::MouseMenu);
  glutAddMenuEntry("ON", 1);
  glutAddMenuEntry("OFF", 2);
  glutAddMenuEntry("Pause", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

#endif // !LOOPPOINT_H
