#ifndef _TRAVERSAL_H
#define _TRAVERSAL_H
#include "node.h"

void inOrderTreeTraversal(Node *node);
void PostOrderTreeTraversal(Node *node);
void PreOrderTreeTraversal(Node *node);
void _inOrderTreeTraversal(Node *node, void(*print)(Node *node));
void _PostOrderTreeTraversal(Node *node,void (*print)(Node *node));
void _PreOrderTreeTraversal(Node *node,void (*print)(Node *node));


#endif // _TRAVERSAL_H
