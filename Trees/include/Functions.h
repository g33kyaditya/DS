#ifndef FUNCTIONS_INCLUDED
#define FUNCTIONS_INCLUDED

#include "Node.h"

void insertBinaryTree();
void insertBinaryTreeFromFile();
Node* preorderTraverse(Node*);
Node* inorderTraverse(Node*);
Node* postorderTraverse(Node*);

void insert(int);
void insert(Node*,int);
Node* createNode(int);

#endif // FUNCTIONS_INCLUDED
