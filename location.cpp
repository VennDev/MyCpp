#include "location.h"
#include "vector3.h"

#include <math.h>
#include <iostream>

namespace utils
{

	Location::Location(double x, double y, double z, double yaw, double pitch, bool onGround)
		: _x(x), _y(y), _z(z), _yaw(yaw), _pitch(pitch), _onGround(onGround)
	{

	}

	double Location::getX()
	{
		return _x;
	}

	double Location::getY()
	{
		return _y;
	}

	double Location::getZ()
	{
		return _z;
	}

	double Location::getYaw()
	{
		return _yaw;
	}

	double Location::getPitch()
	{
		return _pitch;
	}

	bool Location::isOnGround()
	{
		return _onGround;
	}

	void Location::add(double x, double y, double z, double yaw, double pitch)
	{
		_x += x;
		_y += y;
		_z += z;
		_yaw += yaw;
		_pitch += pitch;
	}

	void Location::subtract(double x, double y, double z, double yaw, double pitch)
	{
		_x += x;
		_y += y;
		_z += z;
		_yaw += yaw;
		_pitch += pitch;
	}

	double Location::distanceXZ(Vector3& vector3)
	{
		return sqrt(Location::distanceXZSquared(vector3));
	}

	double Location::distanceXZSquared(Vector3& vector3)
	{
		return pow(_x - vector3.getX(), 2.0) + pow(_z - vector3.getZ(), 2.0);
	}

	bool Location::equals(Location* location)
	{
		return _x == location->getX() && _y == location->getY() && _z == location->getZ() && _yaw == location->getYaw() && _pitch == location->getPitch() && _onGround == location->isOnGround();
	}

	Vector3 Location::toVector()
	{
		return Vector3(_x, _y, _z);
	}

	std::string Location::toString()
	{
		std::string string = "Location(";
		string += "x=" + std::to_string(_x) + ", ";
		string += "y=" + std::to_string(_y) + ", ";
		string += "z=" + std::to_string(_z) + ", ";
		string += "yaw=" + std::to_string(_yaw) + ", ";
		string += "pitch=" + std::to_string(_pitch) + ", ";
		string += "onGround=" + std::to_string(_onGround) + ")";
		return string;
	}

}