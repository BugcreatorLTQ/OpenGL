#ifndef CIRCLE_H
#define CIRCLE_H
#include"Point.h"
//---------------------------------Circle---------------------------------
template<typename Type>
point<Type> CirclePoint(int this_count, int sum_count)
{
	const Type PI = (Type)3.1415926;
	if (sum_count <= 0)
		throw"Count Error";
	point<Type> Pt;
	Pt.x = cos(this_count * 2 * PI / sum_count);
	Pt.y = sin(this_count * 2 * PI / sum_count);
	return Pt;
}


#endif // !CIRCLE_H
