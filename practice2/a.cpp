#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

const int MAXV = 1'000'000;
using namespace std;

void merge(int A[], int left, int mid, int right) {
    int headCnt = mid - left + 1;
    int tailCnt = right - mid;
    int HEAD[headCnt + 1];
    int TAIL[tailCnt + 1];

    int j = 0;
    for (int i = left; i <= mid; i++)
    {
        HEAD[j] = A[i];
        j++;
    }
    HEAD[j] = MAXV;

    j = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        TAIL[j] = A[i];
        j++;
    }
    TAIL[j] = MAXV;

    int i;
    i = j = 0;
    int loopCnt = right -left;
    
    for (int k = 0; k <= loopCnt; k++)
    {
        if(HEAD[i] <= TAIL[j]){
            A[left + k] = HEAD[i];
            i++;
        }else{
            A[left + k] = TAIL[j];
            j++;
        }
    }
    return;
}

void mergeSort(int A[], int left, int right){
    if(left + 1 > right) return;

    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid+1, right);
    merge(A, left, mid, right);
}

int main() {
    int n = 7;
    int A[n] = {1, 32, 4, 5, 0, 2, 8};

    int left = 0;
    mergeSort(A, left, 6);
    return 0;
}