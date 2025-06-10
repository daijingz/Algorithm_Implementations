#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define SIZE 5

// Check if input is valid: no duplicates, no zero
bool checkAvailable(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) return false;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) return false;
        }
    }
    return true;
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Selection Sort
void SelectionSort(int arr[], int size) {
    if (!checkAvailable(arr, size)) {
        printf("Invalid input.\n");
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void InsertionSort(int arr[], int size) {
    if (!checkAvailable(arr, size)) {
        printf("Invalid input.\n");
        return;
    }
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

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void MergeSort(int arr[], int l, int r) {
    if (!checkAvailable(arr + l, r - l + 1)) {
        printf("Invalid input.\n");
        return;
    }
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Shell Sort
void ShellSort(int arr[], int size) {
    if (!checkAvailable(arr, size)) {
        printf("Invalid input.\n");
        return;
    }
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// QuickSort (custom version, not recursive)
void QuickSort(int arr[], int size) {
    if (!checkAvailable(arr, size)) {
        printf("Invalid input.\n");
        return;
    }

    int max = arr[0], min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    srand(time(NULL));
    int pivot;
    do {
        pivot = arr[rand() % size];
    } while (pivot == min || pivot == max);

    int left[SIZE], right[SIZE];
    int l = 0, r = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < pivot) left[l++] = arr[i];
        else if (arr[i] > pivot) right[r++] = arr[i];
    }

    // Sort left and right manually
    SelectionSort(left, l);
    SelectionSort(right, r);

    int idx = 0;
    for (int i = 0; i < l; i++) arr[idx++] = left[i];
    arr[idx++] = pivot;
    for (int i = 0; i < r; i++) arr[idx++] = right[i];
}

int main() {
    int original[SIZE] = {4, 9, 1, 5, 2};
    int a[SIZE];

    // Insertion Sort
    memcpy(a, original, sizeof(a));
    InsertionSort(a, SIZE);
    printf("InsertionSort: "); printArray(a, SIZE);

    // Merge Sort
    memcpy(a, original, sizeof(a));
    MergeSort(a, 0, SIZE - 1);
    printf("MergeSort: "); printArray(a, SIZE);

    // Shell Sort
    memcpy(a, original, sizeof(a));
    ShellSort(a, SIZE);
    printf("ShellSort: "); printArray(a, SIZE);

    // QuickSort
    memcpy(a, original, sizeof(a));
    QuickSort(a, SIZE);
    printf("QuickSort: "); printArray(a, SIZE);

    // Selection Sort
    memcpy(a, original, sizeof(a));
    SelectionSort(a, SIZE);
    printf("SelectionSort: "); printArray(a, SIZE);

    return 0;
}