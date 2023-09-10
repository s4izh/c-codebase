#include "quicksort.h"

static void swap(int* a, int* b)
{
    int* t = a;
    a = b;
    b = t;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = arr[high];
        int i = low;

        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);

        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
