#include <Diabla.h>

class ExampleLayer : public Diabla::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer") {}

	void OnUpdate() override
	{
		if (Diabla::Input::GetKeyDown(DB_KEY_TAB))
			DB_TRACE("Tab is pressd! (poll)");
	}

	void OnEvent(Diabla::Event& event) override
	{
		if (event.GetEventType() == Diabla::EventType::KeyPressed)
		{
			Diabla::KeyPressedEvent& e = (Diabla::KeyPressedEvent&)event;
			if(e.GetKeyCode() == DB_KEY_TAB)
				DB_TRACE("Tab is pressd! (event)");
		}
	}
};

class Sandbox : public Diabla::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Diabla::ImGuiLayer());
	}

	~Sandbox()
	{
		
	}
};

Diabla::Application* Diabla::CreateApplication()
{
	return new Sandbox();
}