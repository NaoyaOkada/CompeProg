#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include <map>
using namespace std;

const int MAX_NODES = 100'000;
const int NIL = -1;

int n;

typedef struct Node {
    int parentId;
    int leftChildId;
    int rightSibId;
} Node;

Node NODES[MAX_NODES];
int DEPTHES[MAX_NODES];



void setDepth(int nodeId, int d){
    DEPTHES[nodeId] = d;

    if(NODES[nodeId].rightSibId != NIL) {
        setDepth(NODES[nodeId].rightSibId, d);
    }

    if(NODES[nodeId].leftChildId != NIL){
        setDepth(NODES[nodeId].leftChildId, d + 1);
    }

    return;
}


void printNodes(){

    int parentId, depth, leftChild;
    for (int i = 0; i < n; i++)
    {
        parentId = NODES[i].parentId;
        leftChild = NODES[i].leftChildId;
        depth = DEPTHES[i];
        
        cout << "node " << i << ": parent = " << parentId  << ", depth = " << depth << ", ";

        if(NIL == parentId){
            cout << "root";
        }else if(NIL == leftChild){
            cout << "leaf";
        }else{
            cout << "internal node";            
        }

        cout << ", [";
        if(NIL != leftChild) {
            cout << leftChild;

            int rightSibID = NODES[leftChild].rightSibId;

            while(NIL != rightSibID) {
                cout << ", " << rightSibID;
                rightSibID = NODES[rightSibID].rightSibId;
            }
        }

        cout << "]" << endl;     
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        NODES[i].parentId = NIL;
        NODES[i].leftChildId = NIL;
        NODES[i].rightSibId = NIL;
    }
    
    // 一行づつ読み込み
    int nodeId, currentChildId, prevChildId, childrenCnt;
    for (int i = 0; i < n; i++)
    {
        cin >> nodeId >> childrenCnt;
        for (int j = 0; j < childrenCnt; j++)
        {
            cin >> currentChildId;
            
            if(j == 0){
                NODES[nodeId].leftChildId = currentChildId;
            } else {
                NODES[prevChildId].rightSibId = currentChildId;
            }

            prevChildId = currentChildId;
            NODES[currentChildId].parentId = nodeId;
        }        
    }
    
    int rootIndex = 100;

    for (int i = 0; i < n; i++)
    {
        if(NODES[i].parentId == -1){
            rootIndex = i;
            break;
        }
    }
    setDepth(rootIndex, 0);
    printNodes();
    return 0;
}