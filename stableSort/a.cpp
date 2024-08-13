#include <iostream>

using namespace std;

static int MAX_CNT = 36;

struct Card {
    char suit;
    int value;
};

void bubble(int num, Card* cards) {
    for (size_t i = 0; i < num - 1; i++) {
        for (size_t j = num - 1; j > i; j--) {
            if (cards[j - 1].value > cards[j].value) {
                swap(cards[j - 1], cards[j]);
            }
        }
    }
}

void selection(int num, Card* cards) {
    for (size_t i = 0; i < num; i++) {
        int minj = i;
        for (size_t j = i; j < num; j++) {
            if (cards[j].value < cards[minj].value) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(cards[i], cards[minj]);
        }
    }
}

bool isStable(int num, Card* c1, Card* c2) {
    for (size_t i = 0; i < num; i++) {
        if (c1[i].suit != c2[i].suit) {
            return false;
        }
    }
    return true;
}

void trace(int num, Card* cards) {
    for (size_t i = 0; i < num; i++) {
        cout << cards[i].suit << cards[i].value;
        if (i != num - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Card C1[100], C2[200];
    int cardNum;
    cin >> cardNum;
    for (size_t i = 0; i < cardNum; i++) {
        cin >> C1[i].suit >> C1[i].value;
    }
    for (size_t i = 0; i < cardNum; i++) {
        C2[i] = C1[i];
    }
    bubble(cardNum, C1);
    selection(cardNum, C2);
    bool stableFlg = isStable(cardNum, C1, C2);
    trace(cardNum, C1);
    cout << "Stable" << endl;
    trace(cardNum, C2);
    if (stableFlg) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    return 0;
}
