#include "Vector2.h"

namespace icarus {
	namespace maths {

		const Vector2 Vector2::up = Vector2(0, 1);
		const Vector2 Vector2::down = Vector2(0, -1);
		const Vector2 Vector2::left = Vector2(-1, 0);
		const Vector2 Vector2::right = Vector2(1, 0);
		const Vector2 Vector2::zero = Vector2(0, 0);
		const Vector2 Vector2::one = Vector2(1, 1);

		Vector2::Vector2()
			: x(0.0f), y(0.0f)
		{
		}

		Vector2::Vector2(const float& x, const float& y)
			: x(x), y(y)
		{
		}

		Vector2 Vector2::Add(const Vector2& other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 Vector2::Subtract(const Vector2& other) const
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 Vector2::Multiply(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}

		Vector2 Vector2::Multiply(const float& scalar) const
		{
			return Vector2(x * scalar, y * scalar);
		}

		Vector2 Vector2::Divide(const Vector2& other) const
		{
			return Vector2(x / other.x, y / other.y);
		}

		Vector2 Vector2::Divide(const float& scalar) const
		{
			return Vector2(x / scalar, y / scalar);
		}

		Vector2 operator+(const Vector2& left, const Vector2& right)
		{
			return left.Add(right);
		}

		Vector2 operator-(const Vector2& left, const Vector2& right)
		{
			return left.Subtract(right);
		}

		Vector2 operator*(const Vector2& left, const Vector2& right)
		{
			return left.Multiply(right);
		}

		Vector2 operator*(const Vector2& vec, const float& scalar)
		{
			return vec.Multiply(scalar);
		}

		Vector2 operator/(const Vector2& left, const Vector2& right)
		{
			return left.Divide(right);
		}

		Vector2 operator/(const Vector2& vec, const float& scalar)
		{
			return vec.Divide(scalar);
		}

		Vector2 operator*=(Vector2& vec, const float& scalar)
		{
			vec.x *= scalar;
			vec.y *= scalar;
			return vec;
		}

		Vector2 operator/=(Vector2& vec, const float& scalar)
		{
			vec.x /= scalar;
			vec.y /= scalar;
			return vec;
		}

		bool operator==(const Vector2& left, const Vector2& right)
		{
			return left.x == right.x && left.y == right.y;
		}

		bool operator!=(const Vector2& left, const Vector2& right)
		{
			return !(left == right);
		}

		std::ostream& operator<<(std::ostream& os, const Vector2& vec)
		{
			os << "Vector2(" << vec.x << ", " << vec.y << ")";
			return os;
		}

	}
}
