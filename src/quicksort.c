#include "quicksort.h"

static void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void quicksort_rec(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = arr[high];
        int i = low;


        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                if (i != j)
                    swap(&arr[i], &arr[j]);
                ++i;
            }
        }
        swap(&arr[i], &arr[high]);

        quicksort_rec(arr, low, i - 1);
        quicksort_rec(arr, i + 1, high);
    }
}

void quicksort(int arr[], int size)
{
    quicksort_rec(arr, 0, size - 1);
}
