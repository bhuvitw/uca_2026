public class FibonacciOptimal{
    public int sumEvenFibonacci(int maxLimit) {
        if (maxLimit < 2) {
            return 0; 
        }

        int previousEven = 2; 
        int currentEven = 8; 

        int evenSum = previousEven; 

        while (currentEven < maxLimit) {
            evenSum += currentEven; 

            int nextEven = (4 * currentEven) + previousEven; 

            previousEven = currentEven; 
            currentEven = nextEven; 
        }

        return evenSum; 
    }
}