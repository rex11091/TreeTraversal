#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>

typedef struct Node Node;
struct Node {
  Node *left;
  Node *right;
  uint32_t data;    // will be change ltr ,no neccessary integer

};


#endif // _NODE_H
