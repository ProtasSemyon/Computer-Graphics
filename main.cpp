
#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void myDisplay(void);
void countTime(void(*func)(int, int, int, int), int x1, int y1, int x2, int y2);
void drawGLLine(int x1, int y1, int x2, int y2);
void drawBresenhamLine(int x1, int y1, int x2, int y2);
void drawDDALine(int x1, int y1, int x2, int y2);


int main(int argc, char **argv)
{
	setlocale(LC_ALL, "rus");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 360);
	glutInitWindowPosition(450, 5);
	glutCreateWindow("LAB_1_GUNENKOV");
	glClearColor(0.06, 0.05, 0.07, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 639, 0, 359);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}

void myDisplay()
{
	system("clear");
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	cout << "Алгоритм GLLines, с:\n";
	glBegin(GL_LINES);
	countTime(drawGLLine, 100, 100, 400, 140);
	glEnd();
	glBegin(GL_POINTS);
	glColor3f(0.0f, 1.0f, 0.0f);
	cout << "Алгоритм Брезенхейма, с:\n";
	countTime(drawBresenhamLine, 200, 100, 500, 140);
	glColor3f(1.0f, 0.0f, 1.0f);
	cout << "Алгоритм DDA, с:\n";
	countTime(drawDDALine, 300, 100, 600, 140);
	glEnd();
	glFlush();
}

void countTime(void(*func)(int, int, int, int), int x1, int y1, int x2, int y2)
{
	steady_clock::time_point start = steady_clock::now();
	for (int i = 0; i < 100000; i++)
	func(x1, y1, x2, y2);
	steady_clock::time_point finish = steady_clock::now();
	duration<double> time = finish - start;
	printf("%.11lf\n", time.count()/100000);
}

void drawGLLine(int x1, int y1, int x2, int y2)
{
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
}

void drawBresenhamLine(int x1, int y1, int x2, int y2)
{
	int x, y, dx = x2 - x1, dy = y2 - y1;
	int d = (dy << 1) - dx, d1 = dy << 1, d2 = (dy - dx) << 1;
	x = x1, y = y1;
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	x2--;
	while (x < x2)
	{
		x++;
		if (d < 0) d += d1;
		else 
		{
			y++;
			d += d2;
		}
		glVertex2i(x, y);
	}
}

void drawDDALine(int x1, int y1, int x2, int y2)
{
	float x = (float)x1, y = (float)y1;
	int dx = x2 - x1, dy = y2 - y1;
	int steps = dx > dy ? dx - 1 : dy - 1;
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	float d = (float) dy / steps;
	for (int i = 0; i < steps; i++)
	{
		x++;
		y += d;
		glVertex2i(round(x), round(y));
	}
}