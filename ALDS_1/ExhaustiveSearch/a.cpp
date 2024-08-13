#include<stdio.h>
#include<iostream>
using namespace std;

int n;
int A[50];

bool solve(int i, int m){

    if(m == 0) return true;
    if(i >= n) return false;

    return solve(i+1, m) || solve(i +1, m - A[i]);    
}

int main (){
    int q, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
    {
        scanf("%d", &m);

        if(solve(0, m)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
