#include "Light.h"

void Light::Set(GLfloat lightPosition[]) {
	GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat ambient[]  = { 0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat diffuse[]  = { 0.4f, 0.4f, 0.4f, 1.0f};

	glLightfv(GL_LIGHT0,GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}