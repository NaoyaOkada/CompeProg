#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
    int inputS, inputT;
    int S[10000];
    int T[10000];

    scanf("%d", &inputS);
    for (int i = 0; i < inputS; i++)
    {        
        scanf("%d", &S[i]);        
    }
    scanf("%d", &inputT);
    for (int i = 0; i < inputT; i++)
    {        
        scanf("%d", &T[i]);
    }

    int count = 0;

    for (int i = 0; i < inputT; i++)
    {
        for (int j = 0; j < inputS; j++)
        {
            if(T[i] == S[j]) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
}