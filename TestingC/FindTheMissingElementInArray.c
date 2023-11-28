#include<stdio.h>
// Finding missing numbers in sorted array
// void findMissingElement(int arraySize, int arr[]){
//     int missingNums[10];
//     int counter = 0;

//     for(int i=0;i<arraySize-1;i++){
//         int d = arr[i+1]-arr[i];
//         if (d != 1){
//             int diff = arr[i+1]-arr[i];
//             for(int j=1;j<diff;j++){
//                 missingNums[counter] = arr[i] + j;
//                 counter++;
//             }
//         }
//     }
//     printf("missing nums are: ");
//     for(int i=0;i<10;i++){
//         printf("%d ",missingNums[i]);
//     }
    
// }

// int main(){
//     int arrIs[]={1,9};
//     printf("Original array is: ");
//     for(int i=0;i<sizeof(arrIs)/sizeof(arrIs[0]);i++){
//         printf("%d ",arrIs[i]);
//     }
//     printf("\n");
//     findMissingElement(sizeof(arrIs)/sizeof(arrIs[0]),arrIs);
//     return 0;
// }

// Finding missing numbers in an un-sorted array

#include<stdio.h>




void findTheMissingElements(int size,int arr[]){
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("mim is: %d and max is: %d\n",min,max);
    int sampleArr[max];
    for(int i=0;i<=max;i++){
        if(i<min){
            sampleArr[i] = 9;
        }else{
            sampleArr[i] = 0;
        }
    }
    printf("sample array is: ");
    for(int i=0;i<=max;i++){
        printf("%d ",sampleArr[i]);
    }
    printf("\n");
    for(int i=0;i<size;i++){
        int val = arr[i];
        sampleArr[val] = 1;
    }
    printf("sample array is: ");
    for(int i=0;i<=max;i++){
        printf("%d ",sampleArr[i]);
    }
    printf("\n");
    printf("missing nums are: ");
    for(int i=0;i<=max;i++){
        if (sampleArr[i] == 0){
            printf("%d ",i);
        }
    }
}


int main(){
    int arrIs[]={33,4,56,3,6,22,8,0,34,23,65,69};
    printf("originar array: ");
    for(int i=0;i<sizeof(arrIs)/sizeof(arrIs[0]);i++){
        printf("%d ",arrIs[i]);
    }
    printf("\n");
    findTheMissingElements(sizeof(arrIs)/sizeof(arrIs[0]),arrIs);
    return 0;
}