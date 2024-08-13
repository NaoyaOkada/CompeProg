#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
const int MAX = 25;
//const int MAX = 6;
const int NIL = -1;

typedef struct Node
{
    int parent;
    int leftChild;
    int rightChild;
    int rightSib;
    int leftSib;
} Node;


Node NODES[MAX];
int HEIGHT[MAX];
int DEPTH[MAX];

void setDepth(int nodeId, int depth){
    DEPTH[nodeId] = depth;

    if(NODES[nodeId].rightSib != NIL) {
        setDepth(NODES[nodeId].rightSib, depth);
    }

    if(NODES[nodeId].leftChild != NIL){
        setDepth(NODES[nodeId].leftChild, depth + 1);
    }
}


void divide(int nodeIndex){
    Node currNode = NODES[nodeIndex];

    if(NIL == currNode.leftChild && NIL == currNode.rightChild){
        HEIGHT[nodeIndex] = 0;
        return;
    }

    if(NIL != currNode.leftChild){
        divide(currNode.leftChild);
    }

    if(NIL != currNode.rightChild){
        divide(currNode.rightChild);
    }

    
    int m = max(HEIGHT[currNode.leftChild], HEIGHT[currNode.rightChild]) + 1;
    HEIGHT[nodeIndex] = m;
}

void printNode() {
    for (int i = 0; i < n; i++)    
    {
        Node n = NODES[i];
        int sib = -1;
        if(NIL != n.leftSib){
            sib = n.leftSib;
        } 
        if(NIL != n.rightSib) sib = n.rightSib;

        int degree = 0;
        if(n.leftChild != NIL){
            degree++;
        }

        if(n.rightChild != NIL){
            degree++;
        }


        cout << "node " << i << ": parent = " << n.parent << ", sibling = " << sib << ", degree = " << degree << ", depth = " << DEPTH[i] << ", height = " << HEIGHT[i] << ", ";
        if(NIL == n.parent){
            cout << "root";
        }else if(NIL == n.leftChild && NIL == n.rightChild){
            cout << "leaf";
        }else{
            cout << "internal node";       
        }
        cout << endl;
    }
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node n;
        n.parent = NIL;
        n.leftChild = NIL;
        n.rightChild = NIL;
        n.rightSib = NIL;
        n.leftSib = NIL;

        NODES[i] = n;
        HEIGHT[i] = -1;
        DEPTH[i] = NIL;
    }

    int nodeId, left, right;
    for (int i = 0; i < n; i++)
    {
        cin >> nodeId >> left >> right;
        NODES[nodeId].leftChild = left;
        NODES[nodeId].rightChild = right;

        if(NIL != right){
            NODES[right].parent = nodeId;
            if(NIL != left){
                NODES[left].rightSib = right;
            }
        }

        if(NIL != left){
            NODES[left].parent = nodeId;
            if(NIL != right){
                NODES[right].leftSib = left;
            }
        }
    }
    
    int rootIndex = 100;
    for (int i = 0; i < n; i++)
    {
        if(NODES[i].parent == NIL){
            rootIndex = i;
            break;
        }
    }
    
    setDepth(rootIndex, 0);
    divide(rootIndex);

    printNode();

    return 0;
}


// 13
// 0 3 1 4 10
// 1 2 2 3
// 2 0
// 3 0
// 4 3 5 6 7
// 5 0
// 6 0
// 7 2 8 9
// 8 0
// 9 0
// 10 2 11 12
// 11 0
// 12 0