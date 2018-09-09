#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"

template <typename Type>
class Point3D : public Point2D<Type>
{
private:
	Type z;
public:
	Point3D();
	Point3D(const Type x, const Type y, const Type z);
	~Point3D();
	void SetPoint(const Type x = 0, const Type y = 0, const Type z = 0);
	Type Z() const;
	bool operator==(const Point3D & other_point) const;
	Point3D & operator+=(const Point3D & other_point);
	Point3D & operator-=(const Point3D & other_point);
	Point3D operator+(const Point3D & other_point) const;
	Point3D operator-(const Point3D & other_point) const;
	Type operator*(const Point3D & other_point) const;
	void Show();
};



template <typename Type>
Point3D<Type>::Point3D()
{
	z = 0;
}

template <typename Type>
Point3D<Type>::Point3D(const Type x, const Type y, const Type z)
{
	this->SetPoint(x, y, z);
}

template <typename Type>
Point3D<Type>::~Point3D()
{

}


template <typename Type>
void Point3D<Type>::SetPoint(const Type x, const Type y, const Type z)
{
	Point2D<Type>::SetPoint(x, y);
	this->z = z;
}

template <typename Type>
Type Point3D<Type>::Z() const
{
	return z;
}

template <typename Type>
bool Point3D<Type>::operator==(const Point3D<Type> & other_point) const
{
	if (Point2D<Type>::operator==(other_point) && z = other_point.z)
		return true;
	else
		return false;
}

template <typename Type>
Point3D<Type> & Point3D<Type>::operator+=(const Point3D & other_point)
{
	Point2D<Type>::operator+=(other_point);
	z += other_point.z;
	return *this;
}

template <typename Type>
Point3D<Type> & Point3D<Type>::operator-=(const Point3D & other_point)
{
	Point2D<Type>::operator-=(other_point);
	z -= other_point.z;
	return *this;
}

template <typename Type>
Point3D<Type> Point3D<Type>::operator+(const Point3D & other_point) const
{
	Point3D<Type> result;
	result = Point2D<Type>::operator+(other_point);
	result.z = z + other_point.z;
	return result;
}

template <typename Type>
Point3D<Type> Point3D<Type>::operator-(const Point3D & other_point) const
{
	Point3D<Type> result;
	result = Point2D<Type>::operator-(other_point);
	result.z = z - other_point.z;
	return result;
}

template <typename Type>
Type Point3D<Type>::operator*(const Point3D<Type> & other_point) const
{
	Type result = Point2D<Type>::operator*(other_point);
	result += z * other_point.z;
	return result;
}

template <typename Type>
void Point3D<Type>::Show()
{
	Point2D::Show();
	std::cout << ',' << z;
}

#endif