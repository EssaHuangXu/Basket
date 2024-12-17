#pragma once

#ifdef BK_PLATFORM_WINDOWS
#include "Application.h"

extern Basket::Application* Basket::CreateApplication();

//int main(int argc, char** argv)
//{
//    auto app = Basket::CreateApplication();
//    app->Run();
//    delete app;
//}

#endif // BK_PLATFORM_WINDOWS