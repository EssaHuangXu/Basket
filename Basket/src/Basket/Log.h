#pragma once

#include <memory>
#include "BasketCore.h"
#include "spdlog/spdlog.h"

namespace  Basket {

	class BASKET_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};

}

#ifndef BK_LOG_DEFINE

#define BK_CORE_ERROR(...)		::Basket::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BK_CORE_WARN(...)		::Basket::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BK_CORE_INFO(...)		::Basket::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BK_CORE_TRACE(...)		::Basket::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BK_CORE_FATAL(...)		::Basket::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define BK_CLIENT_ERROR(...)	::Basket::Log::GetClientLogger()->error(__VA_ARGS__)
#define BK_CLIENT_WARN(...)		::Basket::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BK_CLIENT_INFO(...)		::Basket::Log::GetClientLogger()->info(__VA_ARGS__)
#define BK_CLIENT_TRACE(...)	::Basket::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BK_CLIENT_FATAL(...)	::Basket::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif // !LOG_H