// public: can be accessible to every package
// static: "globally" available, no need to create an instance
// final: this is "final" in hierarchy, cannot be inherited "extends"
//
public final class IntToString {
    public static final String intToString(int inVal) {
    	// create an String with ASCII decimal digit chars for input inVal
    	if (inVal == 0) {
    		return new String("0"); // simple case, int value zero
    	}
    	// for non-zero integers use integer division and modulo
    	// to extract the digits, and add ASCII decimal chars for digits
    	int quot = inVal; // keeps quotient in the loop, init with inVal
    	int remainder = 0; // store remainder from modulo in each step
    	final int ASCII_ZERO = 48; // ascii char value for digit 0 from table
    	final int RADIX = 10; // dividing by 10 to get decimal digits
    	StringBuilder sb = new StringBuilder(); // mutable String
    	while (quot != 0) {
    		remainder = quot % RADIX; // get rightmost digit of quot
    		
    		// compute ASCII value for the remainder digit, cast to 'char',
    		// and append it to StringBuffer
    		sb.append((char)(remainder + ASCII_ZERO));

    		quot = quot / RADIX; // recompute quot (shift out rightmost digit)
    	}
    	// quot is zero, extracted all digits into StringBuilder but it
    	// is in reverse order - from right to left. Reverse StringBuilder,
    	// and convert to String, and return
    	return sb.reverse().toString(); // reverse, then toString
    }
}
