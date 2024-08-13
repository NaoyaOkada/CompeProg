#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100'000'000;

typedef struct Card {
    char Suit;
    int Number;
} Card;

int partition(Card A[], int p, int r) {
    int i = p - 1;
    int x = A[r].Number;

    for (int j = p; j < r; j++) {
        if (A[j].Number <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

void printCard(int n, Card A[]) {
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", A[i].Suit, A[i].Number);
    }
}

void merge(Card A[], int p, int m, int q) {
    if (p >= q)
        return;

    int headCnt = m - (p - 1);
    int lastCnt = q - m;
    Card Head[headCnt + 1], Last[lastCnt + 1];

    int i, j, k;
    i = j = k = 0;
    for (int i = p; i <= m; i++) {
        Head[j++] = A[i];
    }
    Card card;

    card.Suit = 'X';
    card.Number = MAX_SIZE;
    Head[headCnt] = card;

    j = 0;

    for (int i = m + 1; i <= q; i++) {
        Last[j++] = A[i];
    }
    Last[lastCnt] = card;

    i = j = 0;
    for (int k = p; k <= q; k++) {
        if (Head[i].Number <= Last[j].Number) {
            A[k] = Head[i];
            i++;
        } else {
            A[k] = Last[j];
            j++;
        }
    }

    return;
}

void quickSort(Card A[], int p, int r) {
    if (p >= r)
        return;

    int q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
}

void mergeSort(Card A[], int p, int q) {
    if (p >= q)
        return;
    int m = (q + p) / 2;
    mergeSort(A, p, m);
    mergeSort(A, m + 1, q);
    merge(A, p, m, q);
}

int main() {
    int n;
    scanf("%d", &n);

    Card A[n], B[n];

    char letter;
    int number;
    Card card;

    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &letter, &number);
        card.Suit = letter;
        card.Number = number;
        A[i] = card;
        B[i] = card;
    }

    quickSort(A, 0, n - 1);
    mergeSort(B, 0, n - 1);

    bool isStable = true;
    for (int i = 0; i < n; i++) {
        if (A[i].Suit != B[i].Suit) {
            isStable = false;
            break;
        }
    }
    if (isStable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }

    printCard(n, A);
    return 0;
}
