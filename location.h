#pragma once

#ifndef LOCATION_H
#define LOCATION_H

#include "vector3.h"

#include <string>

namespace utils
{
	class Location
	{
	private:
		double _x;
		double _y;
		double _z;
		double _yaw;
		double _pitch;
		bool _onGround;

	public:
		Location(double x, double y, double z, double yaw, double pitch, bool onGround);

		double getX();

		double getY();

		double getZ();

		double getYaw();

		double getPitch();

		bool isOnGround();

		void add(double x, double y, double z, double yaw, double pitch);

		void subtract(double x, double y, double z, double yaw, double pitch);

		double distanceXZ(Vector3& vector3);

		double distanceXZSquared(Vector3& vector3);

		bool equals(Location* location);

		Vector3 toVector();

		std::string toString();
	};
}

#endif