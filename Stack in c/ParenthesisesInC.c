#include<stdio.h>
#include<stdlib.h>

struct Param
{
    int size;
    int top;
    char *charIs;
};

void push (struct Param *ptr, char addTo){
    if (ptr->top == ptr->size - 1){
        printf("over flow\n");
    }else{
        ptr->top += 1;
        ptr->charIs[ptr->top] = addTo;
    }
}

int pop (struct Param *ptr){
    if (ptr->top >= 0){
        ptr->top -= 1;
        return 0;
    }else{
        return 1;
    }
}

int dispaList(struct Param ptr){
    int counter = 0;
    if (ptr.top >= 0){
        for (int i = ptr.top; i >= 0; i--){
            counter += 1;
        }
        return counter;
    }
    return 0;
}

int main(){
    char stringIs[] = ")))(((())))) ";
    int stringLength = 0;    

    int num01 = 0;
    int num02 = 0;

    for (int i = 0; stringIs[i] != '\0'; i++){
        stringLength += 1;
    }
    struct Param p;
    p.size = stringLength;
    p.top = -1;
    p.charIs = (char *)malloc(sizeof(char));


    for (int i = 0; stringIs[i] != '\0'; i++){
        if (stringIs[i] == '('){
            push(&p, stringIs[i]);
        }else if (stringIs[i] == ')'){
            num01 = num01 + pop(&p);
        }
    }

    num02  = num02 + dispaList(p);

    if (num01 == 0 && num02 == 0){
        printf("Balanced");
    }else if (num01 != 0){
        printf(" this ')' has repeaterd for %d times", num01);
    }else if (num02 != 0){
        printf(" this '(' has repeaterd for %d times", num02);
    }else{
        printf("both '(' and ')' hav repeater equal number of tymes");
    }

    
    return 0;
}
