#include "pch.h"
#include "LayerStack.h"

namespace Core
{
	LayerStack::~LayerStack()
	{
		for (Layer* layer: m_layers)
		{
			layer->onDetach();
			delete layer;
		}
	}

	void LayerStack::pushLayer3D(Layer* layer)
	{
		m_layers.emplace(m_layers.begin() + m_layerInsertIndex3D, layer);
		m_layerInsertIndex3D++;
		layer->onAttach();
	}

	void LayerStack::pushLayer2D(Layer* layer)
	{
		m_layers.emplace(m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D, layer);
		m_layerInsertIndex2D++;
		layer->onAttach();
	}

	void LayerStack::pushLayerUI(Layer* layer)
	{
		m_layers.emplace(m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D + m_layerInsertIndexUI, layer);
		m_layerInsertIndexUI++;
		layer->onAttach();
	}

	void LayerStack::pushLayerDEBUG(Layer* layer)
	{
		m_layers.emplace_back(layer);
		layer->onAttach();
	}

	void LayerStack::popLayer3D(Layer* layer)
	{
		auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex3D, layer);
		if (it != m_layers.begin() + m_layerInsertIndex3D)
		{
			layer->onDetach();
			m_layers.erase(it);
			m_layerInsertIndex3D--;
		}
	}

	void LayerStack::popLayer2D(Layer* layer)
	{
		auto it = std::find(m_layers.begin() + m_layerInsertIndex3D, m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D, layer);
		if (it != m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D)
		{
			layer->onDetach();
			m_layers.erase(it);
			m_layerInsertIndex2D--;
		}
	}

	void LayerStack::popLayerUI(Layer* layer)
	{
		auto it = std::find(m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D, m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D + m_layerInsertIndexUI, layer);
		if (it != m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D + m_layerInsertIndexUI)
		{
			layer->onDetach();
			m_layers.erase(it);
			m_layerInsertIndexUI--;
		}
	}

	void LayerStack::popLayerDEBUG(Layer* layer)
	{
		auto it = std::find(m_layers.begin() + m_layerInsertIndex3D + m_layerInsertIndex2D + m_layerInsertIndexUI, m_layers.end(), layer);
		if (it != m_layers.end())
		{
			layer->onDetach();
			m_layers.erase(it);
		}
	}





}
