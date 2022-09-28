// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

const int VECTORS = 2;
const int ELEMENTS = 10;

int bubbleSort(int *arrToSort, unsigned size)
{
    int i, j;
    int tmp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arrToSort[j] > arrToSort[j + 1])
            {
                tmp = arrToSort[j];
                arrToSort[j] = arrToSort[j + 1];
                arrToSort[j + 1] = tmp;
            }
        }
    }
    return 1;
}

int main()
{
    int testVectors[VECTORS][ELEMENTS] = {{11, 32, 24, 36, 73, 8, 9, 112, 2, 68},
                                          {24, 4, 10, 11, 12, 22, 53, 45, 3, 23}};

    // Sort
    for (int idx = 0; idx < VECTORS; idx++)
    {
        cout << "-------------------" << idx << " Array------------------\n";
        bubbleSort(testVectors[idx], ELEMENTS);
        for (int jdx = 0; jdx < ELEMENTS; jdx++)
        {
            cout << jdx << ": " << testVectors[idx][jdx] << "\n";
        }
    }
}
