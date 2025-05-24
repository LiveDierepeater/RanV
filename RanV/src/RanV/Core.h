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
