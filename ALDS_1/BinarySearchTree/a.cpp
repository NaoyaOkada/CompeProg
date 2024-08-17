#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// void insertKey(Node **T, int inputKey) {
//   Node *z = (Node *)malloc(sizeof(Node));
//   z->key = inputKey;
//   *T = z;
// }

// int main() {
//   init();
//   Node *T;
//   T = NIL;
//   insertKey(&T, 5);
//   return 0;
// }

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

int main() {
  init();
  int n;
  cin >> n;

  char command[10];
  int inputKey;

  for (int i = 0; i < n; i++) {
    scanf("%s", command);

    if (strcmp(command, "insert") == 0) {
      cin >> inputKey;
      insertKey(inputKey);
    } else {
      inorder(T);
      printf("\n");
      preorder(T);
      printf("\n");
    }
  }
  return 0;
}
