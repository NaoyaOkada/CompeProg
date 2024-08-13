#include<stdio.h>
#include<iostream>
#define QUEUE_MAX 100005

typedef struct {
    char name[100];
    int processTime;
} Process;

Process Queue[QUEUE_MAX];
int head, tail;

void initQueue(){
    head = tail = 0;
}

bool isFull(){
    return head == (tail + 1) % QUEUE_MAX;
}

bool isEmpty(){
    return head == tail;
}

void enQueue(Process x){
    if(isFull()){
        std::cerr << "バッファが足りません" << std::endl;
        exit(1);
    }
    Queue[tail] = x;

    if(tail +1 >= QUEUE_MAX){
        tail=0;
    }else{
        tail++;    
    }
}

Process deQueue(){
    if(isEmpty()){
        std::cerr << "Emptyです" << std::endl;
        exit(1);
    }

    Process ret = Queue[head];

    if(head + 1 >= QUEUE_MAX){
        head = 0;
    } else {
        head++;
    }
    return ret;
}

int main(){
    initQueue;


    int dataNum, quantumTime;
    scanf("%d %d", &dataNum, &quantumTime);

    for (int i = 0; i < dataNum; i++)
    {   
        Process p;
        scanf("%s %d", p.name, &p.processTime);
        enQueue(p);
    }
    
    int elapsedTime = 0;
    while(isEmpty() == false){
        Process currentP = deQueue();
        if(currentP.processTime <= quantumTime){
            elapsedTime += currentP.processTime;
            std::cout << currentP.name << " " << elapsedTime << std::endl;
        } else {
            currentP.processTime -= quantumTime;
            elapsedTime += quantumTime;
            enQueue(currentP);
        }
    }

    return 0;
}