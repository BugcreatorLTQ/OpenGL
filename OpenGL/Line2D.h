#ifndef LINE2D_H
#define LINE2D_H
#include<GL/glut.h>
#include "Line.h"
#include"Point2D.h"

template <typename Type>
class Line2D :public Line<Type>
{
private:
	Point2D<Type> start;
	Point2D<Type> end;
	GLint Mod;
public:
	friend void Display();
	Line2D();
	~Line2D();
	void SetLine(const Point2D<Type> & start_point, const Point2D<Type> & end_point);
	bool operator==(const Line2D & other_line) const;
	void Show() const;
	void Draw() const;	//Draw one line
};


template <typename Type>
Line2D<Type>::Line2D()
{
	Mod = GL_LINES;
	start.SetPoint(0, 0);
	end.SetPoint(0, 0);
}


template <typename Type>
Line2D<Type>::~Line2D()
{
}

template <typename Type>
void Line2D<Type>::SetLine(const Point2D<Type> & start_point, const Point2D<Type> & end_point)
{
	start = start_point;
	end = end_point;
}

template <typename Type>
bool Line2D<Type>::operator==(const Line2D & other_line) const
{
	if (start == other_line.start && end == other_line.end)
		return true;
	else
		return false;
}


template <typename Type>
void Line2D<Type>::Show() const
{
	std::cout << "[(";
	start.Show();
	std::cout << "),(";
	end.Show();
	std::cout << ")]";
}

template <typename Type>
void Line2D<Type>::Draw() const
{
	//only interge
	//glBegin(Mod);
	glVertex2i(start.X(), start.Y());
	glVertex2i(end.X(), end.Y());
	//glEnd();
}

#endif