#include<stdio.h>
#include<stdlib.h>

int main(){

    // 3 integer pointer in stack memory and rest of the array and array elements are in heap memory
    // int *p[3];
    // p[0] = (int *)malloc(4 * sizeof(int));
    // p[1] = (int *)malloc(4 * sizeof(int));
    // p[2] = (int *)malloc(4 * sizeof(int));

    // p[0][0] = 5; p[0][1] = 4; p[0][2] = 3; p[0][3] = 2;

    // p[1][0] = 50; p[1][1] = 40; p[1][2] = 30; p[1][3] = 20;

    // p[2][0] = 500; p[2][1] = 400; p[2][2] = 300; p[2][3] = 200;


    // for(int i=0; i<3;i++){
    //     for(int j=0; j<4;j++){
    //         printf("%d ",p[i][j]);
    //     }
    //     printf("\n");
    // }

    // free(p);
    // A double integer pointer is in the stack memory rest of the 2D array creation is in heap memory

    // int **p;

    // p = (int **)malloc(3*sizeof(int *));

    // p[0] = (int *)malloc(2*sizeof(int));
    // p[1] = (int *)malloc(2*sizeof(int));
    // p[2] = (int *)malloc(2*sizeof(int));

    // p[0][0] = 5; p[0][1] = 4;
    // p[1][0] = 50; p[1][1] = 40; 
    // p[2][0] = 500; p[2][1] = 400; 


    // for(int i=0; i<3;i++){
    //     for(int j=0; j<2;j++){
    //         printf("%d ",p[i][j]);
    //     }
    //     printf("\n");
    // }
    // free(p)

    return 0;
}