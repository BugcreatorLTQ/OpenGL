#ifndef TEST_H
#define TEST_H
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include"point.h"
#include"Line.h"
#include"Circle.h"

enum PlotMod { T_LINE, T_CIRCLE };

typedef GLfloat DataType;
///Display
namespace Test {
  std::vector<Line> lines;
  std::vector<Circle> circles;
  Line now_line;
  Circle now_circle;
  PlotMod plot_mod = T_LINE;
  bool Flag = true;
	void Display(void);
  void MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y);
  void MouseButtonMove(GLint mouse_x, GLint mouse_y);
  void Show();
  void ProcessMenu(int value);
  void CreateMenu();
}

void Test::Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  for (auto line : lines) {
    line.Display();
  }
  for (auto circle : circles) {
    circle.Display();
  }
  Test::Show();
}


void Test::MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y)
{
  static bool Flag = true;
  if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN && Flag == true)
    Flag = false;
  else if (button == GLUT_LEFT_BUTTON && action == GLUT_UP && Flag == false)
    Flag = true;
  else
    return;
  if (plot_mod == T_LINE) {
    now_line.MouseButton(button, action, mouse_x, mouse_y);
    if (button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
      if (now_line.start == now_line.end)
        return;
      lines.push_back(now_line);
    }
  }
  else if (plot_mod == T_CIRCLE) {
    now_circle.MouseButton(button, action, mouse_x, mouse_y);
    if (button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
      if (now_circle.R == 0)
        return;
      circles.push_back(now_circle);
    }
  }
  glutPostRedisplay();
}

void Test::MouseButtonMove(GLint mouse_x, GLint mouse_y)
{
  if (Test::Flag == false) {
    Test::Flag = true;
    return;
  }
  if (plot_mod == T_LINE)
    now_line.MouseButtonMove(mouse_x, mouse_y);
  else if (plot_mod == T_CIRCLE)
    now_circle.MouseButtonMove(mouse_x, mouse_y);
}


void Test::Show()
{
  system("cls");
  int count = 0;
  for (auto line : Test::lines) {
    std::cout << "Lines: " << ++count << "\t";
    std::cout.width(10);
    std::cout << "start: " << line.start.x << "," << line.start.y << "\t";
    std::cout << "end: " << line.end.x << "," << line.end.y << std::endl;
  }
  count = 0;
  for (auto circle : circles) {
    std::cout << "Circles: " << ++count << "\t";
    std::cout.width(10);
    std::cout << "center: " << circle.Center.x << "," << circle.Center.y << "\t";
    std::cout << "R: " << circle.R << std::endl;
  }
}

void Test::ProcessMenu(int value)
{
  Test::Flag = false;
  switch (value)
  {
  case 1:
    plot_mod = T_LINE;
    break;
  case 2:
    plot_mod = T_CIRCLE;
    break;
  case 3:
    lines.clear();
    circles.clear();
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    Test::Display();
    break;
  default:
    break;
  }
}

void Test::CreateMenu()
{
  glutCreateMenu(Test::ProcessMenu);
  glutAddMenuEntry("Line", 1);
  glutAddMenuEntry("Circle", 2);
  glutAddMenuEntry("Clear", 3);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

#endif // TEST_H
