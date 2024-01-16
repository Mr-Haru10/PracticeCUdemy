#include<stdio.h>
#include<stdlib.h>

struct LinkList
{
    int data;
    struct LinkList *next;
};

int checkForLoop(struct LinkList *ptr){
    struct LinkList *ptr2 = ptr;

    do{
        ptr = ptr->next;
        ptr2= ptr2->next;
        ptr2 = ptr2 != NULL ? ptr2->next : NULL;
    } while (ptr && ptr2 && ptr2!=ptr);
    
    return ptr == ptr2 ? 1 : 0;
}

void createCircleLinkedList(int arrayIs[],int size,struct LinkList **headPtr){
    struct LinkList *ptr,*temp,*last;
    temp=last=NULL;
    ptr = (*headPtr);

    ptr->data = arrayIs[0];
    ptr->next = ptr;
    last = ptr;

    for (int i = 1; i < size; i++)
    {
        temp = (struct LinkList *)malloc(sizeof(struct LinkList));
        temp->data = arrayIs[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void displayLinkList(struct LinkList **head){
    struct LinkList *ptr = (*head);
    printf("Link list:");
    do
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr!=(*head));
    
    printf("\n");
}

int main(){
    int numb[] = {1,2,3,4,5};
    int size = sizeof(numb)/sizeof(int);
    struct LinkList *ptr = (struct LinkList *)malloc(sizeof(struct LinkList));

    printf("creating a circular linkedlist\n");
    createCircleLinkedList(numb,size,&ptr);
    displayLinkList(&ptr);

    printf("Does linkedlist has loop : %s",checkForLoop(ptr) ? "YES broooooo" : "Nope hillout bro");

    return 0;
}