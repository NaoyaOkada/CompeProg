#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 44;
int DP[MAX + 1];

int cnt = 0;

int fib(int i) {
    cnt++;

    if (DP[i] > 0) {
        return DP[i];
    }

    int ans = fib(i - 2) + fib(i - 1);
    DP[i] = ans;
    return ans;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < MAX + 1; i++) {
        if (i == 0 || i == 1) {
            DP[i] = 1;
        } else {
            DP[i] = 0;
        }
    }

    int ans = fib(n);

    cout << ans << endl;
    // cout << cnt << endl;

    return 0;
}