#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <freeglut.h>


float r = 0.0f, g = 0.0f, b = 1.0f;

void display() {

	// clear color buffer
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// draw a triangle
	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glEnd();

	glFlush();
}

// change the color based on the pressed key
void processKeys(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		r = 1.0; g = 0.0; b = 0.0; break;
	case '2':
		r = 0.0; g = 1.0; b = 0.0; break;
	case '3':
		r = 0.0; g = 0.0; b = 1.0; break;
	}
}


int main(int argc, char** argv) {

	// create a window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Computer Graphics");

	// register a display callback
	glutDisplayFunc(display);
	glutIdleFunc(display);

	// register a callback for keyboard events
	glutKeyboardFunc(processKeys);

	// event processing loop
	glutMainLoop();

	return 0;
}