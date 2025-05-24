#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace RanV {

	class RANV_API Log
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

// Core log macros
#define RANV_CORE_TRACE(...)    ::RanV::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RANV_CORE_INFO(...)     ::RanV::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RANV_CORE_WARN(...)     ::RanV::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RANV_CORE_ERROR(...)    ::RanV::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RANV_CORE_CRITICAL(...)    ::RanV::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define RANV_CORE_TRACE(...)    ::RanV::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RANV_CORE_INFO(...)     ::RanV::Log::GetClientLogger()->info(__VA_ARGS__)
#define RANV_CORE_WARN(...)     ::RanV::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RANV_CORE_ERROR(...)    ::RanV::Log::GetClientLogger()->error(__VA_ARGS__)
#define RANV_CORE_CRITICAL(...)    ::RanV::Log::GetClientLogger()->critical(__VA_ARGS__)
