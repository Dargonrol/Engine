#pragma once

#include "Core/Events/Event.h"
#include "Core/Core.h"

namespace Core
{
	struct WindowProperties
	{
		std::string title;
		uint32_t width;
		uint32_t height;

		WindowProperties(std::string title = "Untitled", uint32_t width = 400, uint32_t height = 400) : title(std::move(title)), width(width), height(height) {}
	};

	class Window
	{
	public:
		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual void setEventCallback(const std::function<void(Event&)>& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;
		virtual void setShown(bool enabled) const = 0;
		virtual bool isShown() const = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProperties& properties = WindowProperties());

	protected:
		struct WindowData
		{
			std::string title;
			uint32_t width, height;
			bool VSync;

			std::function<void(Event&)> eventCallBack;
		};
	};
}
