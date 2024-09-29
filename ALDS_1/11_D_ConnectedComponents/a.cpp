#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct Node {
    int id;
    vector<Node*> adj;
    bool isIn;
} Node;

const int MAX_N = 10;
Node *nodes[MAX_N];
stack<Node *> S;

int n;

bool globalResult = false;
int goalNodeId;

/// 渡されたnodeのadjからまだSに入っていないtopを取り出す。取り出せたらadjから削除する
Node* getAdjTop(Node* node){
    if(node->adj.empty()) return nullptr;
    for (int i = 0; i < node->adj.size(); i++)
    {
        if(node->adj[i]->isIn == false){
            Node* target = node->adj[i];
            node->adj.erase(node->adj.begin() + i);
            return target;
        }
    }
    return nullptr;
}


bool dfs() {
    if(globalResult) return true;

    if(S.empty()) return false;

    Node* node = S.top();

    if(goalNodeId == node->id) {
        globalResult = true;
        return globalResult;
    }

    Node* adjTop = getAdjTop(node);
    if(nullptr == adjTop) {
        S.pop();
        return false;
    }

    adjTop->isIn = true;
    S.push(adjTop);

    return dfs();
}

int main() { 
    int m; // friendsの関係の数
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        Node* n = new Node();
        n->id = i;
        n->isIn = false;        
        nodes[i] = n;
    }
    
    int first, second;
    for (int i = 0; i < m; i++)
    {
        cin >> first >> second;
        nodes[first]->adj.push_back(nodes[second]);
        nodes[second]->adj.push_back(nodes[first]);
    }

    int q;
    cin >> q;

    string ans[q];
    int start, goal;

    // nodesのdeep copyを作成
    
    Node* nodesCopy[n];
    for (int i = 0; i < n; i++)
    {
        Node* newNode = new Node();
        newNode->id = nodes[i]->id;
        newNode->isIn = nodes[i]->isIn;
        newNode->adj = nodes[i]->adj;
        // 他の必要なプロパティもコピーする

        nodesCopy[i] = newNode;
    }

    for (int i = 0; i < q; i++)
    {
        globalResult = false;
        cin >> start >> goalNodeId;

        for (int j = 0; j < n; j++)
        {
            nodes[j]->id = nodesCopy[j]->id;
            nodes[j]->isIn = nodesCopy[j]->isIn;
            nodes[j]->adj = nodesCopy[j]->adj;
        }        

        while(!S.empty()){
            S.pop();
        }

        nodes[start]->isIn = true;
        S.push(nodes[start]);

        dfs();

        if(globalResult){
            cout << "yes";
        }else{
            cout << "no";
        }
        cout << endl;
    }  

    return 0;
}