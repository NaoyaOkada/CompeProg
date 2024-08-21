#include <stdio.h>

#include <algorithm>
#include <iostream>
using namespace std;

const int MAX = 500'001;
// const int MAX = 6;
const int HEAP_SIZE = MAX - 1;

int H[MAX];

void maxHeapify(int i, int heapSize) {
    int leftChildIndex = i * 2;
    int rightChildIndex = leftChildIndex + 1;

    int largest = i;
    if (leftChildIndex <= heapSize && H[leftChildIndex] > H[i]) {
        largest = leftChildIndex;
    }

    if (rightChildIndex <= heapSize && H[rightChildIndex] > H[largest]) {
        largest = rightChildIndex;
    }

    if (largest != i) {
        swap(H[largest], H[i]);
        maxHeapify(largest, heapSize);
    }
}

void buildMaxHeap(int heapSize) {
    for (int i = heapSize / 2; i >= 1; i--) {
        maxHeapify(i, heapSize);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    buildMaxHeap(n);

    for (int i = 1; i <= n; i++) {
        cout << " " << H[i];
    }
    cout << endl;

    return 0;
}
