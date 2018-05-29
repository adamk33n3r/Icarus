#include "Matrix4x4.h"

namespace icarus {
	namespace maths {

		Matrix4x4::Matrix4x4()
		{
			for (int i = 0; i < 4 * 4; i++)
				elements[i] = 0.0f;
		}

		Matrix4x4::Matrix4x4(float diagonal)
			: Matrix4x4()
		{
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		Vector4& Matrix4x4::GetColumn(int index) const
		{
			return *(Vector4*)(elements + (index * 4));
		}

		Matrix4x4 Matrix4x4::Multiply(const Matrix4x4& other) const
		{
			Matrix4x4 result;

			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					result.elements[x + y * 4] = sum;
				}
			}

			return result;
		}

		Matrix4x4 Matrix4x4::Identity()
		{
			return Matrix4x4(1.0f);
		}

		Matrix4x4 Matrix4x4::Orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			Matrix4x4 result(1.0f);

			// Diagonals
			result.elements[0 + 0 * 4] = 2.0f / (right - left);
			result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.elements[2 + 2 * 4] = 2.0f / (near - far);

			// W
			//result.elements[0 + 3 * 4] = (right + left) / (right - left);
			//result.elements[1 + 3 * 4] = (top + bottom) / (top - bottom);
			result.elements[0 + 3 * 4] = (right + left) / (left - right);
			result.elements[1 + 3 * 4] = (top + bottom) / (bottom - top);

			result.elements[2 + 3 * 4] = (far + near) / (far - near);

			return result;
		}

		Matrix4x4 Matrix4x4::Perspective(float fov, float aspect, float near, float far)
		{
			Matrix4x4 result;

			float q = 1.0f / tanf(maths::to_radians(0.5f * fov));
			result.elements[0 + 0 * 4] = q / aspect;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = (-near - far) / (near - far);
			result.elements[2 + 3 * 4] = (2 * near * far) / (near - far);
			result.elements[3 + 2 * 4] = 1;

			return result;
		}

		Matrix4x4 Matrix4x4::Translate(float x, float y, float z)
		{
			Matrix4x4 result(1.0f);

			result.elements[0 + 3 * 4] = x;
			result.elements[1 + 3 * 4] = y;
			result.elements[2 + 3 * 4] = z;

			return result;
		}

		Matrix4x4 Matrix4x4::Translate(const Vector3& translation)
		{
			return Translate(translation.x, translation.y, translation.z);
		}

		Matrix4x4 Matrix4x4::TranslateX(float value)
		{
			return Translate(value, 0, 0);
		}

		Matrix4x4 Matrix4x4::TranslateY(float value)
		{
			return Translate(0, value, 0);
		}

		Matrix4x4 Matrix4x4::TranslateZ(float value)
		{
			return Translate(0, 0, value);
		}

		Matrix4x4 Matrix4x4::Scale(float x, float y, float z)
		{
			Matrix4x4 result(1.0f);

			result.elements[0 + 0 * 4] = x;
			result.elements[1 + 1 * 4] = y;
			result.elements[2 + 2 * 4] = z;

			return result;
		}

		Matrix4x4 Matrix4x4::Scale(const Vector3& scale)
		{
			return Scale(scale.x, scale.y, scale.z);
		}

		Matrix4x4 Matrix4x4::ScaleX(float scale)
		{
			return Scale(scale, 0, 0);
		}

		Matrix4x4 Matrix4x4::ScaleY(float scale)
		{
			return Scale(0, scale, 0);
		}

		Matrix4x4 Matrix4x4::ScaleZ(float scale)
		{
			return Scale(0, 0, scale);
		}

		Matrix4x4 Matrix4x4::Rotate(float angle, float x, float y, float z)
		{
			Matrix4x4 result(1.0f);

			float r = maths::to_radians(angle);
			float s = std::sin(r);
			float c = std::cos(r);

			result.elements[0 + 0 * 4] = x * (1 - c) + c;
			result.elements[1 + 0 * 4] = x * y * (1 - c) + z * s;
			result.elements[2 + 0 * 4] = x * z * (1 - c) - y * s;

			result.elements[0 + 1 * 4] = x * y * (1 - c) - z * s;
			result.elements[1 + 1 * 4] = y * (1 - c) + c;
			result.elements[2 + 1 * 4] = y * z * (1 - c) + x * s;

			result.elements[0 + 2 * 4] = x * z * (1 - c) + y * s;
			result.elements[1 + 2 * 4] = y * z * (1 - c) - x * s;
			result.elements[2 + 2 * 4] = z * (1 - c) + c;

			// Formula from http://www.songho.ca/opengl/gl_matrix.html
			//result.elements[0 + 0 * 4] = x * x * (1 - c) + c;
			//result.elements[0 + 1 * 4] = x * y * (1 - c) - z * s;
			//result.elements[1 + 0 * 4] = x * y * (1 - c) + z * s;
			//result.elements[0 + 2 * 4] = x * z * (1 - c) + y * s;
			//result.elements[2 + 0 * 4] = x * z * (1 - c) - y * s;

			//result.elements[1 + 1 * 4] = y * y * (1 - c) + c;
			//result.elements[2 + 1 * 4] = y * z * (1 - c) + x * s;
			//result.elements[1 + 2 * 4] = y * z * (1 - c) - x * s;

			//result.elements[2 + 2 * 4] = z * z * (1 - c) + c;

			return result;
		}

		Matrix4x4 Matrix4x4::Rotate(float angle, const Vector3& axis)
		{
			return Rotate(angle, axis.x, axis.y, axis.z);
		}

		Matrix4x4 Matrix4x4::RotateX(float angle)
		{
			return Rotate(angle, 1, 0, 0);
		}

		Matrix4x4 Matrix4x4::RotateY(float angle)
		{
			return Rotate(angle, 0, 1, 0);
		}

		Matrix4x4 Matrix4x4::RotateZ(float angle)
		{
			return Rotate(angle, 0, 0, 1);
		}

		Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right)
		{
			return left.Multiply(right);
		}

		Matrix4x4 operator*=(Matrix4x4& left, const Matrix4x4& right)
		{
			left = left.Multiply(right);
			return left;
		}

		std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat)
		{
			os << "Matrix4x4:" << std::endl;

			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					os << mat.elements[y + x * 4] << ", ";
				}

				os << std::endl;
			}

			return os;
		}
	}
}
