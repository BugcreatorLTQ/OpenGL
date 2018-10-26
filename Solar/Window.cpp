#include "Window.h"

void Window::Init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(Width, Hight);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("LineCut");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    //Ortho2D
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, Width, 0, Hight);
}