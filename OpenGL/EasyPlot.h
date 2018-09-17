#ifndef EASYPLOT_H
#define EASYPLOT_H
#include<GL/glut.h>
#include"Point.h"
#include"Circle.h"

///EasyPlot
namespace EasyPlot {
  int index = 0;
	void Display(void);
}

void EasyPlot::Display(void)
{
  //case_1
  std::vector<point<DataType>> center;
  const GLint count = 10;
  //case_2
  //begin
  switch (index) {
  case 1:
    glPointSize(4.0f);	//Set Point Size
    glLineWidth(2.0f);	//Set Line Width
    for (int i = 0; i < count; i++) {
      glColor3f(i*0.1f, i*0.1f, 1 - i * 0.1f);	//Change Color
      point<DataType> Pt = CirclePoint<DataType>(i, count) * 0.7f;	//Outer circle
      center.push_back(Pt);
      glBegin(i);
      for (int j = 0; j < count; j++) {
        point<DataType> Ipt = Pt + CirclePoint<DataType>(j, count) * 0.17f;	//Inner circle
        glVertex2f(Ipt.x, Ipt.y);
      }
      glEnd();
    }
    glColor3i(0, 0, 0);		//Set Color Black
    glBegin(GL_LINE_LOOP);
    for (auto & x : center)
      glVertex2f(x.x, x.y);
    glEnd();
    break;
  case 2:
    //plot_2
    for (GLint mod = 0; mod < 10; mod++) {
      glBegin(mod);
      for (GLint i = 0; i < 4; i++)
        glVertex2d(-0.9 + mod * 0.17 + i * 0.05, 0.2*(i & 1));
      glEnd();
    }
    break;
  }
  glFlush();
}


#endif // !EASYPLOT_H

