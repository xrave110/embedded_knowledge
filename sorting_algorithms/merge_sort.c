/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    printf(">>>>MERGE<<<<\nArgument passed: l: %d, m: %d, r: %d\nThe array will be splited into the two %d and %d parts \n", l, m, r, n1, n2);

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        printf("i: %d\t j: %d\t k: %d\nArrayL[%d]: %d\t ArrayR[%d]: %d\n", i, j, k, i, L[i], j, R[j]);
        if (L[i] <= R[j])
        {
            printf("Assigned %d to the arr[%d]\n", L[i], k);
            arr[k] = L[i];
            i++;
        }
        else
        {
            printf("Assigned %d to the arr[%d]\n", R[j], k);
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        printf("i: %d\t j: %d\t k: %d\nArrayL: %d\n", i, j, k, L[i]);
        printf("Assigned %d to the arr[%d]\n", L[i], k);
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        printf("i: %d\t j: %d\t k: %d\nArrayR: %d\n", i, j, k, R[j]);
        printf("Assigned %d to the arr[%d]\n", R[j], k);
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    printf(">>>>>MERGE_SORT<<<<<\nArguments: l: %d, r: %d\n", l, r);
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        printf(">MERGE_SORT_CDN<\nArguments: l: %d, r: %d\n", l, r);
        merge(arr, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/* Driver code */
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; //{12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}