#pragma once

#ifdef CORE_BUILD_DLL
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

namespace Core {

	enum class Error : uint8_t
	{
		CORE_SUCCESS = 0,
		CORE_FATAL,
		CORE_CRITICAL,
		CORE_ERROR
	};

}