#include<stdio.h>
#include<stdlib.h>

struct DEQueue
{
    int size;
    int first;
    int last;
    int *ptr;
};

void addUsingFirst(struct DEQueue *DEQ,int num){
    if (DEQ->first != DEQ->size - 1){
        DEQ->first += 1;
        DEQ->ptr[DEQ->first] = num;
    }else{
        printf("queue is full\n");
    }
}

void removeUsingFirst(struct DEQueue *DEQ){
    if (DEQ->first != -1){
        DEQ->ptr[DEQ->first] = INT8_MIN;
        DEQ->first -= 1;
    }else{
        printf("queue is empty");
    }
}


void addingUsingLast(struct DEQueue *DEQ,int num){
    if (DEQ->last != DEQ->size - 1){
        DEQ->last += 1;
        DEQ->ptr[DEQ->last] = num;
    }else{
        printf("queue is full\n");
    }
}

void removingUsingLast(struct DEQueue *DEQ){
    if (DEQ->last != -1){
        DEQ->ptr[DEQ->last] = INT8_MIN;
        DEQ->last -= 1;
    }else{
        printf("queue is empty");
    }
}


int main(){

    struct DEQueue DEQ;
    DEQ.size = 5;
    DEQ.first = -1;
    DEQ.last = -1;

    DEQ.ptr = (int *)malloc(DEQ.size * sizeof(int));



    return 0;
}