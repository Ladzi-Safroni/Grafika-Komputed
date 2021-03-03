#include<windows.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glClearColor(10, 10, 10, 10);
	glColor3d(1, 1, 1);
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
    glutInitWindowPosition(20,20);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Grafkom 2 - Scan Line Poligon");
    gluOrtho2D(-20., 20., -20., 20.);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
