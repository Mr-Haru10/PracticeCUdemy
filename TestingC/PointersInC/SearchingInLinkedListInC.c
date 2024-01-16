#include<stdio.h>
#include<stdlib.h>

struct LinkedListIs
{
    int dataIs;
    struct LinkedListIs *nextIs;
}*list01=NULL;


void createTheLinkedList( int arrayIs[],int size){
    if (size!=0){
        struct LinkedListIs *inter, *last;
        inter=last=NULL;

        list01->dataIs = arrayIs[0];
        list01->nextIs = NULL;
        last = list01;

        for (int i = 1; i < size; i++)
        {
            inter = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));
            inter->dataIs = arrayIs[i];
            inter->nextIs = NULL;
            last->nextIs = inter;
            last = inter;
        }
    
    }else{
        list01 = NULL;
    }
    

}

void displayTheLinkedList(struct LinkedListIs *list){
    int countIs = 0;
    if (list!=NULL){
        printf("\nLinked list is: ");
        while (list!=NULL)
        {
            printf("%d ",list->dataIs);
            countIs++;
            list=list->nextIs;
        }
    }
    printf("\nlinked list count is: %d",countIs);
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

void insertElementsAt(int position,int x,struct LinkedListIs **list){

    struct LinkedListIs *temp;
    temp = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));
    temp->dataIs = x;
    if (position == 0){
        temp->nextIs = list01;
        list01 = temp;
    }else{
        for (int i = 0; i < position-1; i++)
        {
            (*list) = (*list)->nextIs;
        }
        temp->nextIs = (*list)->nextIs;
        (*list)->nextIs = temp;
    }
}

int main(){
    int arr[]={1,2,3,4,5};
    list01 = (struct LinkedListIs *)malloc(sizeof(struct LinkedListIs));
    createTheLinkedList(arr,sizeof(arr)/sizeof(int));
    displayTheLinkedList(list01);

    
    printf("\ninserting element");
    insertElementsAt(2,8989,&list01);
    
    
    

    free(list01);

    return 0;
}
