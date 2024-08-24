#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

// const int INFTY(1 << 30);
const int MAX = 100'000'000;
int A[MAX + 1];
int H = 0;

void maxHeapify(int i) {
    int leftChildIndex = i * 2;
    int rightChildIndex = leftChildIndex + 1;

    int largest = i;
    if (leftChildIndex <= H && A[leftChildIndex] > A[i]) {
        largest = leftChildIndex;
    }

    if (rightChildIndex <= H && A[rightChildIndex] > A[largest]) {
        largest = rightChildIndex;
    }

    if (largest != i) {
        swap(A[largest], A[i]);
        maxHeapify(largest);
    }
}

int heapExtractMax() {
    if (H < 1)
        return (1 << 30);

    int max = A[1];
    A[1] = A[H];
    H--;

    maxHeapify(1);

    return max;
}

void heapIncreaseKey(int i, int key) {
    A[i] = key;

    // int parent = i / 2;
    while (i > 1 && A[i / 2] < A[i]) {
        swap(A[i / 2], A[i]);
        i = i / 2;
    }

    return;
}

void insert(int key) {
    H++;
    heapIncreaseKey(H, key);
}

int main() {
    int n;
    string com;

    // 標準入力からinsert 8というような文字列と数字を取得
    while (cin >> com) {
        if (com == "insert") {
            cin >> n;
            insert(n);
        } else if (com == "extract") {
            printf("%d\n", heapExtractMax());
        } else if (com == "end") {
            break;
        }
    }

    return 0;
}