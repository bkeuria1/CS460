
//#include <Windows.h>
//#include <gl/GL.h>
//#include <gl/GLU.h>
//#include <iostream>
//#include <freeglut.h>
//
//
//
//
//void display() {
//
//	// clear color buffer
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	// draw a triangle
//	glBegin(GL_TRIANGLES);
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex2f(-0.5f, -0.5f);
//	glVertex2f(0.5f, -0.5f);
//	glVertex2f(0.0f, 0.5f);
//	glEnd();
//
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//
//	// create a window
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(300, 300);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Computer Graphics");
//
//	// register a display callback
//	glutDisplayFunc(display);
//
//	// event processing loop
//	glutMainLoop();
//
//	return 0;
//}
