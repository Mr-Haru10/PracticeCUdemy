#include<stdio.h>
int main(){
    int arraySize;
    int arrayis[arraySize];

    int counter = 0;

	printf("enter the size of the array\n");
	scanf("%d",&arraySize);
	printf("enter %d array element\n", arraySize);
    for(int i = 0; i < arraySize; i++){
        scanf("%d",&arrayis[i]);
    }
    
    for(int i = 0; i < arraySize; i++){
        if (arrayis[i] > 9){
            counter += 1;
        }
    }
    printf("sample output is: %d", counter);
    return 0;
}