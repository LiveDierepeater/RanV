#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "RanV/Events/ApplicationEvent.h"

#include "Window.h"

namespace RanV {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	class RANV_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
