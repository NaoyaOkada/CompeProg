#include<stdio.h>
#include<iostream>

using namespace std;
typedef long long llong;

const int WEIGHT_MAX = 10'000;
// const int WEIGHT_MAX = 3;


int GetMaxLoad(int n, int k, int w[], llong truckMax){
    int loadCnt=0, truckCnt = 0;
    llong p = truckMax;

    for (int i = 0; i < n; i++)
    {        
        p -= w[i];
        if(0 <= p) {
            loadCnt++;            
        }else{
            truckCnt++;
            if(k <= truckCnt) {
                break;                
            }else{
                i--;
                p = truckMax;
            }
        }
    }
    return loadCnt;
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int w[n];
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    llong left, middle, right, ans;
    left = 0;
    right = n * WEIGHT_MAX;

    int loadCnt = 0;

    while(left < right){
        middle = (left + right) / 2;
        loadCnt = GetMaxLoad(n, k, w, middle);

        if(loadCnt < n){
            left = middle +1;
        }else{
            right = middle;
        }
    }

    cout << right << endl;
    return 0;
}