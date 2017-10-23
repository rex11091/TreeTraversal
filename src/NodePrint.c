#include "NodePrint.h"
#include <stdio.h>

void printInteger(Node *node){
    printf("%d, ",node->data);
}

void printDecoratedInteger(Node *node){
    printf("(***)%d, ",node->data);
}

void printString(Node *node){
    printf("%s, ",node->data);
}
