#include "unity.h"
#include "Traversal.h"
#include "NodePrint.h"
#include <stdio.h>

Node node1 = {NULL, NULL, 1};
Node node3 = {NULL, NULL, 3};
Node node7 = {NULL, NULL, 7};
Node node24 = {NULL, NULL, 24};
Node node28 = {NULL, NULL, 28};
Node node2 = {&node1, &node3, 2};
Node node5 = {NULL, &node7, 5};
Node node15 = {NULL, NULL, 15};
Node node25 = {&node24, &node28, 25};
Node node4 = {&node2, &node5, 4};
Node node20 = {&node15, &node25, 20};
Node node10 = {&node4, &node20, 10};

StringNode nodeAli = {NULL,NULL,"Ali"};
StringNode nodeAbu = {NULL,NULL,"Abu"};
StringNode nodeDavid = {NULL,NULL,"David"};
StringNode nodeSteven = {NULL,NULL,"Steven"};
StringNode nodeAbraham = {&nodeAli,&nodeAbu,"Abraham"};
StringNode nodeNoah = {&nodeDavid,&nodeSteven,"Noah"};
StringNode nodeAdam = {&nodeAbraham,&nodeNoah,"Adam"};

int inOrderGoldenValues[] = { 1, 2, 3, 4, 5, 7, 10, 15, 20, 24, 25, 28 };
int preOrderGoldenValues[] = { 10, 4, 2, 1, 3, 5, 7, 20, 15, 25, 24, 28 };
int postOrderGoldenValues[] = { 1, 3, 2, 7, 5, 4, 15, 24, 28, 25, 20, 10 };

int CurIndex;
int *goldenValues;
int indexLimit;


void setUp(void){
  CurIndex = 0;
}

void tearDown(void){}

void verifyinOrderrIntegers(Node *node){
  char error[1028];
  if(goldenValues[CurIndex] != node->data){
    sprintf(error , "at index %d , expected %d but was %d ",CurIndex,goldenValues[CurIndex],node->data);
    TEST_FAIL_MESSAGE(error);
  }
  if(CurIndex >= indexLimit){
    sprintf(error , "The number of values is greater than the number of golden values(%d) ",indexLimit); //error message nid change
    TEST_FAIL_MESSAGE(error);
  }
  CurIndex ++;
}


void test__inOrderTreeTraversal_is_correct_order(void){
  goldenValues = inOrderGoldenValues;
  indexLimit = sizeof(inOrderGoldenValues)/sizeof(int);
  _inOrderTreeTraversal(&node10,verifyinOrderrIntegers);
  if(CurIndex < indexLimit){
    char error[1028];
    sprintf(error, "The number of values is lesser than the number of golden values (%d) ",indexLimit);
    TEST_FAIL_MESSAGE(error);

  }
}

void test__postOrderTreeTraversal_is_correct_order(void){
  goldenValues = postOrderGoldenValues;
  indexLimit = sizeof(postOrderGoldenValues)/sizeof(int);
  _PostOrderTreeTraversal(&node10,verifyinOrderrIntegers);
  if(CurIndex < indexLimit){
    char error[1028];
    sprintf(error, "The number of values is lesser than the number of golden values (%d) ",indexLimit);
    TEST_FAIL_MESSAGE(error);

  }
}

void test__preOrderTreeTraversal_is_correct_order(void){
  goldenValues = preOrderGoldenValues;
  indexLimit = sizeof(preOrderGoldenValues)/sizeof(int);
  _PreOrderTreeTraversal(&node10,verifyinOrderrIntegers);
  if(CurIndex < indexLimit){
    char error[1028];
    sprintf(error, "The number of values is lesser than the number of golden values (%d) ",indexLimit);
    TEST_FAIL_MESSAGE(error);

  }
}


void test__inOrderTreeTraversal_with_printInteger(void){
  _inOrderTreeTraversal(&node10,printInteger);
}

void test__inOrderTreeTraversal_eith_printDecoratedInteger(void){
  _inOrderTreeTraversal(&node10,printDecoratedInteger);
}

void test__inOrderTreeTraversal_with_printString(void){
  _inOrderTreeTraversal((Node *)&nodeAdam,printString);
}


void test_Traversal_inOrder(void)
{
    inOrderTreeTraversal(&node10);
}
void test_Traversal_preOder(void)
{
    PreOrderTreeTraversal(&node10);
}
void test_Traversal_postOder(void)
{
    PostOrderTreeTraversal(&node10);
}
