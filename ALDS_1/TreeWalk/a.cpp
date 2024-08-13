#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


const int MAX_CNT = 25;
//const int MAX_CNT = 8;
const int NIL = -1;

typedef struct Node {
    int parent;
    int left;
    int right;
} Node;

Node NODES[MAX_CNT];
vector<int> preorderIds;
vector<int> inorderIds;
vector<int> postorderIds;

int n;

void preorder(int nodeId) {
    if(NIL == nodeId) return;
    preorderIds.push_back(nodeId);
    preorder(NODES[nodeId].left);
    preorder(NODES[nodeId].right);
}

void inorder(int nodeId) {
    
    if(NIL == nodeId) return;
        
    Node n = NODES[nodeId];

    inorder(n.left);
    inorderIds.push_back(nodeId);
    inorder(n.right);
}

void postorder(int nodeId){
    if(NIL == nodeId) return;
    Node n = NODES[nodeId];

    postorder(n.left);
    postorder(n.right);
    postorderIds.push_back(nodeId);
}

int main() {
    cin >> n;

    int nodeId, left, right;

    for (int i = 0; i < n; i++)
    {
        Node n;
        n.parent = NIL;
        n.left = NIL;
        n.right = NIL;
        NODES[i] = n;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> nodeId >> left >> right;
        
        if(left != NIL) NODES[left].parent = nodeId;        
        if(right != NIL) NODES[right].parent = nodeId;

        NODES[nodeId].left = left;
        NODES[nodeId].right = right;
    }


    int rootId = 100;
    for (int i = 0; i < n; i++)    
    {
        if(NIL == NODES[i].parent){
            rootId = i;
            break;;
        }
        /* code */
    }
    
    preorder(rootId);

    cout << "Preorder" << endl;
    for (int i = 0; i < preorderIds.size(); i++) {
        std::cout << " " <<  preorderIds[i];
    }

    cout << endl;

    inorder(rootId);
    cout << "Inorder" << endl;
    for (int i = 0; i < inorderIds.size(); i++) {
        std::cout << " " << inorderIds[i];
    }

    cout << endl;

    postorder(rootId);
    cout << "Postorder" << endl;
    for (int i = 0; i < postorderIds.size(); i++) {
        std::cout << " " << postorderIds[i];
    }

    cout << endl;
}