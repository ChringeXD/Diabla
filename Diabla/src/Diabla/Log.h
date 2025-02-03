#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Diabla {

	class DIABLA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define DB_CORE_FATAL(...)   ::Diabla::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define DB_CORE_ERROR(...)   ::Diabla::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DB_CORE_WARN(...)    ::Diabla::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DB_CORE_INFO(...)    ::Diabla::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DB_CORE_TRACE(...)   ::Diabla::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define DB_FATAL(...) ::Diabla::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define DB_ERROR(...) ::Diabla::Log::GetClientLogger()->error(__VA_ARGS__)
#define DB_WARN(...)  ::Diabla::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DB_INFO(...)  ::Diabla::Log::GetClientLogger()->info(__VA_ARGS__)
#define DB_TRACE(...) ::Diabla::Log::GetClientLogger()->trace(__VA_ARGS__)