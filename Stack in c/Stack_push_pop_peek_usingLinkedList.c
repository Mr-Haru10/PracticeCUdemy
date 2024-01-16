#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};


void push(struct Stack **ptr, int number){
    struct Stack *new;
    new = NULL;
    new = (struct Stack *)malloc(sizeof(struct Stack));
    
    if (new == NULL){
        printf("stack is full\n");
    }else{
        
        new->data = number;
        new->next = *ptr;
        *ptr = new;
    }
    
}

void pop(struct Stack **ptr){
    struct Stack *t;
    if ((*ptr)->next != NULL){
        t = (*ptr);
        (*ptr) = (*ptr)->next;
        free(t);
    }
}


void displayList(struct Stack *top){
    printf("\n");
    printf("stack data is: ");
    while (top != NULL)
    {
        printf("%d ",top->data);
        top = top->next;
    }   
}

int main(){
    
    struct Stack *top;
    top = NULL;
    push(&top, 8);
    push(&top, 3);
    push(&top, 7);
    push(&top, 5);

    displayList(top);

    pop(&top);

    displayList(top);
    
    return 0;
}
