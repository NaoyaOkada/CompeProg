#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX_NODES = 100'000;
int n;

typedef struct Node {
    int id;
    char t;
    int nodeCnt;
    std::vector<int> children;
}Node;

Node nodes[MAX_NODES];



int getParentId(int childId) {
    int parentId = -1;


    for (int i = 0; i < n; i++)
    {
        if(i == childId) continue;

        Node node = nodes[i];
        if(0 == node.nodeCnt) continue;

        for (int j = 0; j < node.nodeCnt; j++)
        {
            if(node.children[j] == childId){
                parentId = node.id;
                break;
            }
        }
    }
    return parentId;
}

int getDepth(int nodeId, int depth = 0){

    int parentId = getParentId(nodeId);
    if(-1 == parentId) return depth;
    if(20 <= depth) return 20;

    return getDepth(parentId, depth + 1);
}



int main() {
    
    cin >> n;

    int id, nodeCnt, childId;
    
    for (int i = 0; i < n; i++)
    {
        cin >> id >> nodeCnt;
        Node node;

        node.id = id;
        node.nodeCnt = nodeCnt;
        
        for (int j = 0; j < nodeCnt; j++)
        {
            cin >> childId;
            node.children.push_back(childId);
        }
        nodes[i] = node;
    }

    sort(nodes, nodes + n, [](const Node& a, const Node& b) {
        return a.id < b.id;
    });

    int parentId;
    Node curNode;
    for (int i = 0; i < n; i++)
    {
        curNode = nodes[i];
        parentId = getParentId(curNode.id);
        int depth = getDepth(curNode.id);

        cout << "node " << curNode.id << ": parent = " << parentId << ", depth = " << depth << ", ";

        if(-1 == parentId){
            cout << "root";
        }else if(curNode.nodeCnt > 0){
            cout << "internal node";
        }else{
            cout << "leaf";
        }
        cout << ", [";

        if(curNode.nodeCnt > 0){
            for (int i = 0; i < curNode.nodeCnt; i++)
            {
                cout << curNode.children[i];
                if(i != curNode.nodeCnt-1) {
                    cout << ", ";
                }
            }
        }
        cout << "]" << endl;
    }
    
    return 0;
}