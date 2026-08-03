#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// --- Input Generation Functions ---

int *generateRandom(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000000; // Large range to minimize duplicate impact
    }
    return arr;
}

int *ascendingOrder(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    return arr;
}

int *descendingOrder(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = size - i;
    }
    return arr;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// --- Quickselect Implementation ---

// Standard Lomuto Partitioning using a Random Pivot (prevents O(n^2) on sorted inputs)
int partition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickselectHelper(int arr[], int low, int high, int k)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // If pivot is at position k - 1, the first k elements are found in arr[0...k-1]
        if (pi == k - 1)
        {
            return;
        }
        else if (pi > k - 1)
        {
            quickselectHelper(arr, low, pi - 1, k);
        }
        else
        {
            quickselectHelper(arr, pi + 1, high, k);
        }
    }
}

void applyQuickselect(int arr[], int size, int k)
{
    quickselectHelper(arr, 0, size - 1, k);
}

// --- Benchmark Runner ---

void runBenchmark(int inputType)
{
    char *typeName[] = {"RANDOM", "ASCENDING", "DESCENDING"};
    printf("\n--- Results for %s Input Order ---\n", typeName[inputType]);
    printf("Size (N)\tK (Smallest Elements)\tTime Taken (ms)\n");

    // Testing sizes scaling up to 1 million to clearly observe O(N) line
    for (int iter = 0; iter < 8; iter++)
    {
        int size = 100000 + (iter * 100000); // Sizes from 100,000 to 800,000
        int k = size / 10;                  // Select smallest 10%

        // Generate input dataset
        int *masterArr;
        if (inputType == 0)
            masterArr = generateRandom(size);
        else if (inputType == 1)
            masterArr = ascendingOrder(size);
        else
            masterArr = descendingOrder(size);

        // Working copy
        int *testArr = (int *)malloc(size * sizeof(int));
        memcpy(testArr, masterArr, size * sizeof(int));

        // Benchmark Quickselect
        clock_t start = clock();
        applyQuickselect(testArr, size, k);
        clock_t end = clock();

        double time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0; // In milliseconds

        printf("%d\t\t%d\t\t\t%.2f\n", size, k, time_taken);

        free(masterArr);
        free(testArr);
    }
}

int main()
{
    srand(time(NULL)); // Seed random generator

    // Run tests for 0: Random, 1: Ascending, 2: Descending
    for (int type = 0; type < 3; type++)
    {
        runBenchmark(type);
    }

    return 0;
}