public class CountSignificantReveresePairs {
    int count=0; 
    public int CountSignificantReveresePairs(int[] arr) {
        merge(arr, 0, arr.length -1); 
        return count;
    }

    private void merge(int[] arr, int left, int right) {

        if(left>=right) return; 
        
        int mid = left + (right-left)/2; 

        merge(arr, left, mid);
        merge(arr, mid+1, right); 

        int j = mid+1; 
        for(int i = left; i<=mid; i++){
            while(j<=right && arr[i] > 2*arr[j]) j++; 

            count += (j - (mid+1)); 
        }
        mergeSort(arr, left, right, mid); 
    }

    private void mergeSort(int[] a, int left, int right, int mid){
        int i = left; 
        int j = mid+1; 
        int k = left;

        int[] aux = new int[a.length]; 

        while(k<=right){
            if (i>mid) aux[k++] = a[j++]; 
            else if (j>right) aux[k++] = a[i++];
            else if(a[i]<=a[j]) aux[k++] = a[i++];
            else aux[k++] = a[j++]; 
        }

        int p = left; 
        while(p<=right){
            a[p] = aux[p];
            p++;
        }
    }
}