// PerfTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <windows.h>

#include <stdio.h>
#include <string>
#include <vector>

#include <chrono>
#include <ctime>

#include <profileapi.h>

// Import DLL C Func here
//typedef int(__cdecl *MYPROC)();
typedef int(__cdecl *MYPROC)(double, double, double);

static double reduce(double* n, std::vector<double> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        *n += list.at(i);
    }
    return *n;
}

static double test1()
{
    LARGE_INTEGER frequency;        // ticks per second
    LARGE_INTEGER t1, t2;           // ticks
    //double elapsedTime;

    // get ticks per second
    QueryPerformanceFrequency(&frequency);

    // start timer
    QueryPerformanceCounter(&t1);

    for (int i = 0; i < 100000; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            int a = 5 * 5;
            int b = a + 5;
        }
        for (int j = 0; j < 100; ++j)
        {
            double a = 5.5 * 5.5;
            double b = a + 5.5;
        }
        int array[100];
        for (int j = 0; j < 100; ++j)
        {
            array[j] = 0;
        }
        for (int j = 0; j < 100; ++j)
        {
            array[50] = array[70];
        }
        for (int j = 0; j < 100; ++j)
        {
            std::string a = "hello";
            std::string b = a + "world";
        }
    }

    // stop timer
    QueryPerformanceCounter(&t2);

    // compute and print the elapsed time in millisec
    //elapsedTime = (t2.QuadPart - t1.QuadPart) * 1.0 / frequency.QuadPart;
    //std::cout << elapsedTime;

    return (t2.QuadPart - t1.QuadPart) * 1.0 / frequency.QuadPart;;
}

static double test2()
{
    LARGE_INTEGER frequency;        // ticks per second
    LARGE_INTEGER t1, t2;           // ticks

    // get ticks per second
    QueryPerformanceFrequency(&frequency);

    // start timer
    QueryPerformanceCounter(&t1);

    HINSTANCE hinstLib;
    MYPROC ProcSum;
    BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

    // Get a handle to the DLL module.
    hinstLib = LoadLibrary(TEXT("CLib.dll"));

    if (hinstLib != NULL) // If the handle is valid, try to get the function address.
    {
        ProcSum = (MYPROC)GetProcAddress(hinstLib, "sum_written_in_c");

        if (NULL != ProcSum) // If the function address is valid, call the function.
        {
            fRunTimeLinkSuccess = TRUE;
            for (int i = 0; i < 100000000; ++i)
                int a = (ProcSum)(1, 2, 3);
        }
        

        fFreeResult = FreeLibrary(hinstLib); // Free the DLL module.
    }

    if (!fRunTimeLinkSuccess) // If unable to call the DLL function, use an alternative.
        printf("Fail Test 2: Not loading CLib.dll");

    // stop timer
    QueryPerformanceCounter(&t2);

    return (t2.QuadPart - t1.QuadPart) * 1.0 / frequency.QuadPart;
}

static void test3()
{
    for (int i = 0; i < 2; ++i)
    {
        std::vector<int> ints;
        for (int j = 1; j < 100000; ++j)
        {
            ints.push_back(1);
        }
        std::vector<float> floats;
        for (int j = 1; j < 100000; ++j)
        {
            floats.push_back(1.1);
        }
        std::vector<std::string> strings;
        for (int j = 1; j < 100000; ++j)
        {
            strings.push_back("hello world");
        }
    }

    //return 0;
}

int main()
{
    //double* elapsedTime = 0;
    const int iteratorTime = 100;

    // Test 1

    std::vector<double> timeList1;

    for (int i = 0; i < iteratorTime; i++)
    {
        timeList1.push_back(test1());
    }

    //double test1Result = 0.0;
    double elapsedTime1Total = 0.0;

    reduce(&elapsedTime1Total, timeList1);

    std::cout << "Test 1 elapsed time: " << elapsedTime1Total / (double) iteratorTime << "s\n";    

    // Test 2

    //test2();

    std::vector<double> timeList2;

    for (int i = 0; i < iteratorTime; i++)
    {
        timeList2.push_back(test2());
    }

    //double test1Result = 0.0;
    double elapsedTime2Total = 0.0;

    reduce(&elapsedTime2Total, timeList2);

    std::cout << "Test 2 elapsed time: " << elapsedTime2Total / (double) iteratorTime << "s\n";

    return 0;
}
