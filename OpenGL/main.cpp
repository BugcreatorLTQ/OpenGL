#include"Line2D.h"
#include<vector>

void InitWindows()
{
	const Point2D<GLint> size(800, 600);
	const Point2D<GLint> posi(20, 20);
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
	typedef Line2D<GLint> Le;
	//points
	Pt point;
	for (int i = 0; i < 5; i++) {
		point.SetPoint(1 + i, i + 1);
		point.Draw();
	}
	//lines
	Le line;
	//line.SetMod(LINES);
	for (int i = 0; i < 5; i++) {
		line.SetLine(Pt(20, 20 + i * 3), Pt(0, i * 10));
		line.Draw();
	}
	//line_stipple
	line.SetMod(LINE_STIPPLE);
	for (int i = 0; i < 5; i++) {
		line.SetLine(Pt(0, i * 20), Pt(30 * i, 0));
		line.Draw();
	}
	//line_loop
	line.SetMod(LINE_LOOP);
	for (int i = 0; i < 5; i++) {
		line.SetLine(Pt(30 + i * 20, 0), Pt(0, i * 15));
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
