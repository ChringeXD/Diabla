#include <Diabla.h>

class ExampleLayer : public Diabla::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer") {}

	void OnEvent(Diabla::Event& e) override
	{
		DB_TRACE(e);
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