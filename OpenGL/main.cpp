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

void Display()
{
	const DataType size = 0.1f;
	const GLint count = 10;
	glPointSize(4.0f);
	glLineWidth(2.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0.0, 1.0, 1.0);	//Set Point Color
	/*glBegin(GL_POINTS);
	point<GLfloat> Pt;
	for (int i = 0; i < 1000; i++) {
		Pt = Circle<GLfloat>(i, 1000);
		glVertex2i(Pt.x, Pt.y);
		glVertex2i(Pt.x - size, Pt.y + size);
	}
	glEnd();*/
	for (int i = 0; i < count; i++) {
		glColor3f(i*0.1f, i*0.1f, 1-i*0.1f);	//Change Color
		point<DataType> Pt = Circle<DataType>(i, count);	//Find Circle center
		Pt *= 0.8f;	//Shorten the radius
	glBegin(i);
		glVertex2f(Pt.x, Pt.y);	//Draw five point around the Circle
		glVertex2f(Pt.x - size, Pt.y);	
		glVertex2f(Pt.x, Pt.y + size);
		glVertex2f(Pt.x + size, Pt.y);
		glVertex2f(Pt.x, Pt.y - size);
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
