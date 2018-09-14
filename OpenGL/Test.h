#ifndef TEST_H
#define TEST_H
#include<GL/glut.h>
#include<vector>
#include"MyTool.h"
typedef GLfloat DataType;
///Display
namespace Test {
	void Display(void);
}

void Test::Display(void)
{
	const GLint count = 10;
	std::vector<point<DataType>> center;
	glPointSize(4.0f);	//Set Point Size
	glLineWidth(2.0f);	//Set Line Width
	for (int i = 0; i < count; i++) {
		glColor3f(i*0.1f, i*0.1f, 1-i*0.1f);	//Change Color
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
	glFlush();
}

#endif // TEST_H
