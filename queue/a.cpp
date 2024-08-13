#include<iostream>
#include<stdio.h>

const int MAX = 5;
int Queue[MAX];
int head, tail;

void initQueue(){
    head = tail = 0;
}

bool isFull(){
    return head == (tail + 1) % MAX;
}

void enQueue(int x){
    if(isFull()){
        std::cerr << "バッファが足りません" << std::endl;
        exit(1);
    }
    Queue[tail] = x;

    if(tail +1 >= MAX){
        tail=0;
    }else{
        tail++;    
    }
}

bool isEmpty(){
    return head == tail;
}

int deQueue(){
    if(isEmpty()){
        std::cerr << "Emptyです" << std::endl;
        exit(1);
    }

    int ret = Queue[head];

    if(head + 1 >= MAX){
        head = 0;
    } else {
        head++;
    }
    return ret;
}

int main() {
    return 0;
}

