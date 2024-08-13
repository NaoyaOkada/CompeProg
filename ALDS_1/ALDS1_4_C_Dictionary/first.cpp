#include<stdio.h>
#include<iostream>
#include<list>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

// 定数1000003を素数として使う
//const int PRIME_M = 1000003;
const int PRIME_M = 17;

std::array<char, 14> Dic[PRIME_M];

// A->1, C->2, G->3, T->4に変換する
int strToInt(array<char, 14> s){
    vector<char> numStrArray;

    for (char c : s) {
        if (c == '\0') {
            break;
        }

        int numStr = 0;

        switch (c) {
            case 'A':
                numStr = '1';
                break;
            case 'C':
                numStr = '2';
                break;
            case 'G':
                numStr = '3';
                break;
            case 'T':
                numStr = '4';
                break;
            default:
                cout << "error occured!" << endl;
                exit(1);
                break;
        }

        numStrArray.push_back(numStr);
    }

    int sum = 0;
    
    for (int i = 0; i < numStrArray.size(); i++)
    {
        int num = numStrArray[i] - '0';
        sum += num * pow(10, numStrArray.size() - (i + 1));
    }
    
    return sum;
}

int h1(array<char, 14> s) {
    int key = strToInt(s);
    return key % PRIME_M;
}

int h2(array<char, 14> s) {
    int key = strToInt(s);
    return 1 + (key % (PRIME_M - 1));
}

int h(array<char, 14> s, int i){
    return (h1(s) + i*h2(s)) % PRIME_M;
}

bool find(array<char, 14> s) {

    for(int i =0;;i++){
        int hash = h(s, i);
        
        if(Dic[hash] == s) {
            return true;
        }else if(Dic[hash][0] == '\0'){
            return false;
        }         
    }
    return false;
}

void insert(array<char, 14> s){
    for(int i =0;;i++){
        int hash = h(s, i);        
        if(Dic[hash] == s) {
            return;
        }else if(Dic[hash][0] == '\0'){
            Dic[hash] = s;
            return;
        }
    }
    return;
}

int main(){
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char com[6];
        array<char, 14> data;

        scanf("%s%s", com, data.data());

        if(strcmp(com, "insert") == 0) {
            insert(data);
        } else if(strcmp(com, "find") == 0) {
            if(find(data)){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}
