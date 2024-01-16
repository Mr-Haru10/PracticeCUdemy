#include<stdio.h>
#include<stdlib.h>
int main(){
    // // Just practicing pointer
    // int a = 10;
    // int *p;
    // // Hete it is nessesory to use '&' to stire the memory address od a single int value (*****)
    // p = &a;
 
    // printf("address of a by a is %d\n", a);
    // printf("address of a by ponter is %d",*p);
    // End---------
    // To create memory in heap 

    // int *p;
    // p = (int *)malloc(5*sizeof(int));
    // p[0] = 11;
    // p[1] = 12;
    // p[2] = 13;
    // p[3] = 14;
    // p[4] = 15;

    // for(int i = 0; i < 5; i++){
    //     printf("%d ,",p[i]);
    // }
    // int i = 0;
    // while (i< 5)
    // {
    //     printf("%d ,",p[i]);
    //     i++;
    // }
    // do{
    //     printf("%d ,",p[i]);
    //     i++; 
    // }while (i < 5);
    
    // free(p);
    // End---------

    // Assiging an array addres to pointer

    // int array[5] = {1,2,3,4,5};
    // int *p;
    // // here while assiging a array to pointer just assiging array is enough no need to use '&' in case of assigning constant (if not understood please compare with above comment *****)
    // p = array;

    // for(int i = 0; i < sizeof(array)/sizeof(int); i++){
    //     printf("%d",p[i]);
    //     if (i != sizeof(array)/sizeof(int) - 1){
    //         printf(",");
    //     }
    // }
    

    return 0;
}