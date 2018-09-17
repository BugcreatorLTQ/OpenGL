#ifndef LINE_H
#define LINE_H
#include<GL/glut.h>
#include<cmath>
#include"point.h"
#include"Window.h"

typedef GLint Type;

namespace Line{
  point<Type> start(point<Type>(0, 0));
  point<Type> end(point<Type>(0, 0));
  point<Type> step(point<Type>(0, 0));
  void Set(const point<Type> &start, const point<Type> &end); 
  Type Length();
  void Display();
  void MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y);
};

void Line::Set(const point<Type> &_start, const point<Type> &_end)
{
  start = _start; 
  end = _end;
  step = end - start;
}

Type Line::Length()
{
  return (start - end).abs();
}

void Line::Display()
{
//  Window::InitColor();
  point<Type> now_point = start;
  glBegin(GL_POINTS);
  if (step.x == 0 && step.y == 0) //No Step
    return;
  else if (step.x == 0) {   // k is endless
    do{
      glVertex2i(now_point.x, now_point.y);
      now_point.y += step.y / abs(step.y);
    } while (now_point.y != end.y);
  }
  else if (step.y == 0) {   //k is zero
    do {
      glVertex2i(now_point.x, now_point.y);
      now_point.x += step.x / abs(step.x);
    } while (now_point.x != end.x);
  }
  else if (abs(step.y / step.x) == 0) {   // |k| < 1
    Type e = -2 * abs(step.x);
    do {
      glVertex2i(now_point.x, now_point.y);
      e += 2 * abs(step.y);
      now_point.x += step.x / abs(step.x);
      if (e > 0) {
        now_point.y += step.y / abs(step.y);
        e -= 2 * abs(step.x);
      }
    } while (now_point.x != end.x);
  }
  else {    // |k| >= 1
    Type e = -2 * abs(step.y);
    do {
      glVertex2i(now_point.x, now_point.y);
      e += 2 * abs(step.x);
      now_point.y += step.y / abs(step.y);
      if (e > 0) {
        now_point.x += step.x / abs(step.x);
        e -= 2 * abs(step.y);
      }
    } while (now_point.y != end.y);
  }
  glEnd();
  glFlush();
}

void Line::MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y)
{
  if (button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN) {
    Window::InitColor();
    return;
  }
  if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
    point<Type> new_start, new_end(mouse_x, -mouse_y);
    new_start = end;
    new_end += point<Type>(-Window::size.x / 2, Window::size.y / 2);
    Set(new_start, new_end);
  }
}

#endif // !LINE_H
