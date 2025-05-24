#pragma once

#ifdef RANV_PLATFORM_WINDOWS

extern RanV::Application* RanV::CreateApplication();

int main(int argc, char** argv)
{
	auto app = RanV::CreateApplication();
	app->Run();
	delete app;
}

#endif
