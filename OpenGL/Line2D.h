#ifndef LINE2D_H
#define LINE2D_H
#include "Line.h"
#include"Point.h"
#include"Point2D.h"

template <typename Type>
class Line2D :public Line<Type>
{
private:
	Point2D<Type> start;
	Point2D<Type> end;
public:
	Line2D();
	~Line2D();
	void SetLine(const Point2D<Type> & start_point, const Point2D<Type> & end_point);
	bool operator==(const Line2D & other_line) const;
	void Show() const;
};


template <typename Type>
Line2D<Type>::Line2D()
{
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

#endif