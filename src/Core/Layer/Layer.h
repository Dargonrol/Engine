#pragma once

#include "Core/Events/Event.h"

namespace Core
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer") : m_name(name) {}
		virtual ~Layer() = default;

		virtual void onAttack();
		virtual void onDetach();
		virtual void onUpdate() {} // deltatime??
		virtual void onEvent(Event& event) {}

		[[nodiscard]] const std::string& getName() const { return m_name; }

	private:
		std::string m_name;
	};
}

