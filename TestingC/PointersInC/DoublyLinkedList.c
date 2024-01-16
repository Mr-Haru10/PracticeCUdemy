#include<stdio.h>
#include<stdlib.h>

struct DList{
    struct DList *pre;
    int data;
    struct DList *next;
};

int findMidpointInLinkedlist(struct DList **header){
    struct DList *ptr, *follow;
    follow=ptr= (*header);
    
    do
    {
        ptr = ptr->next;
        follow = follow->next;
        follow = follow != NULL ? follow->next : NULL;
    } while (follow!=(*header));
    

    return ptr->data;

}

void printCircularDList(struct DList **header){

    struct DList *ptr = (*header);
    printf("\n");
    printf("\n");
    printf("Printing a circular DList: ");
    do
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr!=(*header));
    printf("\n");
}

void createACircularDList(int arrayIs[],int size,struct DList **header){
    struct DList *ptr, *new, *last;
    new=last=NULL;
    ptr = (*header);

    ptr->data = arrayIs[0];
    ptr->next = ptr;
    ptr->pre = ptr;
    last = ptr;

    for (int i = 1; i < size; i++){
        
        new = (struct DList *)malloc(sizeof(struct DList));
        new->data = arrayIs[i];
        new->next = last->next;
        last->next = new;
        new->pre = last;

        last = new;
    }
    

}

void reversingList(struct DList **head){
    struct DList *temp,*ptr;
    ptr = (*head);
    temp = NULL;

    while (ptr)
    {
        temp = ptr->next;
        ptr->next = ptr->pre;
        ptr->pre = temp;

        ptr = ptr->pre;
        if (ptr != NULL && ptr->next == NULL){
            (*head) = ptr;
        }
    }
    

}

void deleteIndex(int num,struct DList **head){
    struct DList *ptr = (*head);
    while (ptr!=NULL && ptr->data!=num)
    {
        ptr = ptr->next;
    }

    if (ptr->next){
        ptr->next->pre = ptr->pre;
    }
    ptr->pre->next = ptr->next;
    
    
}

void insert(int num,int index,struct DList **head){
    struct DList *ptr, *new;
    ptr = (*head);
    new = (struct DList *)malloc(sizeof(struct DList));
    new->data = num;
    new->pre=new->next=NULL;

    if (index == 1){
        new->next = ptr;
        new->pre = NULL;
        ptr->pre = new;
        (*head) = new;
    }else{
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }

        new->next = ptr->next;
        new->pre = ptr;
        if (ptr->next) {
            ptr->next->pre = new;
        }
        ptr->next = new;
        
        
    }


}

void createDList(int arr[],int size,struct DList **head){
    struct DList *ptr,*last,*new;
    last=new=NULL;
    ptr = (*head);

    ptr->pre = NULL;
    ptr->data = arr[0];
    ptr->next = NULL;
    last = ptr;

    for (int i = 1; i < size; i++){
        
        new = (struct DList *)malloc(sizeof(struct DList));
        new->data = arr[i];
        new->pre = last;
        new->next = last->next;
        last->next = new;
        last = new;

    }
    

}

void DisplayDList(struct DList *ptr){
    struct DList *la;
    la = NULL;
    printf("Forword list is: ");
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        la = ptr;
        ptr = ptr->next;
        
    }
}


int main(){
    int number[] = {1,2,3,4,5,6,7,8,9,0};
    int size = sizeof(number)/sizeof(int);

    printf("Creating DList\n");
    struct DList *ptr = (struct DList *)malloc(sizeof(struct DList));
    createDList(number,size,&ptr);

    DisplayDList(ptr);

    printf("\n");
    printf("\n");
    printf("Inserting\n");
    insert(44,10,&ptr);
    DisplayDList(ptr);

    printf("\n");
    printf("\n");
    printf("Deleting element");
    deleteIndex(44,&ptr);
    DisplayDList(ptr);

    printf("\n");
    printf("\n");
    printf("reversing the list");
    reversingList(&ptr);
    DisplayDList(ptr);

    int number01[] = {1,2,3,8,9,0,81,44,547,32,45,80};
    int size02 = sizeof(number01)/sizeof(int);

    struct DList *circlePtr = (struct DList *)malloc(sizeof(struct DList));

    createACircularDList(number01,size02,&circlePtr);
    printCircularDList(&circlePtr);

    printf("Middle number is: %d",findMidpointInLinkedlist(&circlePtr));
    

    return 0;
}