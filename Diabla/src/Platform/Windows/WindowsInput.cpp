#include "dbpch.h"
#include "WindowsInput.h"

#include "Diabla/Application.h"
#include <GLFW/glfw3.h>

namespace Diabla {
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::GetKeyDownImpl(int keycode) {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	
	bool WindowsInput::GetMouseButtonDownImpl(int button) {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl() {
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float WindowsInput::GetMouseXImpl() {
		std::pair<float, float> pos = GetMousePositionImpl();
		return pos.first;
	}

	float WindowsInput::GetMouseYImpl() {
		std::pair<float, float> pos = GetMousePositionImpl();
		return pos.second;
	}
}