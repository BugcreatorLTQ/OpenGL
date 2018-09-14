#ifndef EASYPLOT_H
#define EASYPLOT_H
#include<GL/glut.h>

///EasyPlot
namespace EasyPlot {
	void Display(void);
}

void EasyPlot::Display(void)
{
	for (GLint mod = 0; mod < 10; mod++) {
		glBegin(mod);
		for (GLint i = 0; i < 4; i++)
			glVertex2d(-0.9 + mod * 0.17 + i * 0.05, 0.2*(i & 1));
		glEnd();
	}
	glFlush();
}


#endif // !EASYPLOT_H

