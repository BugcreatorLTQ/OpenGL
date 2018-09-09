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
	//bool Is   «∑Ò∆Ω––
	friend std::ostream & operator<<(std::ostream & os, const Line & this_line);
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
std::ostream & operator<<(std::ostream & os, const Line<Type> & this_line)
{
	os << "[(" << this_line.start << "),(" << this_line.end << ")]";
	return os;
}

#endif
