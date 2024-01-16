void push(struct Stack **ptr, int number){
    struct Stack *p = *ptr;

    struct Stack *new;
    new = (struct Stack *)malloc(sizeof(struct Stack));
    
    if (new == NULL){
        printf("stack is full\n");
    }else{
        
        new->data = number;
        new->next = p;
        p = new;
    }
    
}