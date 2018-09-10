#include"Line2D.h"
#include<vector>

void InitWindows()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("demo");
}

void Init()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
}



void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//for (GLint i = 0; i < 10; i++) {
	//	glBegin(i);
	//	for (GLint j = 0; j < 5; j++) {
	//		GLfloat x, y;
	//		x = j * 0.1f;
	//		y = 1.0f - x;
	//		glVertex2f(x,y);
	//	}
	//	glEnd();
	//}
	glColor4f(0.2, 0.6, 1.0, 1.0);		//图形绘制颜色
	glRotatef(40.0, -40.0, -20.0, 1.0);	//设置旋转
	glutWireTeapot(0.5);		//绘制线模型模式茶壶
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

