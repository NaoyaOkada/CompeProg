#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 251;
int H[MAX];

int n;
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    for (int i = 1; i <= n; i++) {

        int key = H[i];
        int pk = i / 2;

        int lIndex = i * 2;
        int rIndex = lIndex + 1;

        int lkey = H[lIndex];
        int rkey = H[rIndex];

        cout << "node " << i << ": key = " << key << ", ";
        if (pk > 0) {
            cout << "parent key = " << H[pk] << ", ";
        }

        // cout << ", left key = " << lkey << ", right key = " << rkey << endl;
        if (1 <= lIndex && lIndex <= n) {
            cout << "left key = " << lkey << ", ";
        }

        if (1 <= rIndex && rIndex <= n) {
            cout << "right key = " << rkey << ",";
        }

        cout << endl;
    }
}