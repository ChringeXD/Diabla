#pragma once

#ifdef DB_PLATFORM_WINDOWS
	#ifdef DB_BUILD_DLL
		#define DIABLA_API __declspec(dllexport)
	#else
		#define DIABLA_API __declspec(dllimport)
	#endif
#else
	#error Diabla only supports Windows.
#endif

#define BIT(x) (1 << x)