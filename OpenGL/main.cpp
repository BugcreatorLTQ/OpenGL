#include<GL/glut.h>
#include<vector>
#include"MyTool.h"

typedef GLfloat DataType;

//--------------------------------LoopPoint------------------------------
namespace LoopPoint {
	point<DataType> Pt;
	point<DataType> step;
	void ChangeStep(void) {
		if (Pt.x <= -1.0f || Pt.x >= 1.0f)
			step.x = -step.x;
		if (Pt.y <= -1.0f || Pt.y >= 1.0f)
			step.y = -step.y;
		Pt += step;
	}
	GLboolean IsOk(void) {
		if (Pt.x > -1.0f&&Pt.x<1.0f && Pt.y>-1.0f&&Pt.y < 1.0f)
			return true;
		else
			return false;
	}
}

//--------------------------------Mouse-------------------------------
namespace Mouse {
	point<DataType> Pstart;
	point<DataType> Pend;
}

//-------------------------------Windows------------------------------
namespace Windows {
	const point<GLint> size(800, 800);
	const point<GLint> position(20, 20);
}

void InitWindows(void)
{
	using namespace Windows;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(size.x,size.y);
	glutInitWindowPosition(position.x, position.y);
	glutCreateWindow("OpenGL");
}

void Init(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 0.0, 0.0);	//Set Point Color	
}

void DisplayCircle()
{
	typedef point<DataType> Pt;
	std::vector<Pt> points;
	const GLint count = 11;
	glBegin(GL_LINES);
	for (GLint i = 0; i < count; i++) {
		Pt NewPoint = Circle<DataType>(i, count);
		for (auto pt : points) {
			glVertex2f(pt.x, pt.y);
			glVertex2f(NewPoint.x, NewPoint.y);
		}
		points.push_back(NewPoint);
	}
	glEnd();
	glFlush();
}

void DisplayEasy(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	for (GLint mod = 0; mod < 10; mod++) {
		glBegin(mod);
		for (GLint i = 0; i < 4; i++)
			glVertex2d(-0.9 + mod * 0.17 + i * 0.05, 0.2*(i & 1));
		glEnd();
	}
	glFlush();
}

void MouseButton(GLint button,GLint action,GLint x,GLint y)
{
	using Windows::size;
	using namespace Mouse;
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
		Pstart = Pend;
		Pend.x = 2.0f*x / size.x;
		Pend.y = -2.0f*y / size.y;
		Pend += point<DataType>(-1, 1);
		glutPostRedisplay();
	}
}

void DisplayMouse(void)
{
	using namespace Mouse;
	glBegin(GL_LINES);
	glVertex2f(Pstart.x, Pstart.y);
	glVertex2f(Pend.x, Pend.y);
	glEnd();
	glFlush();
}

void Display(void)
{
	const GLint count = 10;
	std::vector<point<DataType>> center;
	glPointSize(4.0f);	//Set Point Size
	glLineWidth(2.0f);	//Set Line Width
	for (int i = 0; i < count; i++) {
		glColor3f(i*0.1f, i*0.1f, 1-i*0.1f);	//Change Color
		point<DataType> Pt = Circle<DataType>(i, count) * 0.7f;	//Outer circle
		center.push_back(Pt);
		glBegin(i);
		for (int j = 0; j < count; j++) {
			point<DataType> Ipt = Pt + Circle<DataType>(j, count) * 0.17f;	//Inner circle
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

void LoopPoints(void)
{
	using namespace LoopPoint;
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

void MouseVector(GLint button, GLint action, GLint x, GLint y)
{
	using Windows::size;
	using LoopPoint::Pt;
	if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
		point<DataType> Newstep;
		Newstep.x = 2.0f*x / size.x - 1.0f - Pt.x;
		Newstep.y = -2.0f*y / size.y + 1.0f - Pt.y;
		Newstep *= 1 / Newstep.abs();	//turn to eye vector
		LoopPoint::step = Newstep * 0.01f;
		glutPostRedisplay();
	 }
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	InitWindows();
	glPointSize(3.0);
	glutDisplayFunc(LoopPoints);
	glutMouseFunc(MouseVector);
	Init();
	glutMainLoop();
	return 0;
}
