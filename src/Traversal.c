#include<stdio.h>
#include "node.h"
#include "Traversal.h"

void inOrderTreeTraversal(Node *node) {
  if(node->left != NULL)
  inOrderTreeTraversal(node->left);
  printf("%d ,", node->data);
  if(node->right != NULL)
  inOrderTreeTraversal(node->right);
}

void PreOrderTreeTraversal(Node *node) {
  printf("%d ,", node->data);
  if(node->left != NULL)
  PreOrderTreeTraversal(node->left);
  if(node->right != NULL)
  PreOrderTreeTraversal(node->right);
}

void PostOrderTreeTraversal(Node *node) {
  if(node->left != NULL)
  PostOrderTreeTraversal(node->left);
  if(node->right != NULL)
  PostOrderTreeTraversal(node->right);
  printf("%d ,", node->data);
}
