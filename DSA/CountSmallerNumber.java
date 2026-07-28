public class CountSmallerNumber {

    // Value aur uski original position ko ek sath hold karne ke liye
    static class Pair {
        int val;
        int originalIndex;

        Pair(int val, int originalIndex) {
            this.val = val;
            this.originalIndex = originalIndex;
        }
    }

    int[] count;

    public int[] CountSmallerNumber(int[] nums) {
        int n = nums.length;
        count = new int[n];

        // Pair array banao original index save rakhne ke liye
        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        merge(arr, 0, n - 1);
        return count;
    }

    private void merge(Pair[] arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        merge(arr, left, mid);
        merge(arr, mid + 1, right);

        // Standard Sir's style mergeSort call
        mergeSort(arr, left, right, mid);
    }

    private void mergeSort(Pair[] a, int left, int right, int mid) {
        int i = left;
        int j = mid + 1;
        int k = left;

        Pair[] aux = new Pair[a.length];

        while (k <= right) {
            if (i > mid) {
                aux[k++] = a[j++];
            } 
            else if (j > right) {
                // Left element pick ho raha hai -> Right ke saare elements exhausted hain
                count[a[i].originalIndex] += (j - (mid + 1));
                aux[k++] = a[i++];
            } 
            else if (a[i].val <= a[j].val) {
                // Left element pick ho raha hai -> Right ke 'j - (mid + 1)' elements isse chhote the!
                count[a[i].originalIndex] += (j - (mid + 1));
                aux[k++] = a[i++];
            } 
            else {
                // Right element chhota hai, isko aux me daalo
                aux[k++] = a[j++];
            }
        }

        int p = left;
        while (p <= right) {
            a[p] = aux[p];
            p++;
        }
    }
}