#pragma once


#ifdef BK_PLATFORM_WINDOWS
	#ifdef BK_BUILD_DLL
		#define BASKET_API _declspec(dllexport)
	#else
		#define BASKET_API _declspec(dllimport)
	#endif // BK_BUILD_DLL
#else
	#error only support windows platform
#endif// BK_PLATFORM_WINDOWS
