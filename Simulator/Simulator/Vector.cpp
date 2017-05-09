#include "Vector.h"

void Vector::setX(double x) {
	_x = x;
}

void Vector::setY(double y) {
	_y = y;
}

void Vector::setZ(double z) {
	_z = z;
}

// Make a unit vector
Vector &Vector::unit() {

	if (isDefault()) {
		double rep = mag();
		if (rep < EPSILON) {
			_x = 0.0;
			_y = 0.0;
			_z = 0.0;
		} else {
			double temp = 1.0 / rep;
			_x *= temp;
			_y *= temp;
			_z *= temp;
		}
		_status = UNIT;
	}
	return *this;
}

// Make a default vector
Vector &Vector::Default() {
	if (isUnit()) {
		_status = DEFAULT;
	}
	return *this;
}

Vector &Vector::invert(const Vector &v1, Vector &result) {

	if (v1.isValid()) {
		result._x = -v1._x;
		result._y = -v1._y;
		result._z = -v1._z;
		result._status = v1._status;
	} else {
		result = Vector();
	}
	return result;
}



Vector &Vector::add(const Vector &v1, const Vector &v2, Vector &result) {

	if (v1.isValid() && v2.isValid()) {
		result._x = v1._x + v2._x;
		result._y = v1._y + v2._y;
		result._z = v1._z + v2._z;
		result._status = DEFAULT;
	} else {
		result = Vector();
	}
	return result;
}

Vector &Vector::subtract(const Vector &v1, const Vector &v2, Vector &result) {

	if (v1.isValid() && v2.isValid()) {
		result._x = v1._x - v2._x;
		result._y = v1._y - v2._y;
		result._z = v1._z - v2._z;
		result._status = DEFAULT;
	} else {
		result = Vector();
	}
	return result;
}

Vector &Vector::cross(const Vector &v1, const Vector &v2, Vector &result) {

	if (v1.isValid() && v2.isValid()) {
		result._x = v1._y * v2._z - v1._z * v2._y;
		result._y = v1._z * v2._x - v1._x * v2._z;
		result._z = v1._x * v2._y - v1._y * v2._x;
		result._status = DEFAULT;
	} else {
		result = Vector();
	}
	return result;
}

Vector &Vector::multiply(const Vector &v1, const double &scale, Vector &result) {

	if (v1.isValid()) {
		result._x = v1._x * scale;
		result._y = v1._y * scale;
		result._z = v1._z * scale;
		result._status = DEFAULT;
	} else {
		result = Vector();
	}
	return result;
}
