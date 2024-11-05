#pragma once

#ifdef DB_PLATFORM_WINDOWS

extern Diabla::Application* Diabla::CreateApplication();

int main(int argc, char** argv)
{
	printf("ur MOM blud");
	Diabla::Application* app = Diabla::CreateApplication();
	app->Run();
	delete app;
}

#endif