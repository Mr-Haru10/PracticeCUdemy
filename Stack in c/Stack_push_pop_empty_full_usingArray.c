#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *st;
};

void push(struct Stack *str,int valueIs){   
    if (str->top == str->size - 1 ){
        printf("Stak over flow\n");
    }else{
        str->top+=1;
        str->st[str->top] = valueIs;
    }
}

void peek(struct Stack stk, int position){
    if (position > stk.size || position < 0){
        printf("position is out of reach\n");
    }else{
        printf("value at position %d = %d\n",position,stk.st[stk.top-position+1]);
    }
    
}

void pop (struct Stack *stk){
    if (stk->top >= 0 ){
        printf("deleting value = %d\n",stk->st[stk->top]);
        stk->top -= 1;
        printf("new top = %d\n",stk->st[stk->top]);
    }else{
        printf("stack is completely empty\n");
    }
}

void displayStack(struct Stack stk){

    if (stk.top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("stack is: ");
    for (int i = stk.top; i >= 0; i--){
        printf("%d ",stk.st[i]);
    }
    printf("\n");
}

int main(){
    struct Stack stk;
    printf("Please enter size of the stack\n");
    scanf("%d",&stk.size);
    stk.top = -1;


    stk.st = (int *) malloc (stk.size * sizeof(int));

    push(&stk,1);
    push(&stk,2);
    push(&stk,3);
    push(&stk,4);
    push(&stk,5);
    push(&stk,6);
    push(&stk,7);

    displayStack(stk);
    pop(&stk);
    pop(&stk);
    pop(&stk);

    displayStack(stk);

    free(stk.st);

    return 0;
}
