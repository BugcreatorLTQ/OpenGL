#ifndef TEST_H
#define TEST_H
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<queue>
#include"point.h"
#include"Line.h"
#include"Circle.h"

enum PlotMod { T_LINE, T_CIRCLE, T_FULL };

///Display
namespace Test {
  std::vector<Line> lines;
  std::vector<Circle> circles;
  std::vector<std::vector<GLbyte>> pixel;
  Line now_line;
  Circle now_circle;
  PlotMod plot_mod = T_LINE;
  bool Flag = true;
	void Display(void);
  void MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y);
  void MouseButtonMove(GLint mouse_x, GLint mouse_y);
  void Show();
  void ProcessMenu(int value);
  void CreateMenu();
  void ReadPixel(GLint x,GLint y);
  void InitPixelArray();
  void WirtePixel();
  void Full(GLint x, GLint y);
}

void Test::Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto line : lines) {
        line.Display();
    }
    for (auto circle : circles) {
        circle.Display();
    }
    Test::Show();
}

void Test::MouseButton(GLint button, GLint action, GLint mouse_x, GLint mouse_y)
{
    static bool Flag = true;
    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN && Flag == true)
        Flag = false;
    else if (button == GLUT_LEFT_BUTTON && action == GLUT_UP && Flag == false)
        Flag = true;
    else
        return;
    if (plot_mod == T_LINE) {
        now_line.MouseButton(button, action, mouse_x, mouse_y);
        if (button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
            if (now_line.start == now_line.end)
                return;
            lines.push_back(now_line);
        }
    }
    else if (plot_mod == T_CIRCLE) {
        now_circle.MouseButton(button, action, mouse_x, mouse_y);
        if (button == GLUT_LEFT_BUTTON && action == GLUT_UP) {
            if (now_circle.R == 0)
                return;
        circles.push_back(now_circle);
        }
    }
    else if(plot_mod == T_FULL){
        Full(mouse_x, mouse_y);
    }
    glutPostRedisplay();
}

void Test::MouseButtonMove(GLint mouse_x, GLint mouse_y)
{
    if (Test::Flag == false)
    {
        Test::Flag = true;
        return;
    }
    if (plot_mod == T_LINE)
        now_line.MouseButtonMove(mouse_x, mouse_y);
    else if (plot_mod == T_CIRCLE)
        now_circle.MouseButtonMove(mouse_x, mouse_y);
}

void Test::Show()
{
    system("cls");
    int count = 0;
    for (auto line : Test::lines) {
        std::cout << "Lines: " << ++count << "\t";
        std::cout.width(10);
        std::cout << "start: " << line.start.x << "," << line.start.y << "\t";
        std::cout << "end: " << line.end.x << "," << line.end.y << std::endl;
    }
    count = 0;
    for (auto circle : circles) {
        std::cout << "Circles: " << ++count << "\t";
        std::cout.width(10);
        std::cout << "center: " << circle.Center.x << "," << circle.Center.y << "\t";
        std::cout << "R: " << circle.R << std::endl;
    }
}

void Test::ProcessMenu(int value)
{
    Test::Flag = false;
    switch (value)
    {
    case 1:
        plot_mod = T_LINE;
        break;
    case 2:
        plot_mod = T_CIRCLE;
        break;
    case 3:
        lines.clear();
        circles.clear();
        glClear(GL_COLOR_BUFFER_BIT);
        glutSwapBuffers();
        Test::Display();
        break;
    case 4:
        plot_mod = T_FULL;
        break;
    default:
        break;
    }
}

void Test::CreateMenu()
{
  glutCreateMenu(Test::ProcessMenu);
  glutAddMenuEntry("Line", 1);
  glutAddMenuEntry("Circle", 2);
  glutAddMenuEntry("Clear", 3);
  glutAddMenuEntry("Full", 4);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void Test::ReadPixel(GLint x, GLint y)
{
    x += Window::size.x / 2;
    y = Window::size.y / 2 - y;
    pixel[x][y] = 1;
}

void Test::InitPixelArray()
{
    pixel.clear();
    //set size
    pixel.resize(Window::size.x);
    for (auto &x : pixel)
    {
        x.resize(Window::size.y);
        for (auto &y : x)
            y = 0;
    }
    for (auto &x : lines)
    {
        x.Foreace(ReadPixel);
    }
    for (auto &x : circles)
    {
        x.Foreach(ReadPixel);
    }
}

void Test::WirtePixel()
{
    glColor3d(0.4, 0.2, 0.8);
    glBegin(GL_POINTS);
    for (int i = 0; i < Window::size.x; i++)
        for (int j = 0; j < Window::size.y; j++) {
            if (pixel[i][j] == 2)
                glVertex2i(i - Window::size.x / 2, Window::size.y / 2 - j);
        }

    glEnd();
    glFlush();
    Window::InitColor();
}

void Test::Full(GLint x,GLint y)
{
    InitPixelArray();
    std::queue<point<GLint>> roots;
    point<GLint> temp(x, y);
    roots.push(temp);
    while (roots.empty() == false)
    {
        temp = roots.back();
        roots.pop();
        int x = temp.x, y = temp.y;
        bool flag_up, flag_down;
        flag_up = flag_down = true;
        //move to left
        while (pixel[x][y] == 0)
            y--;
        y++;
        //foreach
        while (pixel[x][y] == 0)
        {
            pixel[x][y] = 2;
            //up
            if (flag_up ^ (pixel[x - 1][y] >= 1))
            {
                if (flag_up == true)
                {
                    temp.set(x - 1, y);
                    roots.push(temp);
                }
                flag_up = !flag_up;
            }
            //down
            else if (flag_down ^ (pixel[x + 1][y] >= 1))
            {
                if (flag_down == true)
                {
                    temp.set(x + 1, y);
                    roots.push(temp);
                }
                flag_down = !flag_down;
            }
            y++;
        }
    }
    Test::Display();
    Test::WirtePixel();
}

#endif // TEST_H
