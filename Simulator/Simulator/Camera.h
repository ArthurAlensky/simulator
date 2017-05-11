#ifndef camera_h

#define camera_h

#include "Vector.h"

class Camera {
private:
	Vector _eye, _target, _up;

public:
	Camera(Vector eye, Vector target, Vector up): _eye(eye), _target(target), _up(up) {}
	void View();
};
#endif