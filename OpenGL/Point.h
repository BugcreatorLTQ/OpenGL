#ifndef POINT_H
#define POINT_H
#include<iostream>

template <typename Type>
class Point
{
public:
	Point() {};
	virtual ~Point() {};
	void SetPoint() {};
	bool operator==(const Point & other_point) const { return true; };
	Point & operator+=(const Point & other_point) { return *this; };
	Point & operator-=(const Point & other_point) { return *this; };
	Point operator+(const Point & other_point)  const { return *this; };
	Point operator-(const Point & other_point)  const { return *this; };
	Type operator*(const Point & other_point) const { return Type(0); };
	friend std::ostream & operator<<(std::ostream & os, const Point & this_point);
};

template <typename Type>
std::ostream & operator<<(std::ostream & os, const Point<Type> & this_point)
{
	return os;
}

#endif