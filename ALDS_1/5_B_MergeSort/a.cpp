#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX = 999'999'999;
int compareCnt = 0;

void merge(int A[], int left, int mid, int right) {
    int leftNum = mid - left;
    int rightNum = right - mid;

    int L[leftNum+1], R[rightNum+1];

    for (int i = 0; i < leftNum; i++)
    {
        L[i] = A[left + i];
    }
    L[leftNum] = MAX;
    
    for (int i = 0; i < rightNum; i++)
    {
        R[i] = A[mid+ i];
    }
    R[rightNum] = MAX;

    int i, j, loop;
    i = j = 0;

    loop = right - left;

    for (int k = 0; k < loop; k++)
    {
        if(L[i] <= R[j]){
            A[left + k] = L[i];
            i++;
        }else{
            A[left + k] = R[j];
            j++;
        }
        compareCnt++;
    }
    
    return;
}


void mergeSort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}



int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    mergeSort(A, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if(i  < n-1 ) {
            cout << " ";
        }else{
            cout << endl;
        }
    }
    cout << compareCnt << endl;

}