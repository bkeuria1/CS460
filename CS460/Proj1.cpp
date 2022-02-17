#include <Windows.h>
#include <vector>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <freeglut.h>
#include <cmath>  

struct line {
	int x1, y1;
	int x2, y2;
};
std::vector<std::pair<int,int>> points;
std::pair<int, int> basePoint;
std::vector<line>lines;
int vector_index =0;
bool done_drawing = false;
void bresenham(int x1, int y1 , int x2, int y2);
void setPixels(int x, int y);



void bresenham(int x1, int y1, int x2, int y2) {
	int dx = std::abs(x2 - x1);
	int dy = std::abs(y2 - y1);
	//if (x2 < x1) {
	//	std::swap(x1, x2);
	//}
	//if (y2 < y1) {
	//	std::swap(x2, y2);
	//}


	/*int dx = x2 - x1;
	int dy = y2 - y1;*/ //need to use absolute to prevent negative points
	int xInc, yInc;
	xInc = (x2 > x1) ? 1 : -1;
	yInc = (y2 > y1) ? 1 : -1;

	//need to determine if slope of the line will be positive or negative
	// if dx>dy then slope is 0<m<1, can use regular algo
	if (dx > dy) {
		//std::cout << "DX>DY" << std::endl;
		int d = 2 * dy - dx; //decision variable
		int deltaD1 = 2 * dy;
		int deltaD2 = 2 * (dy - dx);
		int y = y1;

		if (x2 > x1) {

			for (int x = x1; x < x2; x++) {
				setPixels(x, y);
				//std::cout << "X: " << x << " Y:" << y << std::endl;
				if (d < 0) {
					d = d + deltaD1;
				}
				else {
					d = d + deltaD2;
					y += yInc;
				}

			}
		}

		else {
			std::cout << "x2<x1" << std::endl;
			for (int x = x1; x > x2; x--) {
				setPixels(x, y);
				//std::cout << "X: " << x << " Y:" << y << std::endl;
				if (d < 0) {
					d = d + deltaD1;
				}
				else {
					d = d + deltaD2;
					y += yInc;
				}

			}
		}
	}
	else {
		//std::cout << "IN the else " << std::endl;
		int d = 2 * dx - dy; //decision variable
		int deltaD1 = 2 * dx;
		int deltaD2 = 2 * (dx - dy);
		int x = x1;

		if (y1 <= y2) {
			for (int y = y1; y < y2; y++) {
				setPixels(x, y);
				//std::cout << "X: " << x << " Y:" << y << std::endl;
				if (d < 0) {
					d = d + deltaD1;
				}
				else {
					d = d + deltaD2;
					x += 1;
				}

			}
		}
		else {

			for (int y = y1; y > y2; y--) {
				setPixels(x, y);
				//std::cout << "X: " << x << " Y:" << y << std::endl;
				if (d < 0) {
					d = d + deltaD1;
				}
				else {
					d = d + deltaD2;
					x += xInc;
				}

			}
		}

	}

}


void midpoint(int x1, int y1, int x2, int y2) {
	int dx = std::abs(x2 - x1);
	int dy = std::abs(y2 - y1); //need to use absolute to prevent negative points
	int xInc, yInc;
	xInc = (x2 > x1) ? 1 : -1;
	yInc = (y2 > y1) ? 1 : -1;
	setPixels(x1, y1);

	//need to determine if slope of the line will be positive or negative
	// if dx>dy then slope is 0<m<1, can use regular algo
	if (dx > dy) {
		//std::cout <<  "DX>DY" << std::endl;
		int d = 2 * dy - dx; //decision variable
		int deltaD1 = 2 * dy;
		int deltaD2 = 2 * (dy - dx);
		int y = y1;
		int x;

		if (x2 >= x1) {
			x = x1;
			while (x < x2) {
				
				if (d <= 0) {
					d = d + deltaD1;
					x += 1;
				}
				else {
					d += deltaD2;
					x += 1;
					y += yInc;
				}
				setPixels(x, y);
			}
		}
		else {
			x = x1;
			//std::cout << "x2<x1" << std::endl;
			while (x > x2) {

				if (d <= 0) {
					d = d + deltaD1;
					x -= 1;
				}
				else {
					d += deltaD2;
					x -= 1;
					y += yInc;
				}
				setPixels(x, y);
			}
		
		}
	}
	else {
		//std::cout << "IN the else " << std::endl;
		int d = 2*dx - dy; //decision variable
		int deltaD1 = 2 * dx;
		int deltaD2 = 2 * (dx - dy);
		int y;
		int x = x1;

		if (y1 <= y2) {
			y = y1;
			//std::cout << "y<y1" << std::endl;
			while ( y< y2) {
				

				if (d <= 0) {
					d = d + deltaD1;
					y += 1;
				}
				else {
					d += deltaD2;
					x += xInc;
					y += 1;
				}
				setPixels(x, y);
			}
			
		}
		else {

			y = y1;
			std::cout << "y<y2" << std::endl;
			while (y > y2) {

				if (d <= 0) {
					d = d + deltaD1;
					y -= 1;
				}
				else {
					d += deltaD2;
					x += xInc;
					y -= 1;
				}
				setPixels(x, y);
			}
		}

	}


}

void setPixels(int x,int y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void glut_wake() {
	glBegin(GL_LINES);

	//the W
	glVertex2f(500, 0);
	glVertex2f(550, 50);

	glVertex2f(550, 50);
	glVertex2f(580, 20);

	glVertex2f(580, 20);
	glVertex2f(610, 50);

	glVertex2f(610, 50);
	glVertex2f(650, 0);

	//the A
	glVertex2f(640, 50);
	glVertex2f(670, 0);

	glVertex2f(670, 0);
	glVertex2f(700, 50);

	glVertex2f(655, 25);
	glVertex2f(685, 25);

	//the K
	glVertex2f(720, 0);
	glVertex2f(720, 50);

	glVertex2f(720, 25);
	glVertex2f(740, 0);

	glVertex2f(720, 25);
	glVertex2f(740, 50);

	//the E
	glVertex2f(750, 0);
	glVertex2f(750, 50);

	glVertex2f(750, 3);
	glVertex2f(780, 3);

	glVertex2f(750, 25);
	glVertex2f(780, 25);

	glVertex2f(750, 50);
	glVertex2f(780, 50);
	
	glEnd();

}
void draw_line(int x1, int y1, int x2, int y2) {
	glBegin(GL_LINE_STRIP);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	

}


void mouse(int button, int state, int x, int y) {
	int x1, y1;
	int x2, y2;
	if (button == GLUT_LEFT_BUTTON) {

		if (done_drawing && !lines.empty()) {
			std::cout << "DONE DRAWING BOSSS " << lines.size() << std::endl;
			lines.pop_back();
			done_drawing = false;
		}
	
		if (state == GLUT_DOWN) {
			
		//	std::cout << "GLUT-UP" << std::endl;
			basePoint = std::make_pair(x, y);
			
			glutPostRedisplay();

		}
		else if (state == GLUT_UP) {
			//std::cout << "GLUT-UP" << std::endl;
			draw_line(basePoint.first, basePoint.second, x, y);
			lines.push_back({ basePoint.first, basePoint.second, x, y });
			basePoint = std::make_pair(x, y);
		}
	}
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
		//std::cout << "Right Button Clicked" << std::endl;
		done_drawing = true;
		draw_line(basePoint.first, basePoint.second, x, y);
		lines.push_back({ basePoint.first, basePoint.second, x, y });

		
	


	}
	


	


	
}

void mouseMove(int x, int y) {
	
	
	glClear(GL_COLOR_BUFFER_BIT);

	for (auto it = std::begin(lines); it != std::end(lines); ++it) {

		line current = *it;
		draw_line(current.x1, current.y1, current.x2,current.y2);
					
	}
	
	draw_line(basePoint.first, basePoint.second, x, y);
	
	glutPostRedisplay();


}


void display_bresenham() {
	//the W
	bresenham(0,0, 50, 50);
	bresenham(50, 50,80, 20);
	bresenham(80, 20, 110, 50);
	bresenham(110, 50,150, 0);

	//the A
	bresenham(140, 50, 170, 0);
	bresenham(170, 0, 200, 50);
	bresenham(155, 25, 185, 25);

	//the k
	bresenham(220, 0, 220, 50);
	bresenham(220, 25, 240, 0);
	bresenham(220, 25, 240, 50);

	//the E
	bresenham(250, 0, 250, 50);
	bresenham(250, 3, 280, 3);
	bresenham(250, 25, 280, 25);
	bresenham(250, 50, 280, 50);
	glut_wake();


	glFlush();
}
void display_midpoint() {

	

	//the W
	midpoint(0,0, 50, 50);
	midpoint(50, 50,80, 20);
	midpoint(80, 20, 110, 50);
	midpoint(110, 50,150, 0);

	//the A
	midpoint(140, 50, 170, 0);
	midpoint(170, 0, 200, 50);
	midpoint(155, 25, 185, 25);

	//the k
	midpoint(220, 0, 220, 50);
	midpoint(220, 25, 240, 0);
	midpoint(220, 25, 240, 50);

	//the E
	midpoint(250, 0, 250, 50);
	midpoint(250, 3, 280, 3);
	midpoint(250, 25, 280, 25);
	midpoint(250, 50, 280, 50);

	glut_wake();


	glFlush();
}

void choice_algorithm() {
	int input;
	std::cout << "Select 1 for Bresenham or 2 for midpoint ";
	std::cin >> input;
	if (input == 1) {
		display_bresenham();
	}
	else if (input == 2) {
		display_midpoint();
	}
	return;

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("Computer Graphics");
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1000.0, 500.0, 0.0);
	glutDisplayFunc(display_bresenham);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);
	glutMainLoop();
	return 0;

}