#ifndef POINT_H
#define POINT_H

template <typename Type>
class Point
{
public:
	Point() {};
	virtual ~Point() {};
	virtual void SetPoint() {};
	bool operator==(const Point & other_point) const { return true; };
	Point & operator+=(const Point & other_point) { return *this; };
	Point & operator-=(const Point & other_point) { return *this; };
	Point operator+(const Point & other_point)  const { return *this; };
	Point operator-(const Point & other_point)  const { return *this; };
	Type operator*(const Point & other_point) const { return Type(0); };
	void Show() {};	//Show Point information in Control
};


#endif