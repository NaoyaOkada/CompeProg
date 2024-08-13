#include <stdio.h>
#include <iostream>
#include <list>
#include <string.h>
using namespace std;

list<int> L;

void deleteByKey(int key){
    for(list<int>::iterator it = L.begin(); it != L.end(); it ++){
        if( *it == key) {
            L.erase(it);
            break;;
        }
    }
}

void doCommand(char command[10], int key) {
    if ('i' == command[0]) {
        L.push_front(key);
    }
    else if ('d' == command[0]) {
        if (strlen(command) > 6) {
            if ('F' == command[6]) L.pop_front();
            else if ('L' == command[6]) L.pop_back();
        }
        else {
            deleteByKey(key);
        }
    }
}

int main() {
    int num;
    scanf("%d", &num);

    int key;
    char command[10];

    for (int i = 0; i < num; i++) {
        scanf("%s%d", command, &key);
        doCommand(command, key);
    }

    int i = 0;
    for(list<int>::iterator it = L.begin(); it != L.end(); it++ ){
        if(i++) printf(" ");
        printf("%d", *it);
    }

    printf("\n");
}
