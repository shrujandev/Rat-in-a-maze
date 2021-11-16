#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"PES1UG20CS415_H.h"



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

