#pragma once

#include "Core/Events/Event.h"

namespace Core
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		static EventType getStaticType() { return EventType::Close; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "WindowCloseEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::Window; }
	};


	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : m_width(width), m_height(height) {}

		unsigned int getWidth() const { return m_width; }
		unsigned int getHeight() const { return m_height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << "x" << m_height;
			return ss.str();
		}

		static EventType getStaticType() { return EventType::Resize; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "WindowResizeEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::Window; }

	private:
		unsigned int m_width, m_height;
	};


	class WindowFocusEvent : public Event
	{
		WindowFocusEvent() = default;

		static EventType getStaticType() { return EventType::Focus; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "WindowFocusEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::Window; }
	};


	class WindowLostFocusEvent : public Event
	{
		WindowLostFocusEvent() = default;

		static EventType getStaticType() { return EventType::LostFocus; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "WindowLostFocusEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::Window; }
	};


	class WindowMovedEvent : public Event
	{
		WindowMovedEvent() = default;

		static EventType getStaticType() { return EventType::Moved; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "WindowMovedEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::Window; }
	};
}
