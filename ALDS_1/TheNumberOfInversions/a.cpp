#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 200'000;
const int SENTINEL = 2'000'000'000;
typedef long long llong;

int L[MAX/2 + 2], R[MAX/2 + 2];

llong merge(int A[],int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    llong cnt = 0;
    for (int k = left; k < right; k++)
    {
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
            cnt += n1 - i;
        }
    }
    return cnt;
}

llong mergeSort(int A[], int left, int right){
    llong v1, v2, v3;
    v1 = v2 = v3 = 0;
    if(left + 1 < right){
        int mid = (left + right) / 2;
        v1 = mergeSort(A, left, mid);
        v2 = mergeSort(A, mid, right);
        v3 = merge(A, left, mid, right);
    }else {
        return 0;
    }
    return v1 + v2 + v3;
}

int main() {
    llong cnt = 0;
    long long n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    cnt = mergeSort(A, 0, n);

    cout << cnt << endl;
    return 0;
}