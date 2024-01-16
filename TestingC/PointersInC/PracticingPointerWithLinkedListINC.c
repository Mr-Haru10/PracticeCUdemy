// This is to create a linkedlist, inserting a element at desired index in a NON-SORTED LINKEDLIST, inserting new element in a SORTED LINKEDLIST

#include<stdio.h>
#include<stdlib.h>
struct List{
    int data;
    struct List *next;
};



int checkLoop(struct List **ptr){
    struct List *i,*j;
    i=j=(*ptr);

    do{
        i = i->next;
        j = j->next;
        j = j ? j->next : j;
    } while (i && j && i!=j);
    
    return i==j ? 1 : 0;
}

void addedTwoLinkedlist(struct List **p1,struct List **p2){
    struct List *ptr1,*ptr2=NULL;
    ptr1 = (*p1);
    ptr2 = (*p2);
    while (ptr1->next!=NULL)
    {
        ptr1 = ptr1->next;
    }
    ptr1->next = ptr2;
}


void reversTheLinkedlist(struct List **ptr){
    struct List *p,*q,*r;
    p = (*ptr);
    q=r=NULL;

    while (p!=NULL)
    {
        r=q;
        q=p;
        p = p->next;
        q->next=r;
    }
    (*ptr)=q;
}

void deletingDuplicateElementsInASortedLinkedlist(struct List **ptr){
    struct List *p,*i;
    p = (*ptr);
    i=p->next;
    while (i!=NULL)
    {
        if (p->data!=i->data){
            p = i;
            i = i->next;
        }else{
            p->next = i->next;
            free(i);
            i = p->next;
        }
    }
}

void deleteTheElement(int x,struct List **ptr){
    struct List *current,*backUp;
    backUp = NULL;
    current = (*ptr);
    if (x==current->data){
        backUp = current->next;
        *ptr = backUp;
        free(current);
    }else {
        while (current!=NULL)
        {
            if (current->data == x){
                backUp->next = current->next;
                current = backUp;
                free(current);
                break;
            }else{
                backUp = current;
                current = current->next;
            }
        }
    }
}

void insertInASortedLinkedList(int x,struct List **ptr){
    struct List *backUp,*current,*newNode;
    backUp = newNode = NULL;
    newNode = (struct List *)malloc(sizeof(struct List));

    current = (*ptr);
    newNode->data = x;

    if (x<current->data){
        newNode->next = current;
        *ptr = newNode;
    }else{
        while (current!=NULL && current->data < x){
            backUp = current;
            current = current->next;
        }
        backUp->next = newNode;
        newNode->next = current;
    }
}


void insertAtYourWish(struct List **ptr, int insertAt, int element) {
    struct List *help, *temp;
    help = (struct List *)malloc(sizeof(struct List));
    help->data = element;
    
    if (insertAt == 1) {
        help->next = (*ptr);
        (*ptr) = help;
    } else {
        
        temp = (*ptr);
        for (int i = 1; i < insertAt - 1 ; i++) {
            temp = temp->next;
        }
        
        help->next = temp->next;
        temp->next = help;
        
    }
}


void insertAtlastOfTheList(struct List **lastPointer,int x){
    struct List *help;
    help = NULL;
    help = (struct List *)malloc(sizeof(struct List));
    help->data = x;
    help->next = NULL;
    (*lastPointer)->next = help;
    (*lastPointer) = help;
}

void createTheLinkedList(struct List **ptr,struct List **lastPointer,int numbers[],int numbersSize){
    if (numbersSize!=0){
        struct List *help,*last;
        help=last=(*lastPointer)=NULL;
        
        (*ptr)->data = numbers[0];
        (*ptr)->next = NULL;
        last = (*ptr);
        (*lastPointer) = last;
        for (int i = 1; i < numbersSize; i++)
        {
            help = (struct List *)malloc(sizeof(struct List));
            help->data = numbers[i];
            help->next = NULL;
            last->next = help;
            last = help;
            (*lastPointer) = last;
        }
    }else{
        (*ptr) = NULL;
    }
}

void printLinkedList(struct List *ptr){
    int count = 0;
    printf("Linkedlisr is: ");
    while (ptr!=NULL)
    {
        count++;
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    printf("LinkedList count: %d",count);
    printf("\n");
    printf("\n");
}

int main(){
    int numbers[]={97,38,99,43,01};
    int numbersSize = sizeof(numbers)/sizeof(int);
    struct List *ptr;
    struct List *lastPointer;
    ptr = (struct List *)malloc(sizeof(struct List));
    
    printf("\ncreating linkedlist \n");
    printLinkedList(ptr);
    createTheLinkedList(&ptr,&lastPointer,numbers,numbersSize);
    printLinkedList(ptr);
    
    printf("Inserting at the last \n");
    printLinkedList(ptr);
    insertAtlastOfTheList(&lastPointer,100);
    printLinkedList(ptr);
    
    printf("insert at your wish\n");
    printLinkedList(ptr);
    insertAtYourWish(&ptr,4,8989);
    printLinkedList(ptr);

    int sortedNumbers[]={2,5,9,18,43,99,192,846,999};
    struct List *stortedPtr;
    struct List *stortedLastPtr;
    stortedPtr = (struct List *)malloc(sizeof(struct List));
    
    printf("Creating sorted linkedlist\n");
    printLinkedList(stortedPtr);
    createTheLinkedList(&stortedPtr,&stortedLastPtr,sortedNumbers,sizeof(sortedNumbers)/sizeof(int));
    printLinkedList(stortedPtr);
    printf("After inserting in sorted list\n");
    printLinkedList(stortedPtr);
    insertInASortedLinkedList(0,&stortedPtr);
    printLinkedList(stortedPtr);
    printf("deleiting the element\n");
    printLinkedList(stortedPtr);
    deleteTheElement(192,&stortedPtr);
    printLinkedList(stortedPtr);
    printf("Delete duplicate elements in a sorted linkedlist is\n");
    int sortedDelete[] = {1,2,3,4,4,5,6,7,8,9,14,14,14};
    struct List *sortedDeletePointer;
    struct List *sortedDeleteLastPointer;
    sortedDeletePointer = (struct List *)malloc(sizeof(struct List));
    createTheLinkedList(&sortedDeletePointer,&sortedDeleteLastPointer,sortedDelete,sizeof(sortedDelete)/sizeof(int));
    printLinkedList(sortedDeletePointer);
    deletingDuplicateElementsInASortedLinkedlist(&sortedDeletePointer);
    printLinkedList(sortedDeletePointer);
    printf("Reversed linked list \n");
    reversTheLinkedlist(&sortedDeletePointer);
    printLinkedList(sortedDeletePointer);
    printf("adding two linked list");
    addedTwoLinkedlist(&stortedPtr,&sortedDeletePointer);
    printLinkedList(stortedPtr);
    
    
    return 0;
}