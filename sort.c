#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// --- Input Generation Functions ---

int* generateRandom(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000; // Larger range to reduce duplicate impacts
    }
    return arr; 
}

int* ascendingOrder(int size) {
    int* arr = (int*)malloc(size * sizeof(int)); 
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr; 
}

int* descendingOrder(int size) {
    int* arr = (int*)malloc(size * sizeof(int)); 
    for (int i = 0; i < size; i++) {
        arr[i] = size - i; 
    }
    return arr;
}   

void swap(int* a, int* b) {
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

// --- Sorting Algorithms ---

void applyBubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0; 
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]); 
                swapped = 1; 
            }
        }
        if (!swapped) break; 
    }
}   

void applyInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void applySelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int currmin = i; 
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[currmin]) {
                currmin = j;
            }
        }
        if (currmin != i) {
            swap(&arr[i], &arr[currmin]); 
        }
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void applyQuickSort(int arr[], int size) {
    quickSortHelper(arr, 0, size - 1);
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
    free(L);
    free(R);
}

void mergeSortHelper(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortHelper(arr, l, m);
        mergeSortHelper(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void applyMergeSort(int arr[], int size) {
    mergeSortHelper(arr, 0, size - 1);
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void applyHeapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// --- Benchmark Runner ---

void runBenchmark(int inputType) {
    char* typeName[] = {"RANDOM", "ASCENDING", "DESCENDING"};
    printf("\n--- Results for %s Input Order ---\n", typeName[inputType]);
    printf("Size\tBubble\tInsert\tSelect\tQuick\tMerge\tHeap\n");

    for (int iter = 0; iter < 8; iter++) {
        int size = 8000 + (iter * 4000);
        printf("%d\t", size);

        // Run for all 6 algorithms
        for (int alg = 0; alg < 6; alg++) {
            // Generate a fresh array for each run
            int* masterArr;
            if (inputType == 0) masterArr = generateRandom(size);
            else if (inputType == 1) masterArr = ascendingOrder(size);
            else masterArr = descendingOrder(size);

            // Create working copy so we don't sort an already sorted array in subsequent passes
            int* testArr = (int*)malloc(size * sizeof(int));
            memcpy(testArr, masterArr, size * sizeof(int));

            // Track time
            clock_t start = clock();
            
            switch(alg) {
                case 0: applyBubbleSort(testArr, size); break;
                case 1: applyInsertionSort(testArr, size); break;
                case 2: applySelectionSort(testArr, size); break;
                case 3: applyQuickSort(testArr, size); break;
                case 4: applyMergeSort(testArr, size); break;
                case 5: applyHeapSort(testArr, size); break;
            }
            
            clock_t end = clock();
            double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; // to milliseconds

            printf("%.2f\t", time_taken);

            free(masterArr);
            free(testArr);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random generator

    // Run tests for 0: Random, 1: Ascending, 2: Descending
    for (int type = 0; type < 3; type++) {
        runBenchmark(type);
    }

    return 0;
}