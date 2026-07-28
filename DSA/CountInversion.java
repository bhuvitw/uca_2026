public class CountInversion {
    int count = 0; 
    public int CountInversion(int[] arr) {
        merge(arr, 0, arr.length -1); 
        return count;
    }

    private void merge(int[] arr, int left, int right) {

        if(left>=right) return; 
        
        int mid = left + (right-left)/2; 

        merge(arr, left, mid);
        merge(arr, mid+1, right); 

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
            else {
                count += (mid - i + 1); 
                aux[k++] = a[j++]; 
            }
        }

        int p = left; 
        while(p<=right){
            a[p] = aux[p];
            p++;
        }
    }
}