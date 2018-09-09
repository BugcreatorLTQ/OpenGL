#ifndef LINE_H
#define LINE_H
#include"Point.h"

template <typename Type>
class Line
{
private:
	Point<Type> start;
	Point<Type> end;
public:
	Line();
	virtual ~Line();
	void SetLine(const Point<Type> & start_point, const Point<Type> & end_point);
	bool operator==(const Line & other_line) const;
	//bool Is  �Ƿ�ƽ��
	void Show();
};


template <typename Type>
Line<Type>::Line()
{
	start.SetPoint();
	end.SetPoint();
}


template <typename Type>
Line<Type>::~Line()
{
}

template <typename Type>
void Line<Type>::SetLine(const Point<Type> & start_point, const Point<Type> & end_point)
{
	start = start_point;
	end = end_point;
}

template <typename Type>
bool Line<Type>::operator==(const Line & other_line) const
{
	if (start == other_line.start && end == other_line.end)
		return true;
	else
		return false;
}

template <typename Type>
void Line<Type>::Show()
{
	std::cout << "[(";
	start.Show();
	std::cout << "),(";
	end.Show();
	std::cout << ")]";
}

#endif