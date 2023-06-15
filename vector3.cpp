#include "vector3.h"
#include "zmath.h"

#include <math.h>
#include <algorithm>
#include <iostream>

namespace utils
{

	Vector3::Vector3(double x, double y, double z)
		: _x(x), _y(y), _z(z)
	{

	}

	Vector3::Vector3()
		: _x(0.0), _y(0.0), _z(0.0)
	{

	}

	double Vector3::getX()
	{
		return _x;
	}

	double Vector3::getY()
	{
		return _y;
	}

	double Vector3::getZ()
	{
		return _z;
	}

	void Vector3::setX(double x)
	{
		_x = x;
	}

	void Vector3::setY(double y)
	{
		_y = y;
	}

	void Vector3::setZ(double z)
	{
		_z = z;
	}

	void Vector3::add(double x, double y, double z)
	{
		_x += x;
		_y += y;
		_z += z;
	}

	void Vector3::subtract(double x, double y, double z)
	{
		_x -= x;
		_y -= y;
		_z -= z;
	}

	void Vector3::multiply(double x, double y, double z)
	{
		_x *= x;
		_y *= y;
		_z *= z;
	}

	void Vector3::divide(double x, double y, double z)
	{
		_x /= x;
		_y /= y;
		_z /= z;
	}

	void Vector3::floorX()
	{
		_x = floor(_x);
	}

	void Vector3::floorY()
	{
		_y = floor(_y);
	}

	void Vector3::floorZ()
	{
		_z = floor(_z);
	}

	Vector3 Vector3::toCeil()
	{
		Vector3 result;
		result._x = ceil(_x);
		result._y = ceil(_y);
		result._z = ceil(_z);
		return result;
	}

	Vector3 Vector3::toFloor()
	{
		Vector3 result;
		result._x = floor(_x);
		result._y = floor(_y);
		result._z = floor(_z);
		return result;
	}

	Vector3 Vector3::toRound(int precision, int mode)
	{
		Vector3 vector1;
		Vector3 vector2;

		vector1._x = round(_x * pow(10, precision)) / pow(10, precision);
		vector1._y = round(_y * pow(10, precision)) / pow(10, precision);
		vector1._z = round(_z * pow(10, precision)) / pow(10, precision);

		vector2._x = static_cast<int>(round(_x * pow(10, precision)) / pow(10, precision));
		vector2._y = static_cast<int>(round(_y * pow(10, precision)) / pow(10, precision));
		vector2._z = static_cast<int>(round(_z * pow(10, precision)) / pow(10, precision));

		return precision > 0 ? vector1 : vector2;
	}

	Vector3 Vector3::toAbs()
	{
		Vector3 result;
		result._x = abs(_x);
		result._y = abs(_y);
		result._z = abs(_z);
		return result;
	}

	Vector3 Vector3::toNormalize()
	{
		Vector3 result;
		double len = Vector3::getLengthSquared();
		if (len > 0) {
			result.divide(sqrt(len), sqrt(len), sqrt(len));
			return result;
		}
		return result;
	}

	Vector3 Vector3::toCross(Vector3& vector3)
	{
		Vector3 result;
		result._x = _y * vector3.getZ() - _z * vector3.getY();
		result._y = _z * vector3.getX() - _x * vector3.getZ();
		result._z = _x * vector3.getY() - _y * vector3.getX();
		return result;
	}

	Vector3* Vector3::getIntermediateWithXValue(Vector3& vector3, float x)
	{
		double diff = vector3.getX() - _x;
		if ((diff * diff) < 0.0000001)
		{
			return nullptr;
		}
		double f = (x - _x) / diff;
		if (f < 0 || f > 1)
		{
			return nullptr;
		}
		Vector3* result;
		result->_x = x;
		result->_y = _y + (vector3._y - _y) * f;
		result->_z = _z + (vector3._z - _z) * f;
		return result;
	}

	Vector3* Vector3::getIntermediateWithYValue(Vector3& vector3, float y)
	{
		double diff = vector3.getY() - _y;
		if ((diff * diff) < 0.0000001)
		{
			return nullptr;
		}
		double f = (y - _y) / diff;
		if (f < 0 || f > 1)
		{
			return nullptr;
		}
		Vector3* result;
		result->_x = _x + (vector3._x - _x) * f;
		result->_y = y;
		result->_z = _z + (vector3._z - _z) * f;
		return result;
	}

	Vector3* Vector3::getIntermediateWithZValue(Vector3& vector3, float z)
	{
		double diff = vector3.getZ() - _z;
		if ((diff * diff) < 0.0000001)
		{
			return nullptr;
		}
		double f = (z - _z) / diff;
		if (f < 0 || f > 1)
		{
			return nullptr;
		}
		Vector3* result;
		result->_x = _x + (vector3._x - _x) * f;
		result->_y = _y + (vector3._y - _y) * f;
		result->_z = z;
		return result;
	}

	Vector3 Vector3::getDirectionVector(double pitch, double yaw)
	{
		double y = -sin(ZMath::deg2rad(pitch));
		double xz = cos(ZMath::deg2rad(pitch));
		double x = -xz * sin(ZMath::deg2rad(yaw));
		double z = xz * cos(ZMath::deg2rad(yaw));
		Vector3 result(x, y, z);
		return result.toNormalize();
	}

	Vector3 Vector3::getDirectionPlane(Location& location)
	{
		Vector3 result;
		double yaw = location.getYaw();
		result._x = -cos(ZMath::deg2rad(yaw) - VECTOR_3_M_PI_2);
		result._y = 0;
		result._z = -sin(ZMath::deg2rad(yaw) - VECTOR_3_M_PI_2);
		return result.toNormalize();
	}

	double Vector3::distance(Vector3& vector3)
	{
		return sqrt(Vector3::distanceSquared(vector3));
	}

	double Vector3::distanceSquared(Vector3& vector3)
	{
		return pow((_x - vector3.getX()), 2) + pow((_y - vector3.getY()), 2) + pow((_z - vector3.getZ()), 2);
	}

	double Vector3::maxPlainDistance(double x, double z)
	{
		return std::max(abs(_x - x), abs(_z - z));
	}

	double Vector3::getLength()
	{
		return sqrt(Vector3::getLengthSquared());
	}

	double Vector3::getLengthSquared()
	{
		return _x * _x + _y * _y + _z * _z;
	}

	double Vector3::toHypot(double p1, double p2)
	{
		return sqrt(p1 * p1 + p2 * p2);
	}

	double Vector3::toDot(Vector3& vector3)
	{
		return _x * vector3.getX() + _y * vector3.getY() + _z * vector3.getZ();
	}

	bool Vector3::equals(Vector3& vector3)
	{
		return _x == vector3.getX() && _y == vector3.getY() && _z == vector3.getZ();
	}

}