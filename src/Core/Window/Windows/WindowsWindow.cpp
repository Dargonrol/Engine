#include "pch.h"
#include "WindowsWindow.h"

#include "Core/Log.h"

namespace Core
{
	static bool s_bgfxInitialized = false;

	Window* Window::create(const WindowProperties& properties)
	{
		return new WindowsWindow(properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& properties)
	{
		init(properties);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::init(const WindowProperties& properties)
	{
		m_windowData.title = properties.title;
		m_windowData.width = properties.width;
		m_windowData.height = properties.height;

		CORE_LOG_INFO("Creating new window {0}, {1},x{2}", properties.title, properties.width, properties.height);

		createHWND();

		if (true) //!s_bgfxInitialized
		{
			bgfx::Init bgfxInit;
			bgfxInit.platformData.nwh = m_hWND;
			bgfxInit.type = bgfx::RendererType::Count; // Automatically chooses a renderer
			bgfxInit.resolution.width = properties.width;
			bgfxInit.resolution.height = properties.height;
			bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
			bgfx::init(bgfxInit);
		}
	}

	void WindowsWindow::shutdown()
	{
		bgfx::shutdown();
	}

	void WindowsWindow::onUpdate()
	{
	}

	void WindowsWindow::setEventCallback(const std::function<void(Event&)>& callback)
	{
	}

	void WindowsWindow::setVSync(bool enabled)
	{
	}

	void WindowsWindow::createHWND()
	{
		HINSTANCE hInstance = GetModuleHandle(nullptr);
		const wchar_t CLASS_NAME[] = L"WindowClass";

		WNDCLASS wc = {};
		wc.lpfnWndProc = WindowsWindow::WindowProc;
		wc.hInstance = hInstance;
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);

		m_hWND = CreateWindowEx(
			0,
			CLASS_NAME,
			std::wstring(m_windowData.title.begin(), m_windowData.title.end()).c_str(),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, m_windowData.width, m_windowData.height,
			nullptr,
			nullptr,
			hInstance,
			nullptr
		);
	}


	LRESULT WindowsWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			case WM_DESTROY:
				PostQuitMessage(0);
				return 0;

			default:
				CORE_LOG_TRACE("unhandled win32 window event: {0}", uMsg);
		}
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}


}
