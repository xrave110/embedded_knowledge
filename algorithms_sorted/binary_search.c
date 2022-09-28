#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

const int VECTORS = 2;
const int ELEMENTS = 10;
const int CAPACITY = 12;

int binarySearch(int arr[], unsigned low, unsigned high, int key)
{
    if (high < low)
    {
        return -1;
    }
    int mid = low + ((high - low) / 2);
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        return binarySearch(arr, low, (mid - 1), key);
    }
    else
    {
        return binarySearch(arr, (mid + 1), high, key);
    }
}

unsigned insertSorted(int arr[], unsigned n, int key, unsigned capacity)
{
    unsigned i;
    if (capacity <= n)
    {
        return n;
    }

    for (i = n - 1; i > 0 && arr[i] > key; i--)
    {
        arr[i + 1] = arr[i]; // Move values of the array to the right
    }
    arr[i + 1] = key;
    return n + 1;
}

unsigned deleteSorted(int arr[], unsigned n, int key)
{
    int arrIdx = binarySearch(arr, 0, n - 1, key);
    if (arrIdx == -1)
    {
        return n; // Not found
    }

    for (int i = arrIdx + 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int main(int argc, char **argv)
{
    // To DO randomized length of test vectors
    int testVectors[VECTORS][CAPACITY] = {{1, 2, 4, 6, 7, 8, 9, 12, 25, 28},
                                          {20, 30, 110, 111, 112, 122, 233, 345, 550, 670}};
    int lows[VECTORS] = {4, 2};
    int highs[VECTORS] = {8, 9};
    int keys[VECTORS] = {7, 670};
    int keysToInsert[VECTORS] = {10, 670};
    int keysToDelete[VECTORS] = {25, 60};
    int foundIdx = false;
    unsigned newSize;
    // Search
    for (int idx = 0; idx < VECTORS; idx++)
    {
        foundIdx = binarySearch(testVectors[idx], lows[idx], highs[idx], keys[idx]);
        printf("Found index %d for vector number %d\n", foundIdx, idx);
    }
    // Insert
    for (int idx = 0; idx < VECTORS; idx++)
    {
        newSize = insertSorted(testVectors[idx], ELEMENTS, keysToInsert[idx], CAPACITY);
        printf("New size is %d (Old: %d)\n", newSize, ELEMENTS);
        for (unsigned j = 0; j < newSize; j++)
        {
            printf("Values of vectors after: %d\n", testVectors[idx][j]);
        }
    }
    // Delete
    for (int idx = 0; idx < VECTORS; idx++)
    {
        newSize = deleteSorted(testVectors[idx], ELEMENTS, keysToDelete[idx]);
        printf("New size is %d (Old: %d)\n", newSize, ELEMENTS);
        for (unsigned j = 0; j < newSize; j++)
        {
            printf("Values of vectors after: %d\n", testVectors[idx][j]);
        }
    }
}