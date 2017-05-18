#include <GL\glew.h>
#include <GL\freeglut.h>
#include "Light.h"

#define gWinWidth 1200
#define gWinHeight 600

void initGL()
{
	glewInit();
}

void init() {
}

void draw() {

}

void idle()
{
	glutPostRedisplay();
}

void display() {
	draw();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc, char ** const argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH |GLUT_DOUBLE);
	glutInitWindowSize(gWinWidth, gWinHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simulator");

	initGL();
	init();

	Light::Set({ 1.0, 1.0, 1.0 });
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
}