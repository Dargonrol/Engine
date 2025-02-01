#pragma once
#include "pch.h"
#include "Core/Application.h"

extern Core::Application* Core::CreateApplication();

int main(int argc, char** argv)
{
	Core::Log::Init();
	CORE_LOG_WARN("Hello world");

	auto app = Core::CreateApplication();
	app->Init();
	app->Run();
	delete app;
}