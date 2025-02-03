#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"
#include "Diabla/Log.h"

#include <sstream>
#include <iostream>

namespace Diabla {

	Application::Application() {}
	Application::~Application() {}

	void Application::Run()
	{
		MouseMovedEvent e(10.0f, 5.0f);

		DB_TRACE(e);

		while (true);
	}
}