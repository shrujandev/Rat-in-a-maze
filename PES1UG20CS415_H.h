#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct node{
    int i;
    int j;
    int data;
    struct node *right;
    struct node *down;

}Node;

typedef struct head{
    struct node *head;
}Head;

typedef struct stackele{
    struct node *ele;
    struct stackele *next;
}StackEle;

typedef struct stack{
    struct stackele *head;
}Stack;


void init(Head *ptr);
Node* popElement(Stack *stack);
void inputMatrix(Head *ptr,int c,int i, int j);
void findPath(Head *ptr,int endI,int endJ,FILE *output);
void pushElement(Stack *stack,Node *element);