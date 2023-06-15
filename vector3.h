#pragma once

#ifndef VECTOR_3_H
#define VECTOR_3_H
#define VECTOR_3_M_PI_2 1.57079632679489661923
#define VECTOR_3_M_PI_4 0.785398163397448309616
#define VECTOR_3_M_1_PI 0.318309886183790671538
#define VECTOR_3_M_2_PI 0.636619772367581343076

#include "location.h"

namespace utils
{
	class Vector3
	{
	private:
		double _x;
		double _y;
		double _z;

	public:
		Vector3(double x, double y, double z);

		Vector3() = default;

		double getX();

		double getY();

		double getZ();

		void setX(double x);

		void setY(double y);

		void setZ(double z);

		void add(double x, double y, double z);

		void subtract(double x, double y, double z);

		void multiply(double x, double y, double z);

		void divide(double x, double y, double z);

		void floorX();

		void floorY();

		void floorZ();

		Vector3 toCeil();

		Vector3 toFloor();

		Vector3 toRound(int precision, int mode);

		Vector3 toAbs();

		Vector3 toNormalize();

		Vector3 toCross(Vector3& vector3);

		Vector3* getIntermediateWithXValue(Vector3& vector3, float x);

		Vector3* getIntermediateWithYValue(Vector3& vector3, float y);

		Vector3* getIntermediateWithZValue(Vector3& vector3, float z);

		Vector3 getDirectionVector(double pitch, double yaw);

		Vector3 getDirectionPlane(Location& location);

		double distance(Vector3& vector3);

		double distanceSquared(Vector3& vector3);

		double maxPlainDistance(double x, double z);

		double getLength();

		double getLengthSquared();

		double toHypot(double p1, double p2);

		double toDot(Vector3& vector3);

		bool equals(Vector3& vector3);
	};
}

#endif