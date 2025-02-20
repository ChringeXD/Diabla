#include "dbpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"


#include <GLAD/glad.h> 


namespace Diabla {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	}

	Application::~Application() {}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatch(e);
		dispatch.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (std::vector<Layer*>::iterator it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.GetHandled())
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushLayer(overlay);
	}
}