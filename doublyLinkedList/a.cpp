#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct Node {
    int key;
    Node* prev, * next;
};

Node* nil;

void init() {
    nil = (Node*)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

Node* listSerchBy(int key) {
    Node* currentNode = nil->next;
    if (nil == currentNode) return nil;

    while (currentNode != nil && currentNode->key != key) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

void insert(int key) {
    Node* x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

void deleteNode(Node* target) {
    if (nil == target) return;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    free(target);
}

void deleteFirst() {
    deleteNode(nil->next);
}

void deleteLast() {
    deleteNode(nil->prev);
}

void deleteByKey(int key) {
    Node* target = listSerchBy(key);
    deleteNode(target);
}

void doCommand(char command[10], int key) {
    if ('i' == command[0]) {
        insert(key);
    }
    else if ('d' == command[0]) {
        if (strlen(command) > 6) {
            if ('F' == command[6]) deleteFirst();
            else if ('L' == command[6]) deleteLast();
        }
        else {
            deleteByKey(key);
        }
    }
}

void printList() {
    Node* targetNode = nil->next;
    while (nil != targetNode) {
        printf("%d", targetNode->key);
        targetNode = targetNode->next;
        if (nil == targetNode) {
            printf("\n");
        }
        else {
            printf(" ");
        }
    }
}

int main() {
    init();

    int num;
    scanf("%d", &num);

    int key;
    char command[10];

    for (int i = 0; i < num; i++) {
        scanf("%s%d", command, &key);
        doCommand(command, key);
    }

    printList();
}
