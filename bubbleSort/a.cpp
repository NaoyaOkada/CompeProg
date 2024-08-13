#include <iostream>
#include <stdio.h>

// 1 <= N <= 100
// 0 <= A要素 <= 100
static const int MAX_N = 100;

int bubbleSort(int num, int data[]) {
    int i = 0;
    int flg = 1;
    int tmp;
    int swapCnt = 0;

    while (flg) {
        flg = 0;
        for (size_t j = num - 1; j > i; j--) {
            if (data[j - 1] > data[j]) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
                flg = 1;
                swapCnt++;
            }
        }
        i++;
    }
    return swapCnt;
}

void trace(int num, int data[]) {
    for (size_t i = 0; i < num; i++) {
        std::cout << data[i];
        if (i != num - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    int dataArray[MAX_N];
    int dataNum;

    std::cin >> dataNum;
    for (size_t i = 0; i < dataNum; i++) {
        scanf("%d", &dataArray[i]);
    }

    int cnt = bubbleSort(dataNum, dataArray);
    trace(dataNum, dataArray);

    printf("%d", cnt);

    std::cout << std::endl;
}
