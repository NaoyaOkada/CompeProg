#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;


typedef struct Node {
    int Id;
    int Start;
    int End;
} Node;

const int MAX_NODES = 200;
Node *nodes[MAX_NODES];
int M[MAX_NODES][MAX_NODES];

int n;
int times = 0;

void dfs(Node *node) {
    if (node->Start != 0)
        return;

    node->Start = ++times;

    for (int j = 1; j <= n; j++) {
        int nodeId = node->Id;

        if (nodes[j]->Start == 0 && 1 == M[nodeId][j]) {
            dfs(nodes[j]);
        }
    }
    node->End = ++times;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            M[i][j] = 0;
        }
    }

    int out;
    int next;
    for (int i = 0; i < n; i++) {
        Node *node = new Node();
        cin >> node->Id;
        cin >> out;
        for (int j = 0; j < out; j++) {
            cin >> next;
            M[node->Id][next] = 1;
        }
        nodes[node->Id] = node;
    }

    for (int i = 1; i <= n; i++) {
        dfs(nodes[i]);
    }

    for (int i = 1; i < n + 1; i++) {
        Node *nod = nodes[i];
        cout << nod->Id << " " << nod->Start << " " << nod->End;
        cout << endl;
    }
    return 0;
}

// int main2() {

//     int n;
//     cin >> n;

//     Node *nodes[n + 1];

//     int out;
//     int next;
//     for (int i = 0; i < n; i++) {
//         Node *node = new Node();
//         cin >> node->Id;
//         cin >> out;

//         for (int j = 0; j < out; j++) {
//             cin >> next;
//             node->NextNodeIds.push_back(next);
//         }
//         nodes[node->Id] = node;
//     }

//     stack<Node *> S;
//     int times = 1;
//     nodes[1]->Start = times;
//     S.push(nodes[1]);

//     while (true) {
//         if (S.empty()) {
//             for (int i = 1; i < n + 1; i++) {
//                 if (0 == nodes[i]->Start) {
//                     nodes[i]->Start = ++times;
//                     S.push(nodes[i]);
//                     break;
//                     ;
//                 }
//             }
//             if (S.empty())
//                 break;
//         }

//         Node *cNode = S.top();
//         Node *nNode = nullptr;

//         if (false == cNode->NextNodeIds.empty())
//             nNode = nodes[cNode->NextNodeIds.front()];

//         if (nullptr == nNode) {
//             cNode->End = ++times;
//             S.pop();
//         } else {
//             cNode->NextNodeIds.erase(cNode->NextNodeIds.begin());
//             if (nNode->Start != 0)
//                 continue;

//             nNode->Start = ++times;
//             S.push(nNode);
//         }
//     }

//     for (int i = 1; i < n + 1; i++) {
//         Node *nod = nodes[i];
//         cout << nod->Id << " " << nod->Start << " " << nod->End;
//         cout << endl;
//     }

//     return 0;
// }