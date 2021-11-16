#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int i;
    int j;
    int data;
    struct node *right;
    struct node *down;

}Node;

typedef struct head{
    Node *head;
}Head;


int main(){
    int a;
    int b[500];
    int c[100][100];
    Head *ptr;
    ptr->head==NULL;
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
            c[i][j] = b[a];
            a++;
        }
    }

    for(int i = startI; i <= endI ;i++){
        for(int j =startJ ; j <= endJ ; j++ ){
            Node *temp;
            
            if(ptr->head == NULL){
                temp = (Node*)malloc(sizeof(Node));
                
                temp->data = b[a];
                temp->right = NULL;
                temp->down = NULL;
                ptr->head = temp;


            }
            else{
                temp = ptr->head;
                while(temp->right != NULL){
                    temp = temp->right;

                }
                temp->right = (Node*)malloc(sizeof(Node));
                temp->right->data = b[a];
                temp->right->right = NULL;
                temp->down->down = NULL;

        }
        printf("\n");
    }

    
    fclose(input);
    fclose(output);
    

    return 0;

}
