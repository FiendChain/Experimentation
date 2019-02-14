#ifdef NDEBUG
#define DEBUG_PRINT(fmt, args...) ((void)0)
}
#else
#include <stdio.h>
#ifdef DEBUG_PRINT_EXTRA
#define DEBUG_PRINT(fmt, args...) {\
    fprintf(stderr, "%s:%d:%s(): ", __FILE__, __LINE__, __func__); \
    fprintf(stderr, fmt, ##args); \
}
#else
#define DEBUG_PRINT(fmt, args...) {\
    fprintf(stderr, fmt, ##args); \
}
#endif
#endif