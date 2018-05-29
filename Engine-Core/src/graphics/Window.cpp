#include <iostream>
#include "Window.h"

namespace icarus {
	namespace graphics {

		void resize_callback(GLFWwindow* window, int width, int height)
		{
			Window* myWindow = (Window*)glfwGetWindowUserPointer(window);
			myWindow->m_Width = width;
			myWindow->m_Height = height;
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			std::cout << "Key: " << key << ":" << scancode << ":" << action << std::endl;
			if (key < 0) {
				// Key isn't a real key. Like FN key?
				return;
			}
			Window* myWindow = (Window*)glfwGetWindowUserPointer(window);
			myWindow->m_Keys[key] = action != GLFW_RELEASE;

			// TODO: Move out to main and provide a ->close method
			if (key == GLFW_KEY_ESCAPE) {
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}
		}

		void cursor_callback(GLFWwindow* window, double x, double y)
		{
			Window* myWindow = (Window*)glfwGetWindowUserPointer(window);
			myWindow->m_Mx = x;
			myWindow->m_My = y;
			std::cout << "Cursor: " << x << ", " << y << std::endl;
		}

		void button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* myWindow = (Window*)glfwGetWindowUserPointer(window);
			myWindow->m_MouseButtons[button] = action != GLFW_RELEASE;
			std::cout << "MButton: " << button << ":" << action << std::endl;
		}

		Window::Window(const char* name, const int width, const int height, bool vsync)
			: m_Name(name), m_Width(width), m_Height(height)
		{
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, nullptr, nullptr);

			if (!m_Window) {
				glfwTerminate();
				std::cerr << "Failed to create GLFW window!" << std::endl;
				return;
			}

			glfwSetWindowUserPointer(m_Window, this);

			glfwMakeContextCurrent(m_Window);
			if (vsync) {
				glfwSwapInterval(1);
			}

			glfwSetKeyCallback(m_Window, &key_callback);
			glfwSetCursorPosCallback(m_Window, &cursor_callback);
			glfwSetWindowSizeCallback(m_Window, &resize_callback);
			glfwSetMouseButtonCallback(m_Window, &button_callback);

			if (glewInit() != GLEW_OK) {
				std::cerr << "Failed to initialize GLEW!" << std::endl;
				return;
			}

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwDestroyWindow(m_Window);
		}

		void Window::Update() const
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

		bool Window::ShouldClose() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		//void Window::SetWidth(int width)
		//{
		//	m_Width = width;
		//}
		//
		//void Window::SetHeight(int height)
		//{
		//	m_Height = height;
		//}

		int Window::GetWidth() const
		{
			return m_Width;
		}

		int Window::GetHeight() const
		{
			return m_Height;
		}

		void Window::GetMousePosition(double & outX, double & outY) const
		{
			outX = m_Mx;
			outY = m_My;
		}

		GLFWwindow* Window::GetGLFWWindow() const
		{
			return m_Window;
		}

	}
}
