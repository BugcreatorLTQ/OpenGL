#ifndef R_POLYGON_H
#define R_POLYGON_H
#include<GL/glut.h>
#include<vector>
#include"MyTool.h"


typedef GLfloat DataType;

///R_Polygon
namespace R_Polygon {
	GLint count = 5;
	void SetCount(const GLint count);
	void Display(void);
}

void R_Polygon::SetCount(const GLint count)
{
	R_Polygon::count = count;
}

void R_Polygon::Display(void)
{
	typedef point<DataType> Pt;
	std::vector<Pt> points;
	glBegin(GL_LINES);
	for (GLint i = 0; i < count; i++) {
		Pt NewPoint = CirclePoint<DataType>(i, count);
		for (auto pt : points) {
			glVertex2f(pt.x, pt.y);
			glVertex2f(NewPoint.x, NewPoint.y);
		}
		points.push_back(NewPoint);
	}
	glEnd();
	glFlush();
}


#endif // !R_POLYGON_H

