package mainPack;

import java.util.ArrayList;
import java.util.List;

import mainPack.CFun;

public class PerfScript {
    
	public static long test1() {
		long startTime;
		long stopTime;
		startTime = System.currentTimeMillis();
		
		for (int i = 0; i < 100_000; ++i) {
			for (int j = 0; j < 100; ++j) {
				int a = 5 * 5;
				int b = a + 5;
			}
			
			for (int j = 0; j < 100; ++j) {
				double a = 5.5 * 5.5;
				double b = a + 5.5;
			}
			
			int array[] = new int[100];
			for (int j = 0; j < 100; ++j) {
				array[j] = 0;
			}
			for (int j = 0; j < 100; ++j) {
				array[50] = array[70];
			}
			for (int j = 0; j < 100; ++j) {
				String a = "hello";
				String b = a + "world";
			}
		}
		
		stopTime = System.currentTimeMillis();
		
		return stopTime - startTime;
	}
	
	public static long test2 () {
//		System.out.println("Message: " + CFun.isCFun());
		long startTime;
		long stopTime;
		startTime = System.currentTimeMillis();
		
		for (int i = 1; i < 100_000_000; ++i) {
			int a = CFun.sum_written_in_c(1, 2, 3);
		}
		
		stopTime = System.currentTimeMillis();
		
		return stopTime - startTime;
	}
	
	public static void test3 () {
		// std::vector == ArrayList as continues memory
		for (int i = 0; i < 2; ++i) {
			List<Integer> ints = new ArrayList<>();
			for (int j = 1; j < 100_000; ++j) {
				ints.add(1);
			}
			List<Float> floats = new ArrayList<>();
			for (int j = 1; j < 100_000; ++j) {
				floats.add(1.1f);
			}
			List<String> strings = new ArrayList<>();
			for (int j = 1; j < 100_000; ++j) {
				strings.add("hello world");
			}
//			System.out.println(i);
		}
	}
	
	public static void main(String[] args) {
		
		// Test 3
//		test3();
		
		// Naive way to measure memory usage
		// *** gc might run before the calculation of memory
//		// Get the Java runtime
//        Runtime runtime = Runtime.getRuntime();
//        // Run the garbage collector
//        runtime.gc();
//        // Calculate the used memory
//        long memory = runtime.totalMemory() - runtime.freeMemory();
//        
//        System.out.println("Test 3 memory usage: " + memory/1024L + "kB");
        
//		long startTime;
//		long stopTime;
//		long elapsedTime;
		
        // Test 1
		// Start timer
//		startTime = System.currentTimeMillis();
		
//		test1();
		
		// Stop timer
//		stopTime = System.currentTimeMillis();
//		 Calculate run time
		
//		elapsedTime = stopTime - startTime;
//		System.out.println("Test 1 execution time: " + elapsedTime/1000f + "s");
		
		long iteratorTime = 100;
		
		List<Long> test1TimeList = new ArrayList<>();
		for (int i = 0; i < iteratorTime; i++) {
			test1TimeList.add(test1());
		}
		float test1ElapsedTime = test1TimeList.stream().reduce(0L, (t1, t2) -> t1 + t2) / iteratorTime / 1000f;
		System.out.println("Test 1 execution time: " + test1ElapsedTime + "s");
		
		// Test 2
//		System.out.println(System.getProperty("java.library.path"));
		
		// Start timer
//		startTime = System.currentTimeMillis();
		
//		test2();
		
		// Stop timer
//		stopTime = System.currentTimeMillis();
		// Calculate run time
//		elapsedTime = stopTime - startTime;
//		System.out.println("Test 2 execution time: " + elapsedTime/1000f + "s");
		List<Long> test2TimeList = new ArrayList<>();
		for (int i = 0; i < iteratorTime; i++) {
			test2TimeList.add(test2());
		}
		float test2ElapsedTime = test2TimeList.stream().reduce(0L, (t1, t2) -> t1 + t2) / iteratorTime / 1000f;
		System.out.println("Test 2 execution time: " + test2ElapsedTime + "s");
//		
//		System.out.print("stop");
	}
}
