#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
    int dataIs;
    struct LinkedList *poi;
};

void createLinkedList(struct LinkedList *first, int arrayIs[],int size){

    struct LinkedList *linker,*last;
    linker=last=NULL;

    first->dataIs=arrayIs[0];
    first->poi = NULL;
    last=first;

    for (int i = 1; i < size; i++){
        linker = (struct LinkedList *)malloc(sizeof(struct LinkedList));
        linker->dataIs = arrayIs[i];
        linker->poi = NULL;
        last->poi = linker;
        last = linker;
    }
}

void printlinkedList(struct LinkedList *pointer){
    printf("Linked list data is: ");
    while (pointer!=NULL)
    {
        printf("%d ",pointer->dataIs);
        pointer=pointer->poi;
    }
}

void printUsingRecursion(struct LinkedList *pointer){
    if (pointer!=NULL)
    {
        printf("%d ",pointer->dataIs);
        printUsingRecursion(pointer->poi);
    }
    
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};

    struct LinkedList *pp;

    pp = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    createLinkedList(pp,arr,sizeof(arr)/sizeof(arr[0]));
    // printlinkedList(pp);
    printUsingRecursion(pp);
    return 0;
}