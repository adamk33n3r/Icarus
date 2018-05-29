#include "Vector4.h"

namespace icarus {
	namespace maths {

		Vector4::Vector4()
			: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
		}

		Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
			: x(x), y(y), z(z), w(w)
		{
		}

		Vector4 Vector4::Add(const Vector4& other) const
		{
			return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		Vector4 Vector4::Subtract(const Vector4& other) const
		{
			return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
		}

		Vector4 Vector4::Multiply(const Vector4& other) const
		{
			return Vector4(x * other.x, y * other.y, z * other.z, w * other.w);
		}

		Vector4 Vector4::Multiply(const float& scalar) const
		{
			return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
		}

		Vector4 Vector4::Divide(const Vector4& other) const
		{
			return Vector4(x / other.x, y / other.y, z / other.z, w / other.w);
		}

		Vector4 Vector4::Divide(const float& scalar) const
		{
			return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
		}

		Vector4 operator+(const Vector4& left, const Vector4& right)
		{
			return left.Add(right);
		}

		Vector4 operator-(const Vector4& left, const Vector4& right)
		{
			return left.Subtract(right);
		}

		Vector4 operator*(const Vector4& left, const Vector4& right)
		{
			return left.Multiply(right);
		}

		Vector4 operator*(const Vector4& vec, const float& scalar)
		{
			return vec.Multiply(scalar);
		}

		Vector4 operator/(const Vector4& left, const Vector4& right)
		{
			return left.Divide(right);
		}

		Vector4 operator/(const Vector4& vec, const float& scalar)
		{
			return vec.Divide(scalar);
		}

		Vector4 operator*=(Vector4& vec, const float& scalar)
		{
			vec.x *= scalar;
			vec.y *= scalar;
			vec.z *= scalar;
			vec.w *= scalar;
			return vec;
		}

		Vector4 operator/=(Vector4& vec, const float& scalar)
		{
			vec.x /= scalar;
			vec.y /= scalar;
			vec.z /= scalar;
			vec.w /= scalar;
			return vec;
		}

		bool operator==(const Vector4& left, const Vector4& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
		}

		bool operator!=(const Vector4& left, const Vector4& right)
		{
			return !(left == right);
		}

		std::ostream& operator<<(std::ostream& os, const Vector4& vec)
		{
			os << "Vector4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
			return os;
		}

	}
}
