#ifndef POINT_H
#define POINT_H
#include<GL/glut.h>

template <typename Type>
class Point
{
private:
	Type x, y;
public:
	Point();
	~Point();
	void SetPoint(const Type x, const Type y);
	Type X() const;
	Type Y() const;
};

template <typename Type>
Point<Type>::Point()
{
	x = y = 0;
}

template <typename Type>
Point<Type>::~Point()
{

}

template <typename Type>
void Point<Type>::SetPoint(const Type x, const Type y)
{
	this->x = x;
	this->y = y;
}

template <typename Type>
Type Point<Type>::X() const
{
	return x;
}

template <typename Type>
Type Point<Type>::Y() const
{
	return y;
}
#endif
