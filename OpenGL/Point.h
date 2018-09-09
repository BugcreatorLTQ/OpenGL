#ifndef POINT_H
#define POINT_H

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
	Point & operator+=(const Type & other_point);
	Point & operator-=(const Type & other_point);
	Point operator+(const Type & other_point);
	Point operator-(const Type & other_point);
	Type operator*(const Type & other_point);
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

template <typename Type>
Point<Type> & Point<Type>::operator+=(const Type & other_point)
{
	x += other_point.x;
	y += other_point.y;
	return *this;
}

template <typename Type>
Point<Type> & Point<Type>::operator-=(const Type & other_point)
{
	x -= other_point.x;
	y -= other_point.y;
	return *this;
}

template <typename Type>
Point<Type> Point<Type>::operator+(const Type & other_point)
{
	Point result;
	result.SetPoint(x + other_point.x, y + other_point.y);
	return result;
}

template <typename Type>
Point<Type> Point<Type>::operator-(const Type & other_point)
{
	Point result;
	result.SetPoint(x - other_point.x, y - other_point.y);
	return result;
}

template <typename Type>
Type Point<Type>::operator*(const Type & other_point)
{
	return x * other_point.x + y * other_point.y;
}

#endif
