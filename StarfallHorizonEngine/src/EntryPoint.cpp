#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
	sh::Application* app = GetApplication();
	app->Run();

	delete app;
}