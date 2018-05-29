#include "Renderer.h"

#include <iostream>

#include "../GL_STUFF.h"

namespace icarus {
	namespace graphics {

		Renderer::Renderer()
		{
		}


		Renderer::~Renderer()
		{
		}

		void Renderer::Clear() const
		{
			GLCall(glClearColor(0.3f, 0.3f, 0.3f, 1.0f));
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
		}
		void Renderer::Clear(float x, float y, float z, float w) const
		{
			GLCall(glClearColor(x, y, z, w));
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
		}

		void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
		{
			shader.Bind();
			ib.Bind();
			va.Bind();
			GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0));
		}

	}
}
