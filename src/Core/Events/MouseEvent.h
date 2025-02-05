#pragma once

#include "Core/Events/Event.h"
#include "Core/MouseCodes.h"

namespace Core
{
	class MouseButtonEvent : public Event
	{
	public:
		MouseCode getMouseButton() const { return m_Button; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::EventMouse | EventCategory::EventMouseButton | EventCategory::EventInput; }

	protected:
		MouseButtonEvent(const MouseCode button) : m_Button(button) {}

		MouseCode m_Button;
	};


	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		static EventType getStaticType() { return EventType::MouseButtonPressed; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "MouseButtonPressedEvent"; }
	};


	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		static EventType getStaticType() { return EventType::MouseButtonReleased; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "MouseButtonReleasedEvent"; }
	};


	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float x, const float y) : m_mouseX(x), m_mouseY(y) {}

		float getX() const { return m_mouseX; }
		float getY() const { return m_mouseY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		static EventType getStaticType() { return EventType::MouseMoved; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "MouseMovedEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::EventMouse | EventCategory::EventInput; }

	private:
		float m_mouseX, m_mouseY;
	};

	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float xOffset, const float yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

		float getXOffset() const { return m_xOffset; }
		float getYOffset() const { return m_yOffset; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}

		static EventType getStaticType() { return EventType::MouseScrolled; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "MouseScrolledEvent"; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::EventMouse | EventCategory::EventInput; }

	private:
		float m_xOffset, m_yOffset;
	};
}
