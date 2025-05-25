#pragma once

#ifdef RANV_PLATFORM_WINDOWS
	#ifdef RANV_BUILD_DLL
		#define RANV_API __declspec(dllexport)
	#else
		#define RANV_API __declspec(dllimport)
	#endif
#else
	#error RanV only supports Windows!
#endif

#ifdef RANV_ENABLE_ASSERTS
	#define RANV_ASSERT(x, ...) {if (!(x)) {RANV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RANV_CORE_ASSERT(x, ...) {if (!(x)) {RANV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RANV_ASSERT(x, ...)
	#define RANV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)