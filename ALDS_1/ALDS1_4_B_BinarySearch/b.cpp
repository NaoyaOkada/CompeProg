#include<iostream>
#include<stdio.h>

using namespace std;


bool search(int A[], int n, int key){
    int left = 0;
    int right = n;

    while(left < right){
        int mid = (right + left) / 2;
        if(A[mid] == key){
            return true;
        }else if(key < A[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    int A[] = {5, 10, 13, 19, 22};

    int key = 20;
    int n = 5;

    bool ans = search(A, n, key);

    cout << ans << endl;
    
}