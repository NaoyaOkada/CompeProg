#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    int p[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> p[i - 1] >> p[i];
    }

    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int l = n - 1; l >= 1; l--) {
        for (int i = 1; i <= l; i++) {
            int j = n - l + i;
            dp[i][j] = 1 << 20;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << dp[1][n] << endl;
}