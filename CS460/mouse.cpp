//#include <windows.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
//#include <iostream>
//#include <freeglut.h>
//void drawPoint(int x, int y) {
//
//	// adjust the coordinates due to different origins (left-bottom or left-top)
//	y = 600 - y;
//
//	// set the size and the color of the point
//	glPointSize(4);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	// draw a point at position x, y
//	glBegin(GL_POINTS);
//	glVertex2f(x, y);
//	glEnd();
//
//	glFlush();
//}
//
//void processMouse(int button, int state, int x, int y) {
//
//	// check if the left button is down 
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		drawPoint(x, y);
//		std::cout << "The x coor: " << x << std::endl;
//		std::cout << "The y coor: " << y << std::endl;
//	}
//
//}
//
//void init()
//{
//	// clear color buffer
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	// set the viewport as the full screen
//	glViewport(0, 0, 800, 600);
//
//	// set the projection as orthogonal projection
//	glMatrixMode(GL_PROJECTION);
//	glOrtho(0.0, 800.0, 0.0, 600.0, 1.0, -1.0);
//
//	// set the matrix mode back to modelview mode
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void display() {}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//
//	// create a window
//	glutInitWindowPosition(300, 300);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Computer Graphics");
//
//	// init settings
//	init();
//	glutDisplayFunc(display);
//
//	// register a call back for mouse events
//	glutMouseFunc(processMouse);
//
//	// enter main loop
//	glutMainLoop();
//}