#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 1'000;
const int MAXV = 10'000;

int minOnAll = MAXV;

int A[MAX], B[MAX], C[MAX];
int T[MAXV + 1];

int solve(int n) {
    int ans = 0;

    for (int i = 0; i < n; i++) T[B[i]] = i;

    for (int i = 0; i < n; i++)
    {
        int cur = i;
        if(C[cur]) continue;

        int m = MAXV, sum = 0, an = 0, v;
        while(true) {
            if(C[cur]) break;

            v = A[cur];
            sum += v;
            an++;
            C[cur] = true;

            m = min(m, v);
            cur = T[v];
        }

        int ans1 = sum + (an - 2)  * m;
        int ans2 = sum + m + (1 + an) * minOnAll;
        ans += min(ans1, ans2);
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        B[i] = A[i];
        C[i] = false;
        minOnAll = min(minOnAll, A[i]);
    }
    sort(B, B + n);

    int ans = solve(n);
    cout << ans << endl;
    return 0;
}