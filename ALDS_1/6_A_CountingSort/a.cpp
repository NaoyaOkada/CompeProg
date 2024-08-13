#include<stdio.h>
#include<iostream>
using namespace std;

const int MAX_SIZE = 10'000; // Aの要素の最大値
const int MAX_ELEMENT_CNT = 2'000'000; // Aの要素数
int A[MAX_ELEMENT_CNT];

void countingSort(int n){
    int C[MAX_SIZE+1], B[n+1];
    
    for (int i = 0; i <= MAX_SIZE; i++) C[i] = 0;

    for (int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    
    for (int i = 1; i <= MAX_SIZE; i++)
    {
        C[i] = C[i] + C[i-1];
    }
    

    for (int i = n-1; 0 <= i; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    

    for (int i = 1; i <= n; i++)
    {
        printf("%d", B[i]);
        if(i != n) printf(" ");
    }

    cout << endl;
    
    return;
}


int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    countingSort(n);

    return 0;
}