#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

const int VECTORS = 2;
const int ELEMENTS = 10;

bool checkIfPairIsSum(int *arrOfVals, const int N, int sum)
{
    // Assumption - array is sorted!
    bool isPairSum = false;
    int i = 0;
    int j = N - 1;
    while (i < j)
    {
        if (sum == (arrOfVals[i] + arrOfVals[j]))
        {
            isPairSum = true;
            break;
        }
        else if (sum > (arrOfVals[i] + arrOfVals[j]))
        {
            i++;
        }
        else if (sum < (arrOfVals[i] + arrOfVals[j]))
        {
            j--;
        }
    }
    return isPairSum;
}

int main(int argc, char **argv)
{
    int testVectors[VECTORS][ELEMENTS] = {{1, 2, 4, 6, 7, 8, 9, 12, 25, 28},
                                          {20, 30, 110, 111, 112, 122, 233, 345, 550, 670}};
    int expectedSums[VECTORS] = {21, 233};
    bool isParSum = false;
    for (int idx = 0; idx < VECTORS; idx++)
    {
        printf("IDx: %d\n", idx);
        isParSum = checkIfPairIsSum(&testVectors[idx][0], ELEMENTS, expectedSums[idx]);
        printf("IDx: %d\n", idx);
        if (isParSum)
            printf("There is a pair which result in sum of %d\n", expectedSums[idx]);
        else
            printf("There is not pair which result in sum of %d\n", expectedSums[idx]);
    }
    return 0;
}
