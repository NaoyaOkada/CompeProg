#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX = 1000;
int stack[MAX];
int topPointer = 0;

void initialize() {
    topPointer = 0;
    stack[0] = 0;
}

bool isEmpty() {
    return topPointer <= 0;
}

bool isFull() {
    return topPointer >= MAX - 1;
}

void push(int x) {
    if (isFull()) {
        std::cerr << "Error: Stack is Full!" << std::endl;
        exit(1);
    }

    topPointer++;
    stack[topPointer] = x;
}

int pop() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty!" << std::endl;
        exit(1);
    }

    int result = stack[topPointer];
    topPointer--;

    return result;
}

int main(int argc, char* argv[]) {
    initialize();
    int a, b;
    
    char s[1'00];
    while ( scanf("%s", s) != EOF ) {
        if( s[0] == '+'){
            a = pop();
            b = pop();
            push(a + b);
        } else if (s[0] == '-') {
            a = pop();
            b = pop();
            push(b - a);
        } else if(s[0] == '*') {
            a = pop();
            b = pop();
            push(a * b);
        } else {
            push(atoi(s));
        }
    }

    printf("%d\n", pop());    
    return 0;
}
