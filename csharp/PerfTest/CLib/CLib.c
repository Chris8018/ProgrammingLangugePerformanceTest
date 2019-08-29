// CLib.cpp : Defines the exported functions for the DLL application.
//

//#include "stdafx.h"
#include "CLib.h"
#include <stdio.h>

__declspec(dllexport) void greet()
{
    printf("Hello from C!");
}

__declspec(dllexport) int sum_written_in_c(double a, double b, double c)
{
    int temp;
    temp = a + b + c;
    return temp;
}
