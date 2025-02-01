#pragma once
#include "pch.h"
#include "Core.h"

namespace Core {

	class CORE_API Application
	{
	public:

		Application();
		virtual ~Application();

		Core::Error Init();
		Core::Error Run();

	private:
		struct AppContext {
		} appContext;

	};

	Application* CreateApplication(); // needs to be defined by client

}

