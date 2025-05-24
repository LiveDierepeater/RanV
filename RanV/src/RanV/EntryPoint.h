#pragma once

#ifdef RANV_PLATFORM_WINDOWS

extern RanV::Application* RanV::CreateApplication();

int main(int argc, char** argv)
{
	RanV::Log::Init();
	RANV_CORE_WARN("Initialized Log!");
	int a = 5;
	RANV_CORE_INFO("Hello! Var={0}", a);

	auto app = RanV::CreateApplication();
	app->Run();
	delete app;
}

#endif
