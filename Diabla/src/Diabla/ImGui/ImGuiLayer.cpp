#include "dbpch.h"
#include "ImGuiLayer.h"

#include <imgui.h> 
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <Platform/OpenGL/imgui_impl_opengl3.h>

#include "Diabla/KeyCodes.h"
#include "Diabla/MouseButtonCodes.h"

#include "Diabla/Application.h"

namespace Diabla {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") {}

	ImGuiLayer::~ImGuiLayer() {}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.KeyMap[ImGuiKey_Tab] = DB_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = DB_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = DB_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = DB_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = DB_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = DB_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = DB_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = DB_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = DB_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = DB_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = DB_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = DB_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = DB_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = DB_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = DB_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_LeftCtrl] = DB_KEY_LEFT_CONTROL;
		io.KeyMap[ImGuiKey_LeftShift] = DB_KEY_LEFT_SHIFT;
		io.KeyMap[ImGuiKey_LeftAlt] = DB_KEY_LEFT_ALT;
		io.KeyMap[ImGuiKey_LeftSuper] = DB_KEY_LEFT_SUPER;
		io.KeyMap[ImGuiKey_RightCtrl] = DB_KEY_RIGHT_CONTROL;
		io.KeyMap[ImGuiKey_RightShift] = DB_KEY_RIGHT_SHIFT;
		io.KeyMap[ImGuiKey_RightAlt] = DB_KEY_RIGHT_ALT;
		io.KeyMap[ImGuiKey_RightSuper] = DB_KEY_RIGHT_SUPER;
		io.KeyMap[ImGuiKey_A] = DB_KEY_A;
		io.KeyMap[ImGuiKey_B] = DB_KEY_B;
		io.KeyMap[ImGuiKey_C] = DB_KEY_C;
		io.KeyMap[ImGuiKey_D] = DB_KEY_D;
		io.KeyMap[ImGuiKey_E] = DB_KEY_E;
		io.KeyMap[ImGuiKey_F] = DB_KEY_F;
		io.KeyMap[ImGuiKey_G] = DB_KEY_G;
		io.KeyMap[ImGuiKey_H] = DB_KEY_H;
		io.KeyMap[ImGuiKey_I] = DB_KEY_I;
		io.KeyMap[ImGuiKey_J] = DB_KEY_J;
		io.KeyMap[ImGuiKey_K] = DB_KEY_K;
		io.KeyMap[ImGuiKey_L] = DB_KEY_L;
		io.KeyMap[ImGuiKey_M] = DB_KEY_M;
		io.KeyMap[ImGuiKey_N] = DB_KEY_N;
		io.KeyMap[ImGuiKey_O] = DB_KEY_O;
		io.KeyMap[ImGuiKey_P] = DB_KEY_P;
		io.KeyMap[ImGuiKey_Q] = DB_KEY_Q;
		io.KeyMap[ImGuiKey_R] = DB_KEY_R;
		io.KeyMap[ImGuiKey_S] = DB_KEY_S;
		io.KeyMap[ImGuiKey_T] = DB_KEY_T;
		io.KeyMap[ImGuiKey_U] = DB_KEY_U;
		io.KeyMap[ImGuiKey_V] = DB_KEY_V;
		io.KeyMap[ImGuiKey_W] = DB_KEY_W;
		io.KeyMap[ImGuiKey_X] = DB_KEY_X;
		io.KeyMap[ImGuiKey_Y] = DB_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = DB_KEY_Z;
		io.KeyMap[ImGuiKey_F1] = DB_KEY_F1;
		io.KeyMap[ImGuiKey_F2] = DB_KEY_F2;
		io.KeyMap[ImGuiKey_F3] = DB_KEY_F3;
		io.KeyMap[ImGuiKey_F4] = DB_KEY_F4;
		io.KeyMap[ImGuiKey_F5] = DB_KEY_F5;
		io.KeyMap[ImGuiKey_F6] = DB_KEY_F6;
		io.KeyMap[ImGuiKey_F7] = DB_KEY_F7;
		io.KeyMap[ImGuiKey_F8] = DB_KEY_F8;
		io.KeyMap[ImGuiKey_F9] = DB_KEY_F9;
		io.KeyMap[ImGuiKey_F10] = DB_KEY_F10;
		io.KeyMap[ImGuiKey_F11] = DB_KEY_F11;
		io.KeyMap[ImGuiKey_F12] = DB_KEY_F12;
		io.KeyMap[ImGuiKey_Apostrophe] = DB_KEY_APOSTROPHE;
		io.KeyMap[ImGuiKey_Comma] = DB_KEY_COMMA;
		io.KeyMap[ImGuiKey_Minus] = DB_KEY_MINUS;
		io.KeyMap[ImGuiKey_Period] = DB_KEY_PERIOD;
		io.KeyMap[ImGuiKey_Slash] = DB_KEY_SLASH;
		io.KeyMap[ImGuiKey_Semicolon] = DB_KEY_SEMICOLON;
		io.KeyMap[ImGuiKey_Equal] = DB_KEY_EQUAL;
		io.KeyMap[ImGuiKey_LeftBracket] = DB_KEY_LEFT_BRACKET;
		io.KeyMap[ImGuiKey_Backslash] = DB_KEY_BACKSLASH;
		io.KeyMap[ImGuiKey_RightBracket] = DB_KEY_RIGHT_BRACKET;
		io.KeyMap[ImGuiKey_GraveAccent] = DB_KEY_GRAVE_ACCENT;
		io.KeyMap[ImGuiKey_CapsLock] = DB_KEY_CAPS_LOCK;
		io.KeyMap[ImGuiKey_ScrollLock] = DB_KEY_SCROLL_LOCK;
		io.KeyMap[ImGuiKey_NumLock] = DB_KEY_NUM_LOCK;
		io.KeyMap[ImGuiKey_PrintScreen] = DB_KEY_PRINT_SCREEN;
		io.KeyMap[ImGuiKey_Pause] = DB_KEY_PAUSE;
		io.KeyMap[ImGuiKey_Keypad0] = DB_KEY_KP_0;
		io.KeyMap[ImGuiKey_Keypad1] = DB_KEY_KP_1;
		io.KeyMap[ImGuiKey_Keypad2] = DB_KEY_KP_2;
		io.KeyMap[ImGuiKey_Keypad3] = DB_KEY_KP_3;
		io.KeyMap[ImGuiKey_Keypad4] = DB_KEY_KP_4;
		io.KeyMap[ImGuiKey_Keypad5] = DB_KEY_KP_5;
		io.KeyMap[ImGuiKey_Keypad6] = DB_KEY_KP_6;
		io.KeyMap[ImGuiKey_Keypad7] = DB_KEY_KP_7;
		io.KeyMap[ImGuiKey_Keypad8] = DB_KEY_KP_8;
		io.KeyMap[ImGuiKey_Keypad9] = DB_KEY_KP_9;
		io.KeyMap[ImGuiKey_KeypadDecimal] = DB_KEY_KP_DECIMAL;
		io.KeyMap[ImGuiKey_KeypadDivide] = DB_KEY_KP_DIVIDE;
		io.KeyMap[ImGuiKey_KeypadMultiply] = DB_KEY_KP_MULTIPLY;
		io.KeyMap[ImGuiKey_KeypadSubtract] = DB_KEY_KP_SUBTRACT;
		io.KeyMap[ImGuiKey_KeypadAdd] = DB_KEY_KP_ADD;
		io.KeyMap[ImGuiKey_KeypadEnter] = DB_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_KeypadEqual] = DB_KEY_KP_EQUAL;

		ImGui_ImplOpenGL3_Init("#version 460 core");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		Window& window = app.GetWindow();
		io.DisplaySize = ImVec2((float)window.GetWidth(), (float)window.GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);


		ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatch(event);

		dispatch.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
		dispatch.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatch.Dispatch<KeyReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatch.Dispatch<KeyTypedEvent>(BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatch.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatch.Dispatch<MouseButtonReleasedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatch.Dispatch<MouseMovedEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatch.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)e.GetWidth(), (float)e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = true;
		
		io.KeyCtrl = io.KeysDown[DB_KEY_LEFT_CONTROL] || io.KeysDown[DB_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[DB_KEY_LEFT_SHIFT] || io.KeysDown[DB_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[DB_KEY_LEFT_ALT] || io.KeysDown[DB_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[DB_KEY_LEFT_SUPER] || io.KeysDown[DB_KEY_RIGHT_SUPER];
		
		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.KeysDown[e.GetKeyCode()] = false;

		io.KeyCtrl = io.KeysDown[DB_KEY_LEFT_CONTROL] || io.KeysDown[DB_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[DB_KEY_LEFT_SHIFT] || io.KeysDown[DB_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[DB_KEY_LEFT_ALT] || io.KeysDown[DB_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[DB_KEY_LEFT_SUPER] || io.KeysDown[DB_KEY_RIGHT_SUPER];

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		//io.KeysDown[e.GetKeyCode()] = true;

		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);

		return false;
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.GetOffset();

		return false;
	}
}