#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int m[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }

    int v;
    int outNum;
    int dv;
    for (int i = 0; i < n; i++) {
        cin >> v >> outNum;

        for (int j = 0; j < outNum; j++) {
            cin >> dv;
            m[v - 1][dv - 1] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j];

            if (j != n - 1)
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}