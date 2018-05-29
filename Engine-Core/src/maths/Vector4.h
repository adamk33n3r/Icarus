#pragma once

#include <iostream>

namespace icarus {
	namespace maths {

		struct Vector4
		{
			float x, y, z, w;
			Vector4();
			Vector4(const float& x, const float& y, const float& z, const float& w);

			Vector4 Add(const Vector4& other) const;
			Vector4 Subtract(const Vector4& other) const;
			Vector4 Multiply(const Vector4& other) const;
			Vector4 Divide(const Vector4& other) const;
			Vector4 Multiply(const float& scalar) const;
			Vector4 Divide(const float& scalar) const;

			// Operator overloads
			friend Vector4 operator+(const Vector4& left, const Vector4& right);
			friend Vector4 operator-(const Vector4& left, const Vector4& right);
			friend Vector4 operator*(const Vector4& left, const Vector4& right);
			friend Vector4 operator*(const Vector4& vec, const float& scalar);
			friend Vector4 operator/(const Vector4& left, const Vector4& right);
			friend Vector4 operator/(const Vector4& vec, const float& scalar);
			friend Vector4 operator*=(Vector4& vec, const float& scalar);
			friend Vector4 operator/=(Vector4& vec, const float& scalar);
			friend bool operator==(const Vector4& left, const Vector4& right);
			friend bool operator!=(const Vector4& left, const Vector4& right);
			friend std::ostream& operator<<(std::ostream& os, const Vector4& vec);
		};

	}
}