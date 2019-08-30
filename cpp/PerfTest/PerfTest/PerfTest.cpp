// PerfTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <chrono>
#include <ctime>


int main()
{
    //std::cout << "Hello World!\n";
    /*auto start = std::chrono::system_clock::now();*/

    // Some computation here
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

    /*auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
        << "elapsed time: " << elapsed_seconds.count() << "s\n";*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
