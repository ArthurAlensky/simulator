#include <GL\freeglut.h>

#define gWinWidth 1200
#define gWinHeight 600

void main(int argc, char ** const argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH |GLUT_DOUBLE);
	glutInitWindowSize(gWinWidth, gWinHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simulator");
}