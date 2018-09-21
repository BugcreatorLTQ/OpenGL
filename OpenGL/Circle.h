#ifndef CIRCLE_H
#define CIRCLE_H
#include<GL/glut.h>
#include"Point.h"

typedef GLint Type;
struct Circle {
  point<Type> Center;
  Type R;
  void Display();
  void CopyPoint(const point<Type> & now_point);
};

void Circle::Display()
{
  point<Type> now_point(0, R);
  Type e = (Type)1 - R;
  do {
    Circle::CopyPoint(now_point);
    now_point.x++;
    if (e >= 0) {
      now_point.y -= 1;   //it's not my motion
      e += 2 * (now_point.x - now_point.y) + 1;
    }
    else {
      e += 2 * now_point.x + 1;
    }
  } while (now_point.x <= now_point.y);
  Circle::CopyPoint(now_point);
  glFlush();
}

void Circle::CopyPoint(const point<Type> & now_point)
{
  glBegin(GL_POINTS);
  Type x = now_point.x, y = now_point.y;
  glVertex2i(Center.x + x, Center.y + y);
  glVertex2i(Center.y + y, Center.x + x);
  glVertex2i(Center.x + x, Center.y - y);
  glVertex2i(Center.y - y, Center.x + x);
  glVertex2i(Center.x - x, Center.y + y);
  glVertex2i(Center.y + y, Center.x - x);
  glVertex2i(Center.x - x, Center.y - y);
  glVertex2i(Center.y - y, Center.x - x);
  glEnd();
}

#endif // !CIRCLE_H
