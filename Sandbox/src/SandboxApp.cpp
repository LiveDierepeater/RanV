#include <RanV.h>

class Sandbox : public RanV::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

RanV::Application* RanV::CreateApplication()
{
	return new Sandbox();
}
