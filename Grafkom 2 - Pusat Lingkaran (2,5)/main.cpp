#include<windows.h>
#include <stdlib.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init();
void tampilan(void);
void lingkaran(void);

int window_x;
int window_y;

int xl,xp,yl,yp,rl,rp;

int window_width = 640;
int window_height = 480;

using namespace std;

int main(int argc, char **argv)
{
    awal:
    cout<<"Masukkan Nilai Jari-Jari Lingkaran: ";
    cin>>rl;
    if(rl<=0){
        cout<<"\nPerhatian . . . !\nNilai R harus R > 0\n";
        goto awal;
    }
    akhir:
    cout<<"\nMasukkan nilai X : ";
    cin>>xl;
    cout<<"Masukkan nilai Y : ";
    cin>>yl;
    if((xl >= rl) && (yl >= rl)){
        rp = rl;
        xp = xl;
        yp = yl;
    }else{
        cout<<"\nPerhatian . . !\nNilai harus X > R dan Y > R\n";
        goto akhir;
    }
    cout<<endl;

	glutInit(&argc, argv);

	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Grafkom 2 - Pusat Lingkaran P(2,5)");

	init();
	glutDisplayFunc(tampilan);
	glutMainLoop();
}

void init()
{
	glClearColor(0.0, 100.0, 0.0, 100.0);
	glColor3d(1, 1, 1);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 900.0, 0.0, 900.0);
}
void tampilan(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	lingkaran();
	glutSwapBuffers();
}

void lingkaran(void) {

	int p = 1-rp;
	int x = 0;
	int y = rp;

	glBegin(GL_POINTS);

	glVertex2i(xp,yp);
	while (x <= y) {
		if (p < 0) {
			p += 2 * x + 1;
		}
		else {
			y--;
			p += 2 * (x - y) + 1;
		}


		glVertex2i(xp + x, yp + y);
		glVertex2i(xp - x, yp + y);
		glVertex2i(xp + x, yp - y);
		glVertex2i(xp - x, yp - y);
		glVertex2i(xp + y, yp + x);
		glVertex2i(xp - y, yp + x);
		glVertex2i(xp + y, yp - x);
		glVertex2i(xp - y, yp - x);
		x++;
	}

	glEnd();
	glFlush();
}
