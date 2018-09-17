#ifndef LINE_H
#define LINE_H
#include<GL/glut.h>
#include<cmath>
#include"MyTool.h"

template<typename Type>
class Line{
private:
  point<Type> start, end, step;
public:
  Line(point<Type> start, point<Type>end) :start(start), end(end) { step = start - end; };
  Line() { step = start = end = point<Type>(0, 0); };
  void Display();
  void NextPoint(point<Type> const & now_point);
};

template<typename Type>
void Line<Type>::Display()
{
  point<Type> now_point = start;
  while (now_point.abs() < end.abs()) {
    glBegin(GL_POINTS);
    
    glEnd();
  }
}

template<typename Type>
void Line<Type>::NextPoint(point<Type> const & now_point)
{
  Type k = step.y / step.x;
  Type b = start.y - start.x*k;
  point<Type>temp = now_point;
  temp.x += (step.x > 0) ? 1 : -1;
  temp.y += (step.y > 0) ? 0.5 : -0.5;
  if (temp.y - k * temp.x - b > 0)
    now_point.y += (step.y > 0) ? 1 : -1;
  else
    return false;
}

#endif // !LINE_H
