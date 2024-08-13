#include<iostream>
#include<stdio.h>

using namespace std;

bool binarySeach(int A[], int n, int key){
    int left = 0;
    int right = n;

    while(left < right){
        int mid = (right + left) / 2;
        if(A[mid] == key) {
            return true;
        }else if(key < A[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return false;

    // bool flg = false;
    // int s = 0;
    // int e = n - 1;

    // do {
    //     if(A[s] == key)
    //     {
    //         flg = true;
    //         break;
    //     }
    //     int m = (e - s) / 2 + s;
    //     if(m == s) m++; // 最後の三つになったとき
            
    //     if(A[m] <= key){
    //         s = m;
    //         if(A[s] == key){
    //             flg = true;
    //             break;;
    //         }
    //     }else{
    //         e = m - 1;
    //     }
    // } while(s != e);
    // return flg;
}


int main(){
    
    int n, q, key;
    int S[100000];
    int T[50000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);

    int count = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &key);
        if (binarySeach(S, n, key)) count++;
    } 

    cout << count << endl;
}