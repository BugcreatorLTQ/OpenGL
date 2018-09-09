#ifndef POINT2D_H
#define POINT2D_H
#include"Point.h"

template <typename Type>
class Point2D:Point<Type>
{
private:
	Type x, y;
public:
	Point2D();
	Point2D(const Type x, const Type y);
	~Point2D();
	void SetPoint(const Type x, const Type y);
	Type X() const;
	Type Y() const;
	Point2D & operator+=(const Point2D & other_point);
	Point2D & operator-=(const Point2D & other_point);
	Point2D operator+(const Point2D & other_point) const;
	Point2D operator-(const Point2D & other_point) const;
	Type operator*(const Point2D & other_point) const;
};

template <typename Type>
Point2D<Type>::Point2D()
{
	x = y = 0;
}

template <typename Type>
Point2D<Type>::Point2D(const Type x, const Type y)
{
	this->SetPoint(x, y);
}

template <typename Type>
Point2D<Type>::~Point2D()
{

}

template <typename Type>
void Point2D<Type>::SetPoint(const Type x, const Type y)
{
	this->x = x;
	this->y = y;
}

template <typename Type>
Type Point2D<Type>::X() const
{
	return x;
}

template <typename Type>
Type Point2D<Type>::Y() const
{
	return y;
}

template <typename Type>
Point2D<Type> & Point2D<Type>::operator+=(const Point2D & other_point)
{
	x += other_point.x;
	y += other_point.y;
	return *this;
}

template <typename Type>
Point2D<Type> & Point2D<Type>::operator-=(const Point2D & other_point)
{
	x -= other_point.x;
	y -= other_point.y;
	return *this;
}

template <typename Type>
Point2D<Type> Point2D<Type>::operator+(const Point2D & other_point) const
{
	Point2D result;
	result.SetPoint(x + other_point.x, y + other_point.y);
	return result;
}

template <typename Type>
Point2D<Type> Point2D<Type>::operator-(const Point2D & other_point) const
{
	Point2D result;
	result.SetPoint(x - other_point.x, y - other_point.y);
	return result;
}

template <typename Type>
Type Point2D<Type>::operator*(const Point2D & other_point) const
{
	return x * other_point.x + y * other_point.y;
}

#endif
