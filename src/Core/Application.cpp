#include "pch.h"
#include "Application.h"
#include "Log.h"

namespace Core {
	Application::Application() 
	{

	}

	Application::~Application()
	{

	}

	Core::Error Application::Run()
	{
		bool running = true;
		
		while (running)
		{

		}
		return Core::Error::CORE_SUCCESS;
	}

	Core::Error Application::Init()
	{
		CORE_LOG_INFO("SDL initialized!");
		return Core::Error::CORE_SUCCESS;
	}
}