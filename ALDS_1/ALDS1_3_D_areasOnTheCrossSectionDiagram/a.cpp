#include<iostream>
#include<stdio.h>
#include<stack>
#include<utility>
#include<vector>
using namespace std;

int main(){
    stack<int> slashStack;
    vector<pair<int, int>> separatePools;
    
    char slash;

    //char* dummyData = "\\/\\\\__\\__\\/\\///_/_/\\_\\____/\\_\\_/_///\\\\/\\_\\/__/\\\\/\\_//__\\\\\\//\\_\\_\\\\/\\\\_/\\______/\\\\\\/_\\\\/\\/\\/_/\\///\\\\/\\_\\/_//\\_/_///\\\\_\\\\//_\\\\\\\\_/_/__\\_//_/\\\\_\\//\\/__\\__/\\__//\\\\\\/\\\\/\\//\\\\/_/_\\_\\_\\\\_\\///_\\____\\_\\\\__/\\\\\\";
    int sum = 0;

    //for(int i = 0; slash = dummyData[i]; i++){
    for(int i = 0; cin >> slash; i++){    
        if('\\' == slash){
            slashStack.push(i);            
        }else if('/' == slash && !slashStack.empty()) {

            int pairIndex = slashStack.top(); slashStack.pop();
            

            int sameLevelVolume = i - pairIndex;
            sum += sameLevelVolume;

            // 水たまりの個数を調べる処理
            while( !separatePools.empty() && pairIndex < separatePools.back().first) {
                sameLevelVolume += separatePools.back().second;
                separatePools.pop_back();
            }
            separatePools.push_back(make_pair(pairIndex, sameLevelVolume));       
        }
    }

    printf("%d\n", sum);
    printf("%ld", separatePools.size());

    if(1 <= separatePools.size()) {
        printf(" ");
    }else{
        printf("\n");
    }

    for(int i = 0; i < separatePools.size(); i++){
        pair<int, int> pool = separatePools[i];
        if(i == separatePools.size() - 1){
            printf("%d\n", pool.second);
        }else{
            printf("%d ", pool.second);
        }
    }
}
