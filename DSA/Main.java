public class Main{
    public static void main(String[] args){
    



        FibonacciOptimal solver = new FibonacciOptimal(); 

        int[] testInputs = {10,50};
        int[] expectedOutputs = {10,44};

        System.out.println("--- Running FibonacciOptimal Tests ---");
        for (int i = 0; i < testInputs.length; i++) {
            int input = testInputs[i];
            int expected = expectedOutputs[i];
            int actual = solver.sumEvenFibonacci(input);

            if (actual == expected) {
                System.out.println("✓ Test " + i + " Passed! Input: " + input + " -> Output: " + actual);
            } else {
                System.out.println("✗ Test " + i + " Failed! Input: " + input + " | Expected: " + expected + " | Got: " + actual);
            }
        }
    }
}