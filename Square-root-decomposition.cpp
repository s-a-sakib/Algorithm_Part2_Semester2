#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "Number of Elements : " << endl;
    int elements;
    cin >> elements;

    int len = (int)sqrt(elements + .0) + 1;
    vector<int> V1(elements), V2(len);

    // Building Square Root Decomposition
    for (int i = 0; i < elements; i++) {
        cin >> V1[i];
        V2[i / len] += V1[i];
    }

    cout << "Number of Queries : " << endl;
    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cout << "Enter query type (1 for sum query, 2 for update query): ";
        cin >> type;

        if (type == 1) {
            int left, right;
            cout << "Enter range for sum query: ";
            cin >> left >> right;

            int sum = 0;
            for (int i = left; i <= right;) {
                if (i % len == 0 && i + len - 1 <= right) {
                    sum += V2[i / len];
                    i += len;
                } else {
                    sum += V1[i];
                    ++i;
                }
            }
            cout << "Sum of elements from " << left << " to " << right << " is " << sum << endl;
        } else if (type == 2) {
            int index, newValue;
            cout << "Enter index to update and the new value: ";
            cin >> index >> newValue;

            // Update the original array
            V1[index] = newValue;

            // Update the corresponding block sum
            V2[index / len] += (newValue - V1[index]);

            cout << "Element at index " << index << " updated to " << newValue << endl;
        } else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}
