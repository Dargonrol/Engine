#pragma once

#include "Core/Window/Window.h"
#include "bgfx/bgfx.h"
#include "Windows.h"

namespace Core
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow() override;

		virtual void onUpdate() override;

		virtual uint32_t getWidth() const override { return m_windowData.width; }
		virtual uint32_t getHeight() const override { return m_windowData.height; }

		virtual void setEventCallback(const std::function<void(Event&)>& callback) override;
		virtual void setVSync(bool enabled) override;
		virtual bool isVSync() const override { return m_windowData.VSync; }
		virtual void setShown(bool enabled) const override { enabled ? ShowWindow(m_hWND, SW_SHOW) : ShowWindow(m_hWND, SW_HIDE); }
		virtual bool isShown() const override { return IsWindowVisible(m_hWND); }

		virtual void* getNativeWindow() const override { return m_hWND; }

	private:
		inline void init(const WindowProperties& properties);
		inline void shutdown();

		inline void createHWND();
		inline static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	private:
		WindowData m_windowData;

		HWND m_hWND;
	};
}
