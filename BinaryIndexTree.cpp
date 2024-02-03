#include <bits/stdc++.h>
using namespace std;


int getSum(int BITree[], int index) {
    int sum = 0;
    index = index + 1;

    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }

    return sum;
}

void getUpdate(int BITree[], int Size , int index, int update){
    index = index + 1;
    while(index <= Size){
        BITree[index] += update;
        index += index & (-index);
    }
}

int *constructBITree(int arr[], int n) {
    int *BITree = new int[n + 1];
    for (int i = 1; i <= n; i++)
        BITree[i] = 0;

    for (int i = 0; i < n; i++)
        getUpdate(BITree, n, i, arr[i]);

    return BITree;
}

int getSumFromLeftToRight(int BITree[], int left, int right) {
    return (getSum(BITree, right) - getSum(BITree, left - 1));
}



int main(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int n = 17;
    int *BITree = constructBITree(arr, n);

    int result = getSumFromLeftToRight(BITree, 2 , 5);
    cout << result << endl;
    getUpdate(BITree, n , 3 , 10);
    result = getSumFromLeftToRight(BITree, 2 , 5);
    cout << result << endl;
    result = getSumFromLeftToRight(BITree, 0 , 16);
    cout << result << endl;
    return 0;
}