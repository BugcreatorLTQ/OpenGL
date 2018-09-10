#include<GL/glut.h>
#include"MyTool.h"

typedef GLfloat DataType;

void InitWindows()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("OpenGL");
}

void Init()
{
	glClearColor(1, 1, 1, 1);
}

void DisplayCircle()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3i(0, 0, 0);
	glPointSize(3);
	GLint count = 1000;
	point<GLfloat> Pt;
	glBegin(GL_POINTS);
	for (int i = 0; i < count; i++) {
		Pt = Circle<GLfloat>(i, count)*0.5;
		glVertex2f(Pt.x, Pt.y);
	}
	glEnd();
	glFlush();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 1.0, 1.0);	//Set Point Color	
	const DataType step = 0.1f;
	const GLint count = 10;
	glPointSize(4.0f);
	glLineWidth(2.0f);
	for (int i = 0; i < count; i++) {
		glColor3f(i*0.1f, i*0.1f, 1-i*0.1f);	//Change Color
		point<DataType>Pt = Circle<DataType>(i, count) * 0.7f;
		glBegin(i);
		for (int j = 0; j < count; j++) {
			Pt += Circle<DataType>(j, count) * 0.1f;
			glVertex2f(Pt.x, Pt.y);
		}
		glEnd();
	}
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	InitWindows();
	glutDisplayFunc(Display);
	Init();
	glutMainLoop();
	return 0;
}
