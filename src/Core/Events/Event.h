#pragma once

#include "pch.h"

// EVENT SYSTEM FROM "The Cherno"!

namespace Core
{
	enum class EventType : uint8_t
	{
		None = 0,
		Close, Resize, Focus, LostFocus, Moved,								// handled in ApplicationEvent.h
		KeyPressed, KeyReleased, KeyTyped,									// handled in KeyEvent.h
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled	// handled in MouseEvent.h
	};

	enum EventCategory : uint8_t
	{
		None		= 0b00000,
		Window		= 0b00001,
		Input		= 0b00010,
		Keyboard	= 0b00100,
		Mouse		= 0b01000,
		MouseButton	= 0b10000
	};


	class Event
	{
	public:
		virtual ~Event() = default;

		bool handled = false;

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual uint8_t getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		bool isInCategory(EventCategory category) const
		{
			return getCategoryFlags() & category;
		}


		class EventDispatcher
		{
		public:
			EventDispatcher(Event& event) : m_event(event) {}

			template<typename T>
			bool Dispatch(const T& func)
			{
				if (m_event.getEventType() == T::GetStaticType())
				{
					m_event.handled |= func(static_cast<T&>(m_event));
					return true;
				}
				return false;
			}

		private:
			Event& m_event;
		};

		inline std::ostream& operator<<(std::ostream& os, const Event& e) const
		{
			return os << e.toString();
		}
	};
}

