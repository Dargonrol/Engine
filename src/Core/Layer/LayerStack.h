#pragma once
#include "Layer.h"


namespace Core
{
	class LayerStack
	{
	public:
		LayerStack() = default;
		~LayerStack();

		void pushLayer3D(Layer* layer);
		void pushLayer2D(Layer* layer);
		void pushLayerUI(Layer* layer);
		void pushLayerDEBUG(Layer* layer);

		void popLayer3D(Layer* layer);
		void popLayer2D(Layer* layer);
		void popLayerUI(Layer* layer);
		void popLayerDEBUG(Layer* layer);

		[[nodiscard]] unsigned long long getStackSize() const { return m_layers.size(); }

		typedef std::vector<Layer*> LayerVector;

		[[nodiscard]] LayerVector::iterator begin() { return m_layers.begin(); }
		[[nodiscard]] LayerVector::iterator end() { return m_layers.end(); }
		[[nodiscard]] LayerVector::reverse_iterator rbegin() { return m_layers.rbegin(); }
		[[nodiscard]] LayerVector::reverse_iterator rend() { return m_layers.rend(); }

		[[nodiscard]] LayerVector::const_iterator begin() const { return m_layers.begin(); }
		[[nodiscard]] LayerVector::const_iterator end()	const { return m_layers.end(); }
		[[nodiscard]] LayerVector::const_reverse_iterator rbegin() const { return m_layers.rbegin(); }
		[[nodiscard]] LayerVector::const_reverse_iterator rend() const { return m_layers.rend(); }

	private:
		LayerVector m_layers;

		unsigned int m_layerInsertIndex3D = 0;
		unsigned int m_layerInsertIndex2D = 0;
		unsigned int m_layerInsertIndexUI = 0;
	};
}
