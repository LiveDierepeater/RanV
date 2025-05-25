#include "Application.h"

#include "RanV/Events/ApplicationEvent.h"
#include "RanV/Log.h"

namespace RanV {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		RANV_TRACE(e);

		while (true);
	}

}