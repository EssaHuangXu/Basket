#pragma once

#include "BasketCore.h"

namespace Basket {

	class BASKET_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

