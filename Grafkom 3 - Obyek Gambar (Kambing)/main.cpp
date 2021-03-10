#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

const double PI = 3.141592653589793;
int i;

void end()
{
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex2d(-150,150);
    glVertex2d(150,150);
    glVertex2d(150,-150);
    glVertex2d(-150,-150);
    glEnd();
}

void kaki_kiri()
{
    glBegin (GL_POLYGON);
    glVertex2f (-3.0f, -14.5f);
    glVertex2f (-3.0f, -11.0f);
    glVertex2f (-2.0f, -11.0f);
    glVertex2f (-2.0f, -14.5f);
    glEnd ();
}

void kaki_kanan()
{
    glBegin (GL_POLYGON);
    glVertex2f (3.0f, -14.5f);
    glVertex2f (3.0f, -11.0f);
    glVertex2f (2.0f, -11.0f);
    glVertex2f (2.0f, -14.5f);
    glEnd ();

}

void ellips(float rx, float ry, float xc, float yc, int n)
{
	glBegin( GL_POLYGON);
            double t;
            for  (int i=0;  i < n;  ++i)
            {
                t = i * 2.0 * 3.14159 / n;
                glVertex2f( rx*cos(t)+xc, ry*sin(t)+yc );
            }
  	glEnd();
}

void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah)
{
    glBegin(GL_POLYGON);
    for (i=0;i<=360;i++)
        {
            float sudut=i*(2*PI/jumlah_titik);
            float x=x_tengah+radius*cos(sudut);
            float y=y_tengah+radius*sin(sudut);
            glVertex2f(x,y);
        }
    glEnd();
}

void tampilan()
{
    glClear(GL_COLOR_BUFFER_BIT);
    end();
    glColor3f (0.0, 0.0, 1.0); //warna kaki_kanan dan kaki_kiri
    kaki_kiri(); //kaki kiri
    kaki_kanan(); //kaki kanan
    glColor3f(0.0, 0.0, 1.0); //warna badan
    lingkaran(10.0,70.0,0.0,-2.0); //badan
    glColor3f(1.0, 1.0, 1.0); //warna kepala bagian dalam
    ellips(-4.30,8.30,0.0,4.0,40.20); //kepala bagian dalam
    glColor3f(0.0, 0.0, 1.0); //warna kepala bagian luar
    ellips(-4.10,8.20,0.0,4.0,40.20); //kepala bagian luar
    glColor3f(1.0, 0.0, 0.0); //warna mulut
    ellips(1.15,1.15,0.0,-1.15,36.0); //mulut
    glColor3f(1.0, 1.0, 1.0); //warna mata kanan
    ellips(1.0,-2.0,2.0,5.0,25.0); //mata kanan
    glColor3f(1.0, 1.0, 1.0); //warna mata kiri
    ellips(1.0,-2.0,-2.0,5.0,25.0); //mata kiri
    glColor3f(0.0, 0.0, 1.0);//warna telinga kanan
    ellips(-1.30,0.3,4.0,9.0,25.0);//telinga kanan
    glColor3f(0.0, 0.0, 1.0);//warna telinga kiri
    ellips(-1.30,0.3,-4.0,9.0,11.0);//telinga kiri
    glColor3f(2.6,0.3,0.4);//warna retina mata kanan
    ellips(0.5,-1.15,2.0,4.4,10.0); //retina mata kanan
    glColor3f(2.6,0.3,0.4);//warna retina mata kiri
    ellips(0.5,-1.15,-2.0,4.4,10.0); //retina mata kiri
    glColor3f(1.0, 0.0, 0.0); //warna hidung kiri
    ellips(0.15,0.15,-0.3,1.3,25.0); //hidung kiri
    glColor3f(1.0, 0.0, 0.0); //warna hidung kanan
    ellips(0.15,0.15,0.3,1.3,25.0);//hidung kanan
    glColor3f(0.0, 0.0, 0.0);//warna tanduk kanan
    ellips(0.30,-1.30,1.60,13.0,10.0); // tanduk kanan
    glColor3f(0.0, 0.0, 0.0);//warna tanduk kiri
    ellips(0.30,-1.30,-1.60,13.0,10.0);//tanduk kiri
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("Grafkom 3 - Obyek Gambar");
    gluOrtho2D(-15., 15., -15., 15.);
    glutDisplayFunc(tampilan);
    glutMainLoop();
    return 0;
}
