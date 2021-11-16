#include<stdio.h>
#include<stdlib.h>]
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

void init(Head *ptr){
   ptr->head = NULL;
}

int main(){
    int a;
    int b[500];
    
    Head *ptr=(Head*)malloc(sizeof(Head));
    printf("Alloted ptr");
    init(ptr);
    printf("after bAlloted ptr");

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
   //printf("Before for loop");
    for(int i = startI; i <= endI ;i++){
        //printf("inside f1");
        for(int j =startJ ; j <= endJ ; j++ ){
          
            inputMatrix(ptr,b[a],i,j);
            
            

            a++;
        }
    }



Node *p = ptr->head;
printf("%d",p->data);
p=p->right;
printf("%d",p->data);
p=p->down;
printf("%d",p->data);
p=p->right;
printf("%d",p->data);
p=p->down;
printf("%d",p->data);

    
    fclose(input);
    fclose(output);
    

    return 0;

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
                aboveptr = aboveptr->right;
            }
            prevptr->right = temp;
            aboveptr->down = temp;
            }

        }

        
    }
    printf("done");
}
