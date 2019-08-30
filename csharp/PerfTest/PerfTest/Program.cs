using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.InteropServices;

namespace PerfTest
{
    class Program
    {
        /// <summary>
        /// greet func from C
        /// </summary>
        [DllImport("CLib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void greet();

        /// <summary>
        /// sum func from C
        /// </summary>
        /// <param name="a">1st Number</param>
        /// <param name="b">2nd Number</param>
        /// <param name="c">3rd Number</param>
        /// <returns></returns>
        [DllImport("CLib.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int sum_written_in_c(double a, double b, double c);

        /// <summary>
        /// Test 1 to test execution time
        /// </summary>
        public static void test1()
        {
            for (int i = 0; i < 100_000; ++i)
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

                var array = new int[100];
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
                    String a = "hello";
                    String b = a + "world";
                }
            }
        }

        /// <summary>
        /// Test 2 to test execution time when call C-Fun
        /// </summary>
        public static void test2()
        {
            //		System.out.println("Message: " + CFun.isCFun());
            for (int i = 1; i < 100_000_000; ++i)
            {
                int a = sum_written_in_c(1, 2, 3);
            }
        }

        /// <summary>
        /// Test 3 to do memory test with biggest List<>
        /// </summary>
        public static void test3()
        {
            // std::vector == List as continues memory
            for (int i = 0; i < 2; ++i)
            {
                List<int> ints = new List<int>();
                for (int j = 1; j < 100_000; ++j)
                {
                    ints.Add(1);
                }
                List<float> floats = new List<float>();
                for (int j = 1; j < 100_000; ++j)
                {
                    floats.Add(1.1f);
                }
                List<string> strings = new List<string>();
                for (int j = 1; j < 100_000; ++j)
                {
                    strings.Add("hello world");
                }
            }
        }

        static void Main(string[] args)
        {
            //greet();
            //int result = sum_written_in_c(1, 1, 1);
            //Console.WriteLine(result);
            //Console.WriteLine("Hello");
            //Console.ReadKey();

            // Test 1

            //test1();

            // Test 2

            test2();

            // Test 3

            //test3();
            Console.WriteLine("Done");
        }
    }
}
