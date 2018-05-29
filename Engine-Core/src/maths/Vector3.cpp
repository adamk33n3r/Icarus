#include "Vector3.h"

namespace icarus {
	namespace maths {

		const Vector3 Vector3::up = Vector3(0, 1, 0);
		const Vector3 Vector3::down = Vector3(0, -1, 0);
		const Vector3 Vector3::left = Vector3(-1, 0, 0);
		const Vector3 Vector3::right = Vector3(1, 0, 0);
		const Vector3 Vector3::forward = Vector3(0, 0, 1);
		const Vector3 Vector3::back = Vector3(0, 0, -1);
		const Vector3 Vector3::zero = Vector3(0, 0, 0);
		const Vector3 Vector3::one = Vector3(1, 1, 1);

		Vector3::Vector3()
			: x(0.0f), y(0.0f), z(0.0f)
		{
		}

		Vector3::Vector3(const float& x, const float& y, const float& z)
			: x(x), y(y), z(z)
		{
		}

		Vector3 Vector3::Add(const Vector3& other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		Vector3 Vector3::Subtract(const Vector3& other) const
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		Vector3 Vector3::Multiply(const Vector3& other) const
		{
			return Vector3(x * other.x, y * other.y, z * other.z);
		}

		Vector3 Vector3::Multiply(const float& scalar) const
		{
			return Vector3(x * scalar, y * scalar, z * scalar);
		}

		Vector3 Vector3::Divide(const Vector3& other) const
		{
			return Vector3(x / other.x, y / other.y, z / other.z);
		}

		Vector3 Vector3::Divide(const float& scalar) const
		{
			return Vector3(x / scalar, y / scalar, z / scalar);
		}

		Vector3 operator+(const Vector3& left, const Vector3& right)
		{
			return left.Add(right);
		}

		Vector3 operator-(const Vector3& left, const Vector3& right)
		{
			return left.Subtract(right);
		}

		Vector3 operator*(const Vector3& left, const Vector3& right)
		{
			return left.Multiply(right);
		}

		Vector3 operator*(const Vector3& vec, const float& scalar)
		{
			return vec.Multiply(scalar);
		}

		Vector3 operator/(const Vector3& left, const Vector3& right)
		{
			return left.Divide(right);
		}

		Vector3 operator/(const Vector3& vec, const float& scalar)
		{
			return vec.Divide(scalar);
		}

		Vector3 operator*=(Vector3& vec, const float& scalar)
		{
			vec.x *= scalar;
			vec.y *= scalar;
			vec.z *= scalar;
			return vec;
		}

		Vector3 operator/=(Vector3& vec, const float& scalar)
		{
			vec.x /= scalar;
			vec.y /= scalar;
			vec.z /= scalar;
			return vec;
		}

		bool operator==(const Vector3& left, const Vector3& right)
		{
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		bool operator!=(const Vector3& left, const Vector3& right)
		{
			return !(left == right);
		}

		std::ostream& operator<<(std::ostream& os, const Vector3& vec)
		{
			os << "Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
			return os;
		}

	}
}
