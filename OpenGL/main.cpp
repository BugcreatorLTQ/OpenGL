#include<GL/glut.h>
#include<vector>
#include"MyTool.h"

typedef GLfloat DataType;

void Init(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 0.0, 0.0);	//Set Point Color	)
}

///Windows
namespace Windows {
	const point<GLint> size(800, 800);
	const point<GLint> position(20, 20);
	void Init(void);
}

void Windows::Init(void)
{
	using namespace Windows;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(size.x,size.y);
	glutInitWindowPosition(position.x, position.y);
	glutCreateWindow("OpenGL");
}

///LoopPoint
namespace LoopPoint {
	point<DataType> Pt;
	point<DataType> step;
	void ChangeStep(void);
	GLboolean IsOk(void);
	void Display(void);
	void MouseButton(GLint button, GLint action, GLint x, GLint y);
}

void LoopPoint::ChangeStep(void)
{
	if (Pt.x <= -1.0f || Pt.x >= 1.0f)
		step.x = -step.x;
	if (Pt.y <= -1.0f || Pt.y >= 1.0f)
		step.y = -step.y;
	Pt += step;

}

GLboolean LoopPoint::IsOk(void)
{
	if (Pt.x > -1.0f&&Pt.x<1.0f && Pt.y>-1.0f&&Pt.y < 1.0f)
		return true;
	else
		return false;
}

void LoopPoint::Display(void)
{
	if (IsOk()) {
		Pt += step;
		Sleep(5);
		glBegin(GL_POINTS);
		glVertex2f(Pt.x, Pt.y);
		glEnd();
		glFlush();
	}
	else
		ChangeStep();
	glutPostRedisplay();
}

void LoopPoint::MouseButton(GLint button, GLint action, GLint x, GLint y)
{
	using Windows::size;
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
		point<DataType> Newstep;
		Newstep.x = 2.0f*x / size.x - 1.0f - Pt.x;
		Newstep.y = -2.0f*y / size.y + 1.0f - Pt.y;
		Newstep *= 1 / Newstep.abs();	//turn to eye vector
		step = Newstep * 0.01f;
		glutPostRedisplay();
	}
}

///R_Polygon
namespace R_Polygon {
	GLint count = 5;
	void SetCount(const GLint count);
	void Display(void);
}

void R_Polygon::SetCount(const GLint count)
{
	R_Polygon::count = count;
}

void R_Polygon::Display(void)
{
	typedef point<DataType> Pt;
	std::vector<Pt> points;
	glBegin(GL_LINES);
	for (GLint i = 0; i < count; i++) {
		Pt NewPoint = CirclePoint<DataType>(i, count);
		for (auto pt : points) {
			glVertex2f(pt.x, pt.y);
			glVertex2f(NewPoint.x, NewPoint.y);
		}
		points.push_back(NewPoint);
	}
	glEnd();
	glFlush();
}

///EasyPlot
namespace EasyPlot {
	void Display(void);
}

void EasyPlot::Display(void)
{
	glPointSize(5.0);
	for (GLint mod = 0; mod < 10; mod++) {
		glBegin(mod);
		for (GLint i = 0; i < 4; i++)
			glVertex2d(-0.9 + mod * 0.17 + i * 0.05, 0.2*(i & 1));
		glEnd();
	}
	glFlush();
}

///Display
namespace Test {
	void Display(void);
}

void Test::Display(void)
{
	const GLint count = 10;
	std::vector<point<DataType>> center;
	glPointSize(4.0f);	//Set Point Size
	glLineWidth(2.0f);	//Set Line Width
	for (int i = 0; i < count; i++) {
		glColor3f(i*0.1f, i*0.1f, 1-i*0.1f);	//Change Color
		point<DataType> Pt = CirclePoint<DataType>(i, count) * 0.7f;	//Outer circle
		center.push_back(Pt);
		glBegin(i);
		for (int j = 0; j < count; j++) {
			point<DataType> Ipt = Pt + CirclePoint<DataType>(j, count) * 0.17f;	//Inner circle
			glVertex2f(Ipt.x, Ipt.y);
		}
		glEnd();
	}
	glColor3i(0, 0, 0);		//Set Color Black
	glBegin(GL_LINE_LOOP);
	for (auto & x : center)
		glVertex2f(x.x, x.y);
	glEnd();
	glFlush();
}

///Main
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	Windows::Init();
	glPointSize(3.0);
	R_Polygon::SetCount(11);
	glutDisplayFunc(LoopPoint::Display);
	glutMouseFunc(LoopPoint::MouseButton);
	Init();
	glutMainLoop();
	return 0;
}
