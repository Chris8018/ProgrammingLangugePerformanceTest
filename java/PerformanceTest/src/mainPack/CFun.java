package mainPack;

public class CFun {
	// Class initializer look for shared library and link to JVM
	static { System.loadLibrary("CFun"); }
	public static native boolean isCFun();
	public static native int sum_written_in_c(double a, double b, double c);

}