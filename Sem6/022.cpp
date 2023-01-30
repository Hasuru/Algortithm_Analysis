// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

// Estrutura para representar um no da arvore
typedef struct node {
  bool isBlack; // No preto?
  bool isNull;  // No nulo?
  int value;    // Valor
  struct node *left, *right; // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v) {
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull  = (v==0);
  aux->isBlack = (v>=0);
  aux->value   = abs(v);
  return aux;
}

// Ler input em preorder
Node readPreOrder() {
  int v;
  cin >> v;
  Node aux = mkNode(v);
  if (v!=0) {
    aux->left  = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}

// Menor valor da arvore
int minimum(Node t) {
  if (t->isNull) return INT_MAX;
  int minLeft  = minimum(t->left);
  int minRight = minimum(t->right);
  return min(t->value, min(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t) {
  if (t->isNull) return INT_MIN;
  int maxLeft  = maximum(t->left);
  int maxRight = maximum(t->right);
  return max(t->value, max(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t) {
  if (t->isNull) return 0;
  return 1 + size(t->left) + size(t->right);
}

// ---------------------------------------------------

bool blackDepth(Node t) {
    int left = 0, right = 0;
    Node temp = t;
    while (!temp->right->isNull) {
        if (temp->right->isBlack) right++;
        temp = temp->right;
    }
    temp = t;
    while (!temp->left->isNull) {
        if (temp->left->isBlack) left++;
        temp = temp->left;
    }
    return left == right;
}

bool isBST(Node t, int min, int max) {
  if (t->isNull) return true;
  if (t->value < min) return false;
  if (t->value > max) return false;
  return (isBST(t->left, min, t->value) && isBST(t->right, t->value, max));
}

bool isRBTree(Node t) {
    if (t->isNull) return true; // nos nulos sao sempre pretos (folhas)
    if (!t->isBlack && (!t->left->isBlack || !t->right->isBlack)) return false; // vermelhos nao geram vermelhos
    if (!blackDepth(t)) return false;
    return isRBTree(t->left) && isRBTree(t->right);
}

int main() {
  int i, n;
  Node root;

  cin >> n;
  for (i=0; i<n; i++) {
    root = readPreOrder();
    if(isBST(root, INT_MIN, INT_MAX) && isRBTree(root) && root->isBlack) printf("SIM\n");
    else printf("NAO\n");
  }

  return 0;
}