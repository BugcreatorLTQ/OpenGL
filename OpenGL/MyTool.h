#ifndef MYTOOL_H
#define MYTOOL_H

#include<cmath>

template<typename Type>
struct point {
	Type x, y;
	point & operator*=(const Type size);
	point operator*(const Type size);
	Type operator*(const point other);
};

template<typename Type>
point<Type> & point<Type>::operator*=(const Type size) {
	x *= size;
	y *= size;
	return *this;
}

template<typename Type>
point<Type> point<Type>::operator*(const Type size) {
	point temp = *this;
	temp *= size;
	return temp;
}

template<typename Type>
Type point<Type>::operator*(const point other)
{
	return x * other.x + y * other.y;
}

template<typename Type>
point<Type> Circle(int this_count, int sum_count)
{
	const Type PI = (Type)3.1415926;
	if (sum_count <= 0)
		throw"Count Error";
	point<Type> Pt;
	Pt.x = cos(this_count * 2 * PI / sum_count);
	Pt.y = sin(this_count * 2 * PI / sum_count);
	return Pt;
}

#endif // !MYTOOL_H
//NOT DEFINE