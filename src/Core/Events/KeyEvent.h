#pragma once

#include "Core/Events/Event.h"
#include "Core/KeyCodes.h"

// EVENT SYSTEM FROM "The Cherno"!

namespace Core
{
	class KeyEvent : public Event
	{
	public:
		KeyCode getKeyCode() const { return m_KeyCode; }

		virtual uint8_t getCategoryFlags() const override { return EventCategory::EventKeyboard | EventCategory::EventInput; }

	protected:
		KeyEvent(const KeyCode keyCode) : m_KeyCode(keyCode) {}

		KeyCode m_KeyCode;
	};


	class KeyPressedEvent : public KeyEvent
	{
		KeyPressedEvent(const KeyCode keyCode, bool isRepeat = false) : KeyEvent(keyCode), m_isRepeat(isRepeat) {}

		bool isRepeat() const { return m_isRepeat; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_isRepeat << ")";
			return ss.str();
		}

		static EventType getStaticType() { return EventType::KeyPressed; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "KeyPressedEvent"; }

	private:
		bool m_isRepeat;
	};


	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		static EventType getStaticType() { return EventType::KeyReleased; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "KeyReleasedEvent"; }
		
	};


	class KeyTypedEvent : public KeyEvent
	{
		KeyTypedEvent(const KeyCode keyCode) : KeyEvent(keyCode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		static EventType getStaticType() { return EventType::KeyTyped; }
		virtual EventType getEventType() const override { return getStaticType(); }
		virtual const char* getName() const override { return "KeyTypedEvent"; }

	};
}