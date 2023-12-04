#include<stdio.h>
#include<stdlib.h>

struct LinkedListIs
{
    int dataIs;
    struct LinkedListIs *nextIs;
}*list01;


void createTheLinkedList(struct LinkedListIs *poi, int arrayIs[],int size){
    struct LinkedListIs *inter, *last;
    inter=last=NULL;

    poi->dataIs = arrayIs[0];
    poi->nextIs = NULL;
    last = poi;

    for (int i = 1; i < size; i++)
    {
        inter = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));
        inter->dataIs = arrayIs[i];
        inter->nextIs = NULL;
        last->nextIs = inter;
        last = inter;
    }
    

}

void displayTheLinkedList(struct LinkedListIs *list){
    printf("\nLinked list is: ");
    while (list!=NULL)
    {
        printf("%d ",list->dataIs);
        list=list->nextIs;
    }
}

int findTheNum(struct LinkedListIs *list,int key){
    struct LinkedListIs *backUp;
    backUp = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));

    while (list!=NULL)
    {
        if(list->dataIs == key){
            backUp->nextIs = list->nextIs;
            list->nextIs = list01;
            list01 = list;
            return list->dataIs;
        }else{
            backUp = list;
            list=list->nextIs;
        }
    }
    return -987;
}

void insertElementsAt(int position,int x,struct LinkedListIs *list){

    struct LinkedListIs *temp;
    temp = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));
    temp->dataIs = x;
    if (position == 0){
        temp->nextIs = list01;
        list01 = temp;
    }else{
        for (int i = 0; i < position-1; i++)
        {
            list = list->nextIs;
        }
        temp->nextIs = list->nextIs;
        list->nextIs = temp;
    }
}

int main(){
    int arr[]={6,3,5,8,9,14,66,32,0,4};
    list01 = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));
    createTheLinkedList(list01,arr,sizeof(arr)/sizeof(arr[0]));
    displayTheLinkedList(list01);
    int num = findTheNum(list01,66);
    printf("\nFOund num is: %d",num);
    displayTheLinkedList(list01);

    printf("\ninserting the element");
    insertElementsAt(10,100,list01);
    displayTheLinkedList(list01);
    return 0;
}