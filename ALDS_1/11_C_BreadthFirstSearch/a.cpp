#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;



typedef struct Node {
    int id;
    vector<int> adj;
} Node;

int main() {
    queue<Node*> q;
    int n, nodeId, neiborNum, neiborId;
    
    cin >> n;
    Node* nodes[n+1];
    int depth[n+1];

    for (int i = 0; i < n; i++)
    {
        Node* node = new Node();

        cin >> nodeId >> neiborNum;
        node->id = nodeId;

        for (int j = 0; j < neiborNum; j++)
        {
            cin >> neiborId;
            node->adj.push_back(neiborId);
        }
        nodes[i+1] = node;
        depth[i+1] = -1;
    }
    

    depth[1] = 0;
    q.push(nodes[1]);

    while(!q.empty()) {
        Node* cn = q.front();
        q.pop();

        while(cn->adj.size() > 0) {
            Node* neibor = nodes[cn->adj[0]];
            cn->adj.erase(cn->adj.begin());

            if(depth[neibor->id] < 0) depth[neibor->id] = depth[cn->id] + 1;
            q.push(neibor);
        }
    }


    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << depth[i] << endl;
    }
    
    return 0;
}