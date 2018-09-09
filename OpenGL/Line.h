#ifndef LINE_H
#define LINE_H
#include"Point.h"

template <typename Type>
class Line
{
private:
	Point<Type> start;	//start point
	Point<Type> end;	//end point
	GLint Mod;		//line draw mod
public:
	Line();
	virtual ~Line();
	void SetLine(const Point<Type> & start_point, const Point<Type> & end_point);
	bool operator==(const Line & other_line) const;
	void Show() const;	//Show Line information in Control 
	void SetMod(GLint mod) { Mod = mod; };
	GLint GetMod() const { return Mod; };
};

template <typename Type>
Line<Type>::Line()
{
	Mod = GL_LINES;
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
void Line<Type>::Show() const
{
	std::cout << "[(";
	start.Show();
	std::cout << "),(";
	end.Show();
	std::cout << ")]";
}

#endif
