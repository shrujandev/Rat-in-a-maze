#include<stdio.h>
#include<stdlib.h>


int main(){
    int a[100];
    FILE *input = fopen("input.txt","r");
    FILE *output = fopen("output.txt","w");
    int i=0;
    if(input == NULL){
        printf("Ohh error\n");
        return 0;
    }


    while ( fscanf(input, "%d", &a[i] ) != EOF ){
        i++;
    };

    for(int i = a[0];i<a[3];i++){
        for(int j = a[0];j<a[3];j++){
            printf(" %d ",a[j+4]);

        
        } 
        printf("\n");
    } 

    return 0;

}
