// Online C++ compiler to run C++ program online
#include <cstdlib>
#include <string.h>
#include <typeinfo>
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>

using namespace std;
using namespace std::chrono;

const unsigned VECTORS = 50;
const unsigned MAX_ELEMENTS = 1000;

void _swap(int arr[], int x, int y)
{
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

void bubbleSort1(int *arrToSort, unsigned size)
{
    unsigned i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++) // size - i - 1 -> eliminates not needed iterations
        {
            if (arrToSort[j] > arrToSort[j + 1])
            {
                _swap(arrToSort, j, j + 1);
            }
        }
    }
}

void bubbleSort2(int *arrToSort, unsigned size)
{
    unsigned loop = size - 1;
    unsigned i = size - 1;
    while (loop > 0)
    {
        i = size - 1;
        while (i > 0)
        {
            if (arrToSort[i] < arrToSort[i - 1])
            {
                _swap(arrToSort, i, i - 1);
            }
            i--;
        }
        loop--;
    }
}

unsigned _locateSmallest(int arr[], unsigned idx, unsigned size)
{
    unsigned i = idx;
    unsigned smallestLocation = idx;
    while (i < size)
    {
        if (arr[smallestLocation] > arr[i])
        {
            smallestLocation = i;
        }
        i++;
    }
    return smallestLocation;
}

void selectionSort(int arr[], unsigned size)
{
    unsigned i = 0;
    unsigned smallestLocation = 0;

    while (i < size)
    {
        smallestLocation = _locateSmallest(arr, i, size);
        _swap(arr, i, smallestLocation);
        i++;
    }
}

void _insertKey(int arr[], unsigned size, unsigned i)
{
    int j = i - 1;
    int key = arr[i];
    while (j >= 0 && key <= arr[j])
    {
        arr[j + 1] = arr[j];
        /* i = 1, j = 0: [3 2 1] */
        /* i = 2, j = 1: [2 1 3] */
        /* i = 2, j = 0: [1 2 3] */
        j--;
    }

    arr[j + 1] = key;
}

void insertionSort(int arr[], unsigned size)
{
    unsigned i = 1;
    while (i < size)
    {
        _insertKey(arr, size, i);
        i++;
    }
}

void _combine(int arr[], unsigned start, unsigned mid, unsigned end)
{
    int *buffer = new int[end + 1]; // total size of the merged array
    memcpy(buffer, arr, (end + 1) * sizeof(int));
    unsigned i = start;   // begining of first part of array
    unsigned j = mid + 1; // begining of second part of array
    unsigned k = i;
    while (i <= mid && j <= end)
    {
        if (buffer[i] > buffer[j])
        {
            arr[k] = buffer[j];
            j++;
        }
        else if (buffer[i] < buffer[j])
        {
            arr[k] = buffer[i];
            i++;
        }
        else
        {
            arr[k] = buffer[i];
            k++;
            arr[k] = buffer[j];
            i++;
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        arr[k] = buffer[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        arr[k] = buffer[j];
        j++;
        k++;
    }
    delete[] buffer;
}

// Auxilary function
void mergeSort(int arr[], unsigned start, unsigned end)
{
    if (start >= end)
    {
        return;
    }
    unsigned mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    _combine(arr, start, mid, end);
}

void mergeSort(int arr[], unsigned size)
{ // wrapper function
    mergeSort(arr, 0, size - 1);
}

void display(int arr[], unsigned size)
{
    cout << "[";
    for (int jdx = 0; jdx < size; jdx++)
    {
        cout << arr[jdx] << " ";
    }
}

int main()
{

    unsigned long bubbleSort1Time = 0;
    unsigned long bubbleSort2Time = 0;
    unsigned long insertionSortTime = 0;
    unsigned long selectionSortTime = 0;
    unsigned long mergeSortTime = 0;
    // Main loop
    for (unsigned i = 0; i < VECTORS; i++)
    {
        cout << "\n-------------------" << i << " Test----------------\nInput Array:\n";
        // Assign
        unsigned nrOfElements = (rand() % MAX_ELEMENTS);
        int *testSuite = new int[nrOfElements];
        int *testSuiteCopy = new int[nrOfElements];

        cout << "[";
        for (unsigned j = 0; j < nrOfElements; j++)
        {
            testSuite[j] = (rand() % MAX_ELEMENTS);
            cout << testSuite[j] << " ";
        }
        memcpy(testSuiteCopy, testSuite, nrOfElements * sizeof(int));

        /** Bubble Sort 1
         * Time complexity: O(n)/O(n^2)
         * Space complexity: O(1)
         */
        cout << "]\n\n---------Bubble Sort 1---------------\n";
        auto start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        cout << "------------------------------" << typeid(start).name() << endl;
        bubbleSort1(testSuite, nrOfElements);
        auto end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        unsigned long frams = (end - start);
        bubbleSort1Time += (end - start);
        display(testSuite, nrOfElements);

        /** Bubble Sort 2
         * Time complexity: O(n^2)
         * Space complexity: O(1)
         */
        // Return to Input array
        memcpy(testSuite, testSuiteCopy, nrOfElements * sizeof(int));
        cout << "]\n\n---------Bubble Sort 2---------------\n";
        start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        bubbleSort2(testSuite, nrOfElements);
        end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        bubbleSort2Time += (end - start);

        display(testSuite, nrOfElements);

        /** Selection sort
         * Time complexity: O(n^2)
         * Space complexity: O(1)
         */
        // Return to Input array
        memcpy(testSuite, testSuiteCopy, nrOfElements * sizeof(int));
        cout << "]\n\n---------Selection Sort---------------\n";
        start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        selectionSort(testSuite, nrOfElements);
        end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        selectionSortTime += (end - start);
        display(testSuite, nrOfElements);

        /** Insertion sort
         * Time complexity: O(n^2)
         * Space complexity: O(1)
         */
        // Return to Input array
        memcpy(testSuite, testSuiteCopy, nrOfElements * sizeof(int));
        cout << "]\n\n---------Insertion Sort---------------\n";
        start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        insertionSort(testSuite, nrOfElements);
        end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        insertionSortTime += (end - start);
        display(testSuite, nrOfElements);

        /** Merge sort
         * Time complexity: O(nlog(n))
         * Space complexity: O(n)
         */
        // Return to Input array
        memcpy(testSuite, testSuiteCopy, nrOfElements * sizeof(int));
        cout << "]\n\n---------Merge Sort---------------\n";
        start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        mergeSort(testSuite, nrOfElements);
        end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        mergeSortTime += (end - start);
        display(testSuite, nrOfElements);
        cout << "]\n\n";

        // Cleaning
        delete[] testSuite;
        delete[] testSuiteCopy;
    }
    /* Algorithms comparison - time complexity */
    cout << "Algorithms comparison - time complexity:" << endl;
    cout << "Bubble sort 1: \t\t" << bubbleSort1Time << endl;
    cout << "Bubble sort 2: \t\t" << bubbleSort2Time << endl;
    cout << "Selection sort: \t" << selectionSortTime << endl;
    cout << "Insertion sort: \t" << insertionSortTime << endl;
    cout << "Merge sort: \t\t" << mergeSortTime << endl;
}
