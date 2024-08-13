#include<stdio.h>
#include<iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int PRIME_M = 1000003;
const int L = 13;

char Dic[PRIME_M][L];


// A->1, C->2, G->3, T->4に変換する
long long strToInt(char str[L]){
    vector<char> numStrArray;
   
    for (int i =0; i < L; i++) {
        char c = str[i];

        if (c == '\0') break;
            
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

    long long sum = 0;
    
    for (int i = 0; i < numStrArray.size(); i++)
    {
        long long num = numStrArray[i] - '0';
        sum += num * pow(10, numStrArray.size() - (i + 1));
    }
    
    return sum;
}


int h1(char str[L]) {
    long long key = strToInt(str);
    return key % PRIME_M;
}

int h2(char str[L]) {
    long long key = strToInt(str);
    return 1 + (key % (PRIME_M - 1));
}

int h(char str[L], int i){
    return (h1(str) + i*h2(str)) % PRIME_M;
}


void insert(char str[L]){
    for(int i =0;;i++){
        int hash = h(str, i);  
        if(strcmp(Dic[hash],str) == 0) {
            return;
        } else if(Dic[hash][0] == '\0') {
            strcpy(Dic[hash], str);
            return;
        }
    }
    return;
}


bool find(char str[L]) {

    for(int i =0;;i++){
        int hash = h(str, i);
        
        if(strcmp(Dic[hash], str) == 0) {
            return true;
        }else if(Dic[hash][0] == '\0'){
            return false;
        }
    }
    return false;
}


int main(){
    int n;
    char com[6], data[L];
    
    for (int i = 0; i < PRIME_M; i++) Dic[i][0] = '\0';
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", com, data);

        if(com[0] == 'i') {
            insert(data);
        } else if(com[0] == 'f') {
            if(find(data)){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }

    return 0;
}