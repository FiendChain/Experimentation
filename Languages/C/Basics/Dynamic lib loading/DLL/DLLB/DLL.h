#pragma once  
#include "../IDLL.h"


class DLL: public IDLL
{
    public:
        virtual void helloWorld(void);
        virtual int multiply(int, int);
    private:
        int factorial(int n);
};

