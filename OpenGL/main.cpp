#include"Line2D.h"

void InitWindows()
{
	const Point2D<GLint> size(800, 600);
	const Point2D<GLint> posi(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(size.X(), size.Y());
	glutInitWindowPosition(posi.X(), posi.Y());
	glutCreateWindow("demo");
}

void Init()
{
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 2, 150);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
}

void Display()
{
	typedef Point2D<GLint> Pt;
	Line2D<GLint> line;
	for (int i = 0; i < 10; i++) {
		line.SetLine(Pt(0, 10 + i * 10), Pt(i * 10 + 10, 0));
		line.Draw();
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
