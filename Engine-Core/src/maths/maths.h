#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

namespace icarus {
	namespace maths {

		inline float to_radians(float degrees)
		{
			return (float)((degrees * M_PI) / 180);
		}

		inline float to_degrees(float radians)
		{
			return (float)((radians * 180) / M_PI);
		}

	}
}
