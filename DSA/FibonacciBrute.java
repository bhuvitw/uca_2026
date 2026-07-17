public class FibonacciBrute{
    public int sumEvenFibonacci(int maxLimit){
        int initialSum = 0; 
        int firstTerm = 1; 
        int secondTerm = 1; 
        return calculateEvenSumHelper(firstTerm,secondTerm,maxLimit, initialSum); 
    }
    private int calculateEvenSumHelper(int previousTerm, int currentTerm, int maxLimit, int currentSum){

        if (currentTerm > maxLimit) {
            return currentSum; 
        }

        if (currentTerm % 2 == 0) {
            currentSum += currentTerm;
        }

        int nextTerm = previousTerm + currentTerm; 
        return calculateEvenSumHelper(currentTerm, nextTerm, maxLimit, currentSum); 
    }
}