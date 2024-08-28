#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int getLCS(string X, string Y) {
    int n = X.size();
    int m = Y.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    X = ' ' + X;
    Y = ' ' + Y;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i] == Y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[n][m];
}

int main() {

    int q;
    cin >> q;

    int n, m;

    int ans[q];
    for (int i = 0; i < q; i++) {
        // abcbdabという標準入力を受け取る
        string X, Y;
        cin >> X >> Y;

        ans[i] = getLCS(X, Y);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

//以下分割統治法を使った別解
int rec(string X, string Y) {

    if (1 >= X.size()) {
        if (X[0] == Y[Y.size() - 1]) {
            return 1;
        } else {
            return 0;
        }
    }

    if (1 >= Y.size()) {
        if (Y[0] == X[X.size() - 1]) {
            return 1;
        } else {
            return 0;
        }
    }

    if (X[X.size() - 1] == Y[Y.size() - 1]) {
        return rec(X.substr(0, X.size() - 1), Y.substr(0, Y.size() - 1)) + 1;
    } else {
        return max(rec(X.substr(0, X.size() - 1), Y), rec(X, Y.substr(0, Y.size() - 1)));
    }
}

int main2() {

    int q;
    cin >> q;

    int n, m;

    int ans[q];
    for (int i = 0; i < q; i++) {
        // abcbdabという標準入力を受け取る
        string X, Y;
        cin >> X >> Y;

        ans[i] = rec(X, Y);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}