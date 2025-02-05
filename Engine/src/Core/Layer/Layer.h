#pragma once

#include "Core/Events/Event.h"

namespace Core
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer") : m_name(name) {}
		virtual ~Layer() = default;

		virtual void onAttach();
		virtual void onDetach();
		virtual void onUpdate() {} // deltatime??
		virtual void onEvent(Event& event) {}

		[[nodiscard]] const std::string& getName() const { return m_name; }

	private:
		std::string m_name;

	public:
		bool operator==(const Layer& other) const
		{
			return m_name == other.m_name;
		}
	};
}

