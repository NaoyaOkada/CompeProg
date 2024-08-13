#include <iostream>
#include <stdio.h>

using namespace std;

int search(int A[], int n, int key) {
    int i = 0;
    A[n] = key;
    while (A[i] != key)
        i++;
    return i != n;
}

int main() {
    int n, q, key, S[10000 + 1];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);

    int count = 0;
    for (int i = 0; i < q; i++) {
        scanf("%d", &key);
        if (search(S, n, key))
            count++;
    }

    cout << count << endl;
}