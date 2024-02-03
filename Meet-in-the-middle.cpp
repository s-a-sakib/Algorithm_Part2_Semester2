#include <bits/stdc++.h>
using namespace std;

int X[1 << 20], Y[1 << 20];

int* lower_bound(int* first, int* last, int value) {
    while (first < last) {
        int* mid = first + (last - first) / 2;
        if (*mid < value) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return first;
}

void subsetSum(int a[], int subsetsum[], int n, int c) {
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                sum += a[j + c];
        }
        subsetsum[i] = sum;
    }
}

bool meetInTheMiddle(int givenArray[], int elements, int targetSum) {
    subsetSum(givenArray, X, elements / 2, 0);
    subsetSum(givenArray, Y, elements - elements / 2, elements / 2);

    int size_X = 1 << (elements / 2);
    int size_Y = 1 << (elements - elements / 2);

    sort(Y, Y + size_Y);

    for (int i = 0; i < size_X; i++) {
        if (X[i] <= targetSum) {
            int* p = lower_bound(Y, Y + size_Y, targetSum - X[i]);
            if (p != Y + size_Y && *p == targetSum - X[i]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << "--------------------------------" << endl;
    cout << "Number of Elements" << endl;
    int elements;
    cin >> elements;
    int givenArray[elements];
    for (auto& it : givenArray)
        cin >> it;
    cout << "--------------------------------" << endl;
    cout << "What is the target Sum? " << endl;
    int targetSum;
    cin >> targetSum;
    bool flag = meetInTheMiddle(givenArray, elements, targetSum);
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
