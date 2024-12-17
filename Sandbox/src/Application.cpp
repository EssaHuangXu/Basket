#include "Basket.h"
#include "iostream"

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
	printf("Start Basket Engine!\n");
	auto app = Basket::CreateApplication();
	app->Run();
	delete app;
}