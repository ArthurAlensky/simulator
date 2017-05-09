#ifndef camera_h

#define camera_h

#include "Vector.h"

class Camera {
private:
	Vector eye, target, up;

public:
	void view();
};
#endif