#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

typedef struct Node {
    int key;
    Node *p;
    Node *r;
    Node *l;
} Node;

Node *NIL;
Node *T;

void init() {
    NIL = (Node *)malloc(sizeof(Node));
    NIL->key = 0;
    NIL->p = NIL;
    NIL->r = NIL;
    NIL->l = NIL;

    T = NIL;
}

void insertKey(int inputKey) {
    Node *z = (Node *)malloc(sizeof(Node));
    z->key = inputKey;
    z->l = NIL;
    z->r = NIL;

    Node *y = NIL;
    Node *x = T;

    while (x != NIL) {
        y = x;

        if (z->key < x->key) {
            x = x->l;
        } else {
            x = x->r;
        }
    }
    z->p = y;

    if (y == NIL) {
        T = z;
    } else if (z->key < y->key) {
        y->l = z;
    } else {
        y->r = z;
    }
}

void preorder(Node *node) {
    if (node == NIL)
        return;

    printf(" %d", node->key);
    preorder(node->l);
    preorder(node->r);
}

void inorder(Node *node) {
    if (node == NIL)
        return;

    inorder(node->l);
    printf(" %d", node->key);
    inorder(node->r);
}

void postorder(Node *node) {
    if (node == NIL)
        return;

    postorder(node->l);
    postorder(node->r);
    printf(" %d", node->key);
}

bool find(int key) {
    if (T == NIL)
        return false;

    Node *x = T;
    while (x != NIL) {
        if (key == x->key) {
            return true;
        }

        if (key < x->key) {
            x = x->l;
        } else {
            x = x->r;
        }
    }

    return false;
}

Node *findNode(int key) {
    Node *targetNode;

    if (T == NIL)
        return NIL;

    Node *x = T;
    while (x != NIL) {
        if (key == x->key) {
            return x;
        }

        if (key < x->key) {
            x = x->l;
        } else {
            x = x->r;
        }
    }

    return NIL;
}

void deleteOne(Node* trgtNode) {
    if(NIL == trgtNode) return;

    if (NIL == trgtNode->l && NIL == trgtNode->r) {
        if (NIL == trgtNode->p) {
            free(trgtNode);
            return;
        }

        if (trgtNode->key < trgtNode->p->key) { // 左を削除
            trgtNode->p->l = NIL;
        } else { //右を削除
            trgtNode->p->r = NIL;
        }
        free(trgtNode);
        return;
    }

    if (trgtNode->l != NIL && trgtNode->r == NIL) { // 左に子が或る場合
        // zの親の子をzの子に変更
        if (trgtNode->key < trgtNode->p->key) { // 親の左側にある
            trgtNode->p->l = trgtNode->l;

        } else { // 親の右側にある
            trgtNode->p->r = trgtNode->l;
        }
        // zの子の親を、zの親に変更
        trgtNode->l->p = trgtNode->p;

        free(trgtNode);
        return;
    }


    if (trgtNode->l == NIL && trgtNode->r != NIL) { //右に子が或る場合
        // zの親の子をzの子に変更
        if (trgtNode->key < trgtNode->p->key) { // 親の左側にある
            trgtNode->p->l = trgtNode->r;

        } else { // 親の右側にある
            trgtNode->p->r = trgtNode->r;
        }
        // zの子の親を、zの親に変更
        trgtNode->r->p = trgtNode->p;
        free(trgtNode);
        return;
    }
}


vector<Node*> inorderNode;

void makeInorder(Node* node){
    if (node == NIL)
        return;

    makeInorder(node->l);
    inorderNode.push_back(node);
    makeInorder(node->r);
}

Node* findNext(Node* node){
    inorderNode.clear();
    makeInorder(node);

    Node* nextNode = NIL;
    
    // inorderNodeの中からnodeの次のノードを探す
    for(int i = 0; i < inorderNode.size(); i++){
        if(inorderNode[i] == node){
            nextNode = inorderNode[i+1];
        }
    }
    return nextNode;

}

void deleteKey(int key) {
    Node *trgtNode = findNode(key);
    if(NIL == trgtNode) return;

    if(NIL != trgtNode->r && NIL != trgtNode->l) {
        Node* nextNode = findNext(trgtNode);
        if(NIL == nextNode) return;

        trgtNode->key = nextNode->key;
        deleteOne(nextNode);

    }else{
        deleteOne(trgtNode);
    }
}

int main() {
    init();
    int n;
    cin >> n;

    char command[10];
    int inputKey;

    // insertKey(10);
    // insertKey(22);
    // insertKey(5);
    // insertKey(8);
    // insertKey(1);
    // insertKey(21);
    // insertKey(7);
    // insertKey(9);
    // insertKey(30);
    // insertKey(31);
    // insertKey(29);
    // insertKey(38);
    // deleteKey(22);
    // inorder(T);
    // cout << endl;

    // if(find(10)){
    //   cout << "yes";
    // }else{
    //   cout << "no";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
      scanf("%s", command);

      if (strcmp(command, "insert") == 0) {
        cin >> inputKey;
        insertKey(inputKey);
      } else if (strcmp(command, "find") == 0) {
        cin >> inputKey;
        if (find(inputKey)) {
          cout << "yes" << endl;
        } else {
          cout << "no" << endl;
        }
      }else if(strcmp(command, "delete") == 0) {
        cin >> inputKey;
        deleteKey(inputKey);
      } else {
        inorder(T);
        printf("\n");
        preorder(T);
        printf("\n");
      }
    }

    return 0;
}
