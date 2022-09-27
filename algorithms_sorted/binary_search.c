#include <stdio.h>
#include <stdbool.h>

const int VECTORS = 2;
const int ELEMENTS = 10;

int binarySearch(int arr[], unsigned low, unsigned high, unsigned key)
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

int main(int argc, char **argv)
{
    // To DO randomized length of test vectors
    int testVectors[VECTORS][ELEMENTS] = {{1, 2, 4, 6, 7, 8, 9, 12, 25, 28},
                                          {20, 30, 110, 111, 112, 122, 233, 345, 550, 670}};
    int lows[VECTORS] = {4, 2};
    int highs[VECTORS] = {8, 9};
    int keys[VECTORS] = {7, 670};
    int foundIdx = false;
    for (int idx = 0; idx < VECTORS; idx++)
    {
        foundIdx = binarySearch(testVectors[idx], lows[idx], highs[idx], keys[idx]);
        printf("Found index %d for vector number %d\n", foundIdx, idx);
    }
}