#ifndef POINT_H
#define POINT_H

template <typename Type>
class Point
{
public:
	Point() {};
	virtual ~Point() {};
	virtual void SetPoint() {};
	virtual Point & operator+=(const Point & other_point) { return *this; };
	virtual Point & operator-=(const Point & other_point) { return *this; };
	virtual Point operator+(const Point & other_point)  const { return *this; };
	virtual Point operator-(const Point & other_point)  const { return *this; };
	Type operator*(const Point & other_point) const { return Type(0); };
};

#endif