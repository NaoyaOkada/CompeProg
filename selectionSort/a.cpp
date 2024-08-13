#include <iostream>
#include <stdio.h>

using namespace std;

static const int MAX_CNT = 100;

int selectionSort(int num, int* data) {
    int sw = 0;
    for (size_t i = 0; i < num; i++) {
        int minj = i;

        for (size_t j = i; j < num; j++) {
            if (data[minj] > data[j]) {
                minj = j;
            }
        }

        if (minj != i) {
            swap(data[i], data[minj]);
            sw++;
        }
    }
    return sw;
}

void trace(int num, int* data) {
    for (size_t i = 0; i < num; i++) {
        cout << data[i];
        if (i != num - 1) cout << " ";
    }
}

int main(int argc, char* argv[]) {
    int data[MAX_CNT];
    int num;
    cin >> num;
    for (size_t i = 0; i < num; i++) {
        cin >> data[i];
    }

    int cnt = selectionSort(num, data);

    trace(num, data);
    cout << endl;

    cout << cnt << endl;

    return 0;
}
