public class CountSignificantReversePairs {
    public int significantReversePairs(int[] nums) {
        // i, j -> indices
        // 0 <= i, j< n
        // nums[i] > 2 * nums[j]; 

        int length = nums.length; 

        int countOfSignificantReversePairs = 0; 

        for (int i = 0; i < length - 1; i++) {
            for (int j = i+1; j < length; j++) {
                if(nums[i] > 2 * nums[j]) countOfSignificantReversePairs++; 
            }
        }

        return countOfSignificantReversePairs; 
    }
}