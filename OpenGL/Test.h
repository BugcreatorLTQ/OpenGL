#ifndef TEST_H
#define TEST_H
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include"point.h"
#include"Line.h"

typedef GLfloat DataType;
///Display
namespace Test {
  std::vector<Line> lines;
  Line now_line;
	void Display(void);
  void MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y);
  void MouseButtonMove(GLint mouse_x, GLint mouse_y);
  void Show();
}

void Test::Display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  for (auto line : lines) {
    line.Display();
  }
  Test::Show();
}


void Test::MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y)
{
  now_line.MouseButton(button, action, mouse_x, mouse_y);
  if (button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
    if (now_line.start == now_line.end)
      return;
    lines.push_back(now_line);
    glutPostRedisplay();
  }
}

void Test::MouseButtonMove(GLint mouse_x, GLint mouse_y)
{
  now_line.MouseButtonMove(mouse_x, mouse_y);
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
}

#endif // TEST_H
