#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "maths.h"

namespace icarus {
	namespace maths {

		struct Matrix4x4
		{
			float elements[4 * 4];
			//union {
			//	Vector4 columns[4];
			//};

			Matrix4x4();
			Matrix4x4(float diagonal);

			Vector4& GetColumn(int index) const;

			Matrix4x4 Multiply(const Matrix4x4& other) const;
			friend Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right);
			friend Matrix4x4 operator*=(Matrix4x4& left, const Matrix4x4& right);

			static Matrix4x4 Identity();
			static Matrix4x4 Orthographic(float left, float right, float bottom, float top, float near, float far);
			static Matrix4x4 Perspective(float fov, float aspect, float near, float far);

			static Matrix4x4 Translate(float x, float y, float z);
			static Matrix4x4 Translate(const Vector3& translation);
			static Matrix4x4 TranslateX(float value);
			static Matrix4x4 TranslateY(float value);
			static Matrix4x4 TranslateZ(float value);

			static Matrix4x4 Scale(float x, float y, float z);
			static Matrix4x4 Scale(const Vector3& scale);
			static Matrix4x4 ScaleX(float scale);
			static Matrix4x4 ScaleY(float scale);
			static Matrix4x4 ScaleZ(float scale);

			static Matrix4x4 Rotate(float angle, float x, float y, float z);
			static Matrix4x4 Rotate(float angle, const Vector3& axis);
			static Matrix4x4 RotateX(float angle);
			static Matrix4x4 RotateY(float angle);
			static Matrix4x4 RotateZ(float angle);

			friend std::ostream& operator<<(std::ostream& os, const Matrix4x4& mat);
		};

	}
}
