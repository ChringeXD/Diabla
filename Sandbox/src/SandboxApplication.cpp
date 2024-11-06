#include <Diabla.h>

class Sandbox : public Diabla::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}
};

Diabla::Application* Diabla::CreateApplication()
{
	return new Sandbox();
}