#include <iostream>

#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/maths/maths.h"
#include "src/utils/file.h"

#include "src/graphics/Renderer.h"
#include "src/graphics/VertexBuffer.h"
#include "src/graphics/IndexBuffer.h"
#include "src/graphics/VertexArray.h"
#include "src/graphics/VertexBufferLayout.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"
#include "imgui/imgui_internal.h"

#if 0
#include <Windows.h>
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}
#endif

#define WIDTH 960
#define HEIGHT 540

int main()
{

	using namespace icarus::graphics;
	using namespace icarus::maths;

	std::cout << "Hello World!" << std::endl;

#if 0
	std::cout << (1 - 0.3f) << std::endl;

	Vector4 vec(10, 10, 12, 5);
	Vector4 vec2(5, 5, 8, 9.3f);

	std::cout << vec << std::endl;
	std::cout << vec2 << std::endl;
	std::cout << vec + vec2 << std::endl;
	std::cout << vec * vec2 << std::endl;
	std::cout << vec * 2.5f << std::endl;
	std::cout << (vec == vec2) << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << vec << std::endl;
	vec *= 5;
	std::cout << vec << std::endl;
	std::cout << (vec *= 2) << std::endl;
	std::cout << vec << std::endl;
	std::cout << "----------------------" << std::endl;

	Matrix4x4 mat = Matrix4x4::Identity();
	Matrix4x4 mat2 = Matrix4x4::Identity();

	std::cout << (mat * mat2) << std::endl;
	std::cout << "----------------------" << std::endl;

	Matrix4x4 position = Matrix4x4::Translate(2, 3, 4);

	std::cout << position << std::endl;
	Vector4& column = position.GetColumn(3);
	std::cout << column << std::endl;

	std::cout << position.elements[12] << std::endl;
	column.x++;
	std::cout << position.elements[12] << std::endl;
#endif

	if (!glfwInit()) {
		return -1;
	}

	Window window("Game Engine", WIDTH, HEIGHT, true);

	std::cout << glGetString(GL_VERSION) << std::endl;

	{
		glClearColor(0.0f, 0.5f, 0.8f, 1.0f);

		GLfloat vertices[] =
		{
			//-0.5f, -0.5f, 0,
			//-0.5f,  0.5f, 0,
			// 0.5f,  0.5f, 0,
			// 0.5f,  0.5f, 0,
			// 0.5f, -0.5f, 0,
			//-0.5f, -0.5f, 0,

			0, 0, 0, // 0
			0, 3, 0, // 1
			8, 3, 0, // 2
			8, 0, 0, // 3
		};

		GLuint indicies[] =
		{
			0, 1, 2,
			2, 3, 0,
		};

		VertexArray va;
		VertexBuffer vb(vertices, 4 * 3 * sizeof(GLfloat));
		VertexBufferLayout layout;
		layout.Push<float>(3);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indicies, 6);

		Shader shader("src/shaders/Basic.shader");
		Matrix4x4 model(1.0f);
		//model *= Matrix4x4::Rotate(45, 0, 0, 1);
		//model *= Matrix4x4::Scale(1, 0.5f, 1);
		//model *= Matrix4x4::Translate(4, 3, 0);
		//model = Matrix4x4::Identity();
		Matrix4x4 view = Matrix4x4::Identity();
		Matrix4x4 proj = Matrix4x4::Orthographic(0, 16, 0, 9, -1, 1);

		shader.Bind();
		shader.SetUniformMat4f("u_MVP", proj * view * model);
		shader.SetUniform4f("u_Color", Vector4(0.2f, 0.3f, 0.8f, 1.0f));
		shader.SetUniform2f("u_LightPos", Vector2(4, 1.5f));

		Renderer renderer;

		ImGuiContext* imguiContext = ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window.GetGLFWWindow(), false);
		ImGui::StyleColorsDark();

		float r = 0.0f;
		float incrementR = 0.05f;
		float lightXPos = 4.0f;
		float incrementL = 0.05f;
		while (!window.ShouldClose()) {
			//std::cout << window.GetWidth() << std::endl;
			renderer.Clear();

			ImGui_ImplGlfwGL3_NewFrame();

			// 1. Show a simple window.
			// Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
			{
				static float f = 0.0f;
				static int counter = 0;
				ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
				//ImGui::SliderFloat3("Translation", &translation.x, 0.0f, WIDTH);
				//ImGui::SliderFloat3("Camera", &camera.x, 0.0f, WIDTH);
				//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
			}


			shader.Bind();
			model = Matrix4x4::Translate(4, 3, 0);
			shader.SetUniformMat4f("u_MVP", proj * view * model);
			shader.SetUniformMat4f("u_modelMat", model);
			shader.SetUniform4f("u_Color", Vector4(r, 0.3f, 0.8f, 1.0f));
			double x, y;
			window.GetMousePosition(x, y);
			//shader.SetUniform2f("u_LightPos", Vector2(lightXPos, 1.5f));
			shader.SetUniform2f("u_LightPos", Vector2((float)x * 16.0f / 960.0f, 9.0f - (float)y * 9.0f / 540.0f));

			renderer.Draw(va, ib, shader);
			model = Matrix4x4::Translate(0, 0, 0);
			shader.SetUniformMat4f("u_MVP", proj * view * model);
			shader.SetUniformMat4f("u_modelMat", model);
			renderer.Draw(va, ib, shader);

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			if (r > 1.0f) {
				incrementR = -0.05f;
			} else if (r < 0.0f) {
				incrementR = 0.05f;
			}

			r += incrementR;

			//if (lightXPos > 8.0f) {
			//	incrementL = -0.05f;
			//} else if (lightXPos < 0.0f) {
			//	incrementL = 0.05f;
			//}

			//lightXPos += incrementL;

			window.Update();
		}
	}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();

	return 0;
}