#include "Basket.h"
#include <iostream>

class Sanbox : public Basket::Application 
{
public:
	Sanbox() {}
	~Sanbox() {}
};


Basket::Application* Basket::CreateApplication()
{
	return new Sanbox();
}


int main(int argc, char** argv)
{
	Basket::Log::Init();

	BK_CORE_INFO("Start Basket Engine!");
	BK_CLIENT_INFO("Client Start! {0}", 1);

	auto app = Basket::CreateApplication();
	app->Run();
	delete app;
}