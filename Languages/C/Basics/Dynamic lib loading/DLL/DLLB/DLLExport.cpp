#define DLL_EXPORT
#include "DLLExport.h"
#include "../IDLL.h"
#include "DLL.h"

IDLL *CreateDLLInstance() {
    return static_cast<IDLL*>(new DLL);
} 