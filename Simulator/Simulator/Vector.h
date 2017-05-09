#ifndef vector_h

#define vector_h


#include <iostream>
#include <math.h>
#include "Mathex.h"

class Vector {
	public:
		enum Status { INVALID, DEFAULT, UNIT };

	private:
		
		Status _status;
		double _x, _y, _z;
	
		// Constructors
		Vector(double x, double y, double z, Status s) : _x(x), _y(y), _z(z), _status(s) {}

	public:
		
		// Constructors
		Vector() : _x(1.0), _y(0.0), _z(0.0), _status(DEFAULT) {}
		Vector(double x, double y, double z) : _x(x), _y(y), _z(z), _status(DEFAULT) {}
		
		//set variable
		void setX(double x);
		void setY(double y);
		void setZ(double z);
		void operator()(double x, double y, double z){ _x=x; _y=y; _z=z; }

		// Selectors
		double X() const { return _x; }
		double Y() const { return _y; }
		double Z() const { return _z; }
		int isUnit() const { return _status==UNIT; }
		int isDefault() const { return _status==DEFAULT; }
		int isValid() const { return _status!=INVALID; }

		// Change the status of a vector
		Vector &unit();
		static Vector &unit(const Vector &v, Vector &result) { result = v; return result.unit(); }
		static Vector unit(const Vector &v) { return Vector(v).unit(); }

		Vector &Default();
		static Vector Default(const Vector &v, Vector &result) { result = v; return result.Default(); }
		static Vector Default(const Vector &v) { return Vector(v).Default(); }

		// Magnitude
		double mag() const { return (isValid() ? (isUnit() ? 1.0 : sqrt(sqr(X()) + sqr(Y()) + sqr(Z()))) : 0.0); }
		double magSqr() const { return (isValid() ? (isUnit() ? 1.0 : sqr(X()) + sqr(Y()) + sqr(Z())) : 0.0); }

		// Dot or scalar product
		double dot(const Vector &v) const { return ((isValid() && v.isValid()) ? (X()*v.X() + Y()*v.Y() + Z()*v.Z()) : 0.0); }
		static double dot(const Vector &v1, const Vector &v2) { return v1.dot(v2); }

		// Distance between two vectors
		double dist(const Vector &v) const { return (*this-v).mag(); }
		double distSqr(const Vector &v) const { return (*this-v).magSqr(); }

		// Optimised arithmetic methods
		static Vector &add(const Vector &v1, const Vector &v2, Vector &result);
		static Vector &subtract(const Vector &v1, const Vector &v2, Vector &result);
		static Vector &cross(const Vector &v1, const Vector &v2, Vector &result);
		static Vector &invert(const Vector &v1, Vector &result);
		static Vector &multiply(const Vector &v1, const double &scale, Vector &result);

		// Vector arithmetic, addition, subtraction and vector product
		Vector operator-() const { Vector tmp; return invert(*this, tmp); }
		Vector &operator+=(const Vector &v) { return add(*this, v, *this); }
		Vector &operator-=(const Vector &v) { return subtract(*this, v, *this); }
		Vector &operator*=(const Vector &v) { Vector tv(*this); return cross(tv, v, *this); }
		Vector &operator*=(const double &scale) { return multiply(*this, scale, *this); }
		Vector operator+(const Vector &v) const { Vector tv; return add(*this, v, tv); }
		Vector operator-(const Vector &v) const { Vector tv; return subtract(*this, v, tv); }
		Vector operator*(const Vector &v) const { Vector tv; return cross(*this, v, tv); }
		Vector operator*(const double &scale) const { Vector tv; return multiply(*this, scale, tv); }
};
#endif
