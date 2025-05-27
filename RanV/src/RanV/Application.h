#pragma once

#include "Core.h"

#include "Window.h"
#include "RanV/LayerStack.h"
#include "RanV/Events/Event.h"
#include "RanV/Events/ApplicationEvent.h"


namespace RanV {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	class RANV_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
