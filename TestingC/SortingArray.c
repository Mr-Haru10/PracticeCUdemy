#include<stdio.h>

void sortTheArray(int arr[],int size){
    int i,j = 1,temp;
    while (j<= size)
    {
        for(i=0; i<size-1; i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        j+= 1;
    }
}

int main(){
    int arrIs[]={4,5,6,8,0,2,9,99,3,7};
    sortTheArray(arrIs,sizeof(arrIs)/sizeof(arrIs[0]));
    for(int i=0;i<sizeof(arrIs)/sizeof(arrIs[0]);i++){
        printf("%d ",arrIs[i]);
    }
    return 0;
}