#pragma once

#include "Diabla/Layer.h"

#include "Diabla/Events/ApplicationEvent.h"
#include "Diabla/Events/KeyEvent.h"
#include "Diabla/Events/MouseEvent.h"

namespace Diabla {

	class DIABLA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:

		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);

		float m_Time = 0.0f;
	};
}