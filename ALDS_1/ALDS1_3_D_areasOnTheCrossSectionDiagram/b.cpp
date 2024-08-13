#include<iostream>
#include<stdio.h>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

int main(){
    vector<pair<int, int>> separatePools;

    separatePools.push_back(make_pair(1, 1));
    separatePools.push_back(make_pair(3, 1));

    int pairIndex = 0;
    int currentVal = 5;

    // separatePoolsからひとつずつ取り出して、pairIndexと比較
    // pairIndex < pool.first なら、取り出して合算
    // pairIndex >= pool.first なら、break
    // これを繰り返す
    while(true){
        pair<int, int> pool = separatePools.back();
        if(pairIndex < pool.first){
            currentVal += pool.second;
            separatePools.pop_back();
        }else{
            break;
        }
    }

    cout << currentVal << endl;
}