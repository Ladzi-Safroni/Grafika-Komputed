#include<windows.h>
#include <graphics.h>
#include <stdlib.h>
#include <graphics.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void SetPixel(int x, int y, int colors)
{
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void boundaryFill(int x, int y, int fill_color,int boundary_color)
{
        SetPixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3d(1, 0, 0);
    glVertex2f(2, 1);
    glVertex2f(3, 6);
    glVertex2f(5, 4);
    glVertex2f(8, 8);
    glVertex2f(10, 4);
    glVertex2f(12, 2);
    glVertex2f(2, 1);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(30,30);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Grafkom 2 - Boundary Fill");
    gluOrtho2D(-20., 20., -20., 20.);
    glutDisplayFunc(mydisplay);
    glutMainLoop();
    return 0;
}
