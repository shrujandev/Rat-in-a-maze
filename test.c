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

int main(){
    int a;
    int b[500];
    
    Head *ptr=(Head*)malloc(sizeof(Head));
    init(ptr);
    

    int startI,startJ,endI,endJ;
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    int i=0;
    if(input == NULL){
        printf("Ohh error\n");
        return 0;
    }
    int j=0;
   
    while ( fscanf(input, "%d", &a ) == 1 ){
        switch(j){
            case 0 : startI = a;
                break;
            case 1 : startJ = a;
                break;
            case 2: endI =a;
                break;
            case 3: endJ = a;
                break;
            default :
                    b[j-4] = a;
        }
        j++;

    };
   a = 0;
    for(int i = startI; i <= endI ;i++){
        for(int j =startJ ; j <= endJ ; j++ ){
            inputMatrix(ptr,b[a],i,j);
            a++;
        }
    }



    findPath(ptr,endI,endJ,output);

    
    fclose(input);
    fclose(output);
    

    return 0;

}


void init(Head *ptr){
   ptr->head = NULL;
}

void inputMatrix(Head *ptr,int c,int i, int j){
    
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
            temp->i = i;
            temp->j = j;
            temp->data = c;
            temp->right =NULL;
            temp->down =NULL;
    Node *aboveptr = NULL;
    Node *prevptr = NULL;
    Node *head = NULL;

    if(ptr->head == NULL){
        
        ptr->head = temp;
        
    }
    else{
        head = ptr->head;
        while(head->down != NULL){
            aboveptr = head;
            head = head->down;
        }
        
        if(i==0){
            prevptr = head;
            while(prevptr->right != NULL){
                prevptr = prevptr->right;
            }
            prevptr->right = temp;


        }
        else{
            
            
            if(j==0){
                head->down = temp;
            }
            else{
            prevptr = head;
            while(prevptr->right != NULL){
                prevptr = prevptr->right;
                
            }
            prevptr->right = temp;
            prevptr = head;
            while(prevptr->right != NULL){
                prevptr = prevptr->right;
                aboveptr = aboveptr->right;
                
            }
            aboveptr->down = temp;
            }

        }

        
    }
    
}


void findPath(Head * ptr, int endI, int endJ, FILE * output) {
  Stack * stack;
  int condition = 0;
  stack = (Stack * ) malloc(sizeof(Stack));
  stack -> head = NULL;
  Node * move;
  move = ptr -> head;
  pushElement(stack, move);
  while (condition == 0) {
    if (move -> i < endI && move -> j < endJ) {
      if (move -> right -> data == 0) {
        move = move -> right;
        pushElement(stack, move);

      } else if (move -> down -> data == 0) {

        move = move -> down;
        pushElement(stack, move);

      } else if (move -> down -> data != 0 && move -> right -> data != 0) {
        move -> data = 1;
        move = popElement(stack);
      }

    } else if (move -> i == endI && move -> j != endJ) {
      if (move -> right -> data == 0) {
        move = move -> right;
        pushElement(stack, move);

      } else if (move -> down -> data != 0 && move -> right -> data != 0) {
        move -> data = 1;
        move = popElement(stack);
      }

    } else if (move -> i != endI && move -> j == endJ) {
      if (move -> down -> data == 0) {

        move = move -> down;
        pushElement(stack, move);

      } else if (move -> down -> data != 0 && move -> right -> data != 0) {
        move -> data = 1;
        move = popElement(stack);
      }

    } else {
      condition = 1;
    }
  }

  pushElement(stack, move);

  StackEle * p;
  p = stack -> head;
  printf("\nThe result");
  if (p == NULL) {
    printf("\nNo possible Path Exist");
    fprintf(output, "%d", -1);

  }
  while (p -> next != NULL) {
    printf("\n%d %d", p -> ele -> i, p -> ele -> j);
    fprintf(output, "\n%d %d", p -> ele -> i, p -> ele -> j);
    p = p -> next;

  }

}

void pushElement(Stack * stack, Node * element) {
  StackEle * p = stack -> head;
  StackEle * temp;

  temp = (StackEle * ) malloc(sizeof(StackEle));
  temp -> ele = element;
  temp -> next = NULL;
  if (p == NULL) {
    stack -> head = temp;
  } else {
    while (p -> next != NULL) {
      p = p -> next;
    }
    p -> next = temp;
  }
}

Node* popElement(Stack *stack){
    StackEle *p = stack->head;
    StackEle *prev;
    while(p->next !=NULL){
            prev = p;
            p = p->next;
    }
    p->ele->data = 1;
    prev->next = NULL;
    
    return prev->ele;

}