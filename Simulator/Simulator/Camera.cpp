#include "Camera.h"
#include <GL\freeglut.h>

void Camera::View() {
	gluLookAt(_eye.x(), _eye.y(), _eye.z(), _target.x(), _target.y(), _target.z(), _up.x(), _up.y(), _up.z());
}