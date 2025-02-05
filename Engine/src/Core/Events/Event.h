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
		EventWindow		= 0b00001,
		EventInput		= 0b00010,
		EventKeyboard	= 0b00100,
		EventMouse		= 0b01000,
		EventMouseButton	= 0b10000
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
			template<typename T>
			using EventFn = std::function<bool(T&)>;
		public:
			EventDispatcher(Event& event) : m_event(event) {}

			template<typename T>
			bool Dispatch(EventFn<T> func)
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
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}
}

