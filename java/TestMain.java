// TestMain class to test IntToString for different integer values
// default package

final class TestMain {
    public static void main(String[] args) {
        // call IntToString.intToString static method
        final int[] testValues = {0, 1234, 24680864};
        for (int i : testValues) {
            String ret = IntToString.intToString(i);
            System.out.format("Integer %d in string %s%n", i, ret);
        }
    }
}
