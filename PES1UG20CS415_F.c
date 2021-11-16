#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PES1UG20CS415_H.h"

void init(Head *ptr){
   ptr->head = NULL;
}

void inputMatrix(Head *ptr,int c,int i, int j){
    //printf("before allocation");
    printf("\n%d,%d ",i,j);
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
            temp->i = i;
            temp->j = j;
            temp->data = c;
            temp->right =NULL;
            temp->down =NULL;
    //printf("Allocated Successfully");
    Node *aboveptr = NULL;
    Node *prevptr = NULL;
    Node *head = NULL;

    //printf("Before if conditions");
    if(ptr->head == NULL){
        printf("Null condition");
        ptr->head = temp;
        
    }
    else{
        //printf("Inside elsse");
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
    printf("done");
}


void findPath(Head *ptr,int endI,int endJ , FILE *output){
            Stack *stack;
            stack = (Stack*)malloc(sizeof(Stack));
            stack->head = NULL;
            Node *move;
            move = ptr->head;
            pushElement(stack,move);
            while((move->i != endI && move->j != endJ) ){
                if(move->right->data == 0 ){
                    
                    move = move->right;
                    pushElement(stack,move);
                    printf("\ntest : %d  %d",move->i,move->j);
                    
            }
                else if(move->down->data ==0){
                    
                    move = move->down;
                    pushElement(stack,move);
                    printf("\ntest : %d  %d",move->i,move->j);

                }
                else if(move->down->data !=0 && move->right->data !=0){
                    move->data = 1;
                    move = popElement(stack);
                }
            }
            pushElement(stack,move);

            StackEle *p;
            p = stack->head;
            printf("\nThe result");
            while(p->next != NULL){
                printf("\n%d %d",p->ele->i,p->ele->j);
                fprintf(output,"\n%d %d",p->ele->i,p->ele->j);
                p = p->next;

            }

}

void pushElement(Stack *stack,Node *element){
        StackEle *p = stack->head;
        StackEle *temp;
        
        temp = (StackEle*)malloc(sizeof(StackEle));
        temp->ele = element;
        temp->next = NULL;
        if(p == NULL){
            stack->head =temp;
        }
        else{
        while(p->next !=NULL){
            p = p->next;
        }
        p->next = temp;
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