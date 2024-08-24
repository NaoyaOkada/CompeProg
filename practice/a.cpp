#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

typedef struct Check {
    bool solved;
    bool done;
} Check;


const int n = 5;
int A[n] = {1, 2, 3, 4, 5};

const int target = 13;

Check C[n+1][target+1];

int call = 0;
int sel = 0;

bool rec2(int i, int x) {
    call++;

    if (x == 0) {
        return true;
    } else if (i >= n) {
        return false;
    }

    return rec2(i+1, x) || rec2(i+1, x - A[i]);
}



bool rec(int i, int x) {
    
    if (C[i][x].done) {
        sel++;
        return C[i][x].solved;
    }
    call++;
    if (x == 0) {
        C[i][x].solved = true;
        C[i][x].done = true;
        return true;
    } else if (x < 0 || i >= n) {
        C[i][x].solved = false;
        C[i][x].done = true;
        return false;
    } else if (rec(i+1, x)){
        C[i][x].solved = true;
        C[i][x].done = true;
        return true;
    } else if (rec(i+1, x - A[i])) {
        C[i][x].solved = true;
        C[i][x].done = true;
        return true;
    } else {
        C[i][x].solved = false;
        C[i][x].done = true;
        return false;
    }
}



int main() {

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            C[i][j].solved = false;
            C[i][j].done = false;            
        }        
    };
    


    bool result = rec(0, target);

    cout << result << endl;
    cout << call << endl;
    cout << sel << endl;

    return 0;
}
