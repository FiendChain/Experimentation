#pragma once
#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


#include <windows.h>
#include "../IDLL.h"

extern "C"

DLL_API IDLL* CreateDLLInstance(void);




