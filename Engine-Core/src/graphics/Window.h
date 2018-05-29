#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace icarus {
	namespace graphics {

		class Window
		{
		private:
			GLFWwindow * m_Window;
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double m_Mx, m_My;
		protected:
			const char* m_Name;
			int m_Width;
			int m_Height;
		private:
			friend void resize_callback(GLFWwindow* window, int width, int height);
			friend void button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_callback(GLFWwindow* window, double x, double y);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		public:
			Window(const char* name, const int width, const int height, bool vsync = false);
			virtual ~Window();

			void Update() const;
			bool ShouldClose() const;
			int GetWidth() const;
			int GetHeight() const;
			void GetMousePosition(double& outX, double& outY) const;
			//void SetWidth(int width);
			//void SetHeight(int height);
			GLFWwindow* GetGLFWWindow() const;
		};

	}
}
