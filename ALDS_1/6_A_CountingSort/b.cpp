#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

const int MAX = 2'000'000; // Aの要素数
const int VMAX = 10'000; // Aの要素の最大値

int main(){
    unsigned short *A, *B;

    int C[VMAX+ 1];
    int n;

    scanf("%d", &n);

    // short型の配列を動的に確保
    A = (unsigned short *)malloc(sizeof(short) * n);
    B = (unsigned short *)malloc(sizeof(short) * (n + 1));


    for (int i = 0; i < VMAX; i++) C[i] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%hu", &A[i]);
        C[A[i]]++;
    }

    for (int i = 1; i <= VMAX; i++)
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

    return 0;
}
