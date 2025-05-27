#include <RanV.h>

class ExampleLayer : public RanV::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		RANV_INFO("Example::Update");
	}

	void OnEvent(RanV::Event& event) override
	{
		RANV_TRACE("{0}", event);
	}
};

class Sandbox : public RanV::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

RanV::Application* RanV::CreateApplication()
{
	return new Sandbox();
}
