#pragma once

#ifdef DB_PLATFORM_WINDOWS

extern Diabla::Application* Diabla::CreateApplication();

int main(int argc, char** argv)
{
	Diabla::Log::Init();

	DB_CORE_TRACE("Hello, {0}", "World!");

	Diabla::Application* app = Diabla::CreateApplication();
	app->Run();
	delete app;
}

#endif