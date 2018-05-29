#pragma once

#include <iostream>

namespace icarus {
	namespace maths {

		struct Vector3
		{
			float x, y, z;

			const static Vector3 up;
			const static Vector3 down;
			const static Vector3 left;
			const static Vector3 right;
			const static Vector3 forward;
			const static Vector3 back;
			const static Vector3 zero;
			const static Vector3 one;

			Vector3();
			Vector3(const float& x, const float& y, const float& z);

			Vector3 Add(const Vector3& other) const;
			Vector3 Subtract(const Vector3& other) const;
			Vector3 Multiply(const Vector3& other) const;
			Vector3 Divide(const Vector3& other) const;
			Vector3 Multiply(const float& scalar) const;
			Vector3 Divide(const float& scalar) const;

			// Operator overloads
			friend Vector3 operator+(const Vector3& left, const Vector3& right);
			friend Vector3 operator-(const Vector3& left, const Vector3& right);
			friend Vector3 operator*(const Vector3& left, const Vector3& right);
			friend Vector3 operator*(const Vector3& vec, const float& scalar);
			friend Vector3 operator/(const Vector3& left, const Vector3& right);
			friend Vector3 operator/(const Vector3& vec, const float& scalar);
			friend Vector3 operator*=(Vector3& vec, const float& scalar);
			friend Vector3 operator/=(Vector3& vec, const float& scalar);
			friend bool operator==(const Vector3& left, const Vector3& right);
			friend bool operator!=(const Vector3& left, const Vector3& right);
			friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);
		};

	}
}
