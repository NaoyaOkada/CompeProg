#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long cnt;
vector<int> G;

void insertionSort(int num, int* data, int g) {
    for (size_t i = g; i < num; i++) {
        int currentNum = data[i];
        
        int j = i - g;
        while (j >= 0 && data[j] > currentNum) {
            data[j + g] = data[j];
            j = j - g;
            cnt = cnt + 1;
        }
        data[j + g] = currentNum;
    }
}

void shellSort(int num, int* data) {
    for (size_t h = 1;;) {
        if (h > num) break;
        
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        insertionSort(num, data, G[i]);
    }
}

int main() {
    int dataNum;
    cin >> dataNum;
    int data[dataNum];

    for (size_t i = 0; i < dataNum; i++) {
        cin >> data[i];
    }

    shellSort(dataNum, data);

    cout << G.size() << endl;
    for (int i = G.size() - 1; i >= 0; i--) {
        cout << G[i];
        if (i) cout << " ";
    }
    
    cout << endl;

    cout << cnt << endl;
    for (size_t i = 0; i < dataNum; i++) {
        cout << data[i] << endl;
    }
}
