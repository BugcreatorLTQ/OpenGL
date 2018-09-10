#include<GL/glut.h>
#include<vector>
#include"MyTool.h"

typedef GLfloat DataType;


void InitWindows(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("OpenGL");
}

void Init(void)
{
	glClearColor(1, 1, 1, 1);
}

void DisplayCircle()
{
	typedef point<DataType> Pt;
	std::vector<Pt> points;
	const GLint count = 11;
	glBegin(GL_LINES);
	for (GLint i = 0; i < count; i++) {
		Pt NewPoint = Circle<DataType>(i, count);
		for (auto x : points) {
			glVertex2f(x.x, x.y);
			glVertex2f(NewPoint.x, NewPoint.y);
		}
		points.push_back(NewPoint);
	}
	glEnd();
	glFlush();
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 1.0, 1.0);	//Set Point Color	
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

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	InitWindows();
	glutDisplayFunc(DisplayCircle);
	Init();
	glutMainLoop();
	return 0;
}
