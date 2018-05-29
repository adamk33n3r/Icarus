#pragma once

#include <iostream>

namespace icarus {
	namespace maths {

		struct Vector2
		{
			float x, y;

			const static Vector2 up;
			const static Vector2 down;
			const static Vector2 left;
			const static Vector2 right;
			const static Vector2 zero;
			const static Vector2 one;

			Vector2();
			Vector2(const float& x, const float& y);

			Vector2 Add(const Vector2& other) const;
			Vector2 Subtract(const Vector2& other) const;
			Vector2 Multiply(const Vector2& other) const;
			Vector2 Divide(const Vector2& other) const;
			Vector2 Multiply(const float& scalar) const;
			Vector2 Divide(const float& scalar) const;

			static Vector2 Up();
			static Vector2 Down();
			static Vector2 Left();
			static Vector2 Right();

			// Operator overloads
			friend Vector2 operator+(const Vector2& left, const Vector2& right);
			friend Vector2 operator-(const Vector2& left, const Vector2& right);
			friend Vector2 operator*(const Vector2& left, const Vector2& right);
			friend Vector2 operator*(const Vector2& vec, const float& scalar);
			friend Vector2 operator/(const Vector2& left, const Vector2& right);
			friend Vector2 operator/(const Vector2& vec, const float& scalar);
			friend Vector2 operator*=(Vector2& vec, const float& scalar);
			friend Vector2 operator/=(Vector2& vec, const float& scalar);
			friend bool operator==(const Vector2& left, const Vector2& right);
			friend bool operator!=(const Vector2& left, const Vector2& right);
			friend std::ostream& operator<<(std::ostream& os, const Vector2& vec);
		};

	}
}
