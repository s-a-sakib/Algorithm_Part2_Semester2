#include <bits/stdc++.h>
using namespace std;

int getMid(int start, int end) { return start + (end - start) / 2; }

int getSumUtil(int *segmentTree, int startRange, int endRange, int queryStart, int queryEnd, int index)
{
    if (queryStart <= startRange && queryEnd >= endRange)
        return segmentTree[index];

    if (endRange < queryStart || startRange > queryEnd)
        return 0;

    int mid = getMid(startRange, endRange);
    return getSumUtil(segmentTree, startRange, mid, queryStart, queryEnd, 2 * index + 1) +
           getSumUtil(segmentTree, mid + 1, endRange, queryStart, queryEnd, 2 * index + 2);
}

void updateValueUtil(int *segmentTree, int startRange, int endRange, int arrayIndex, int difference, int index)
{
    if (arrayIndex < startRange || arrayIndex > endRange)
        return;

    segmentTree[index] = segmentTree[index] + difference;

    if (endRange != startRange)
    {
        int mid = getMid(startRange, endRange);
        updateValueUtil(segmentTree, startRange, mid, arrayIndex, difference, 2 * index + 1);
        updateValueUtil(segmentTree, mid + 1, endRange, arrayIndex, difference, 2 * index + 2);
    }
}

void updateValue(int inputArray[], int *segmentTree, int size, int arrayIndex, int newValue)
{
    if (arrayIndex < 0 || arrayIndex > size - 1)
    {
        cout << "Invalid Input";
        return;
    }

    int difference = newValue - inputArray[arrayIndex];
    inputArray[arrayIndex] = newValue;

    updateValueUtil(segmentTree, 0, size - 1, arrayIndex, difference, 0);
}

int getSum(int *segmentTree, int size, int queryStart, int queryEnd)
{
    if (queryStart < 0 || queryEnd > size - 1 || queryStart > queryEnd)
    {
        cout << "Invalid Input";
        return -1;
    }

    return getSumUtil(segmentTree, 0, size - 1, queryStart, queryEnd, 0);
}

int constructSTUtil(int inputArray[], int startRange, int endRange, int *segmentTree, int index)
{
    if (startRange == endRange)
    {
        segmentTree[index] = inputArray[startRange];
        return inputArray[startRange];
    }

    int mid = getMid(startRange, endRange);
    segmentTree[index] = constructSTUtil(inputArray, startRange, mid, segmentTree, 2 * index + 1) +
                         constructSTUtil(inputArray, mid + 1, endRange, segmentTree, 2 * index + 2);
    return segmentTree[index];
}

int *constructST(int inputArray[], int size)
{
    int height = (int)(ceil(log2(size)));
    int max_size = 2 * (int)pow(2, height) - 1;

    int *segmentTree = new int[max_size];

    constructSTUtil(inputArray, 0, size - 1, segmentTree, 0);

    return segmentTree;
}

int main()
{
    int inputArray[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(inputArray) / sizeof(inputArray[0]);

    int *segmentTree = constructST(inputArray, size);

    cout << "Sum of values in given range = " << getSum(segmentTree, size, 1, 3) << endl;

    updateValue(inputArray, segmentTree, size, 1, 10);

    cout << "Updated sum of values in given range = " << getSum(segmentTree, size, 1, 3) << endl;

    return 0;
}
