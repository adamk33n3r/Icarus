#pragma once

#include <GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace icarus {
	namespace graphics {

		class Renderer
		{
		public:
			Renderer();
			~Renderer();

			void Clear() const;
			void Clear(float x, float y, float z, float w) const;
			void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
		};

	}
}
