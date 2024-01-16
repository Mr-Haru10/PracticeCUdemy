#include<stdio.h>
#include<stdlib.h>

struct CircularQueue
{
    int size;
    int first;
    int last;
    int *queue;
};

void addToCircularQueue(struct CircularQueue *CQ, int number){
    if ((CQ->last+1)%CQ->size != CQ->first){
        CQ->queue[CQ->last] = number;
        CQ->last = (CQ->last+1)%CQ->size;
    }else{
        printf("full\n");
    }
}

void removeFromCircularQueue(struct CircularQueue *CQ){
    if (CQ->first != CQ->last){
        CQ->queue[CQ->first] = INT8_MIN;
        CQ->first = (CQ->first+1)%CQ->size; 
    }else{
        printf("empth\n");
    }
}

void display(struct CircularQueue CQ){
    printf("queue is: ");
    int i = (CQ.first+1);
    do
    {
        printf("%d ",CQ.queue[i]);
        i = (i + 1) % CQ.size;
    } while (i != (CQ.last + 1)% CQ.size);
    printf("\n");
}

int main(){
    struct CircularQueue CQ;
    CQ.size = 5;
    CQ.first = 0;
    CQ.last = 0;
    CQ.queue = (int *)malloc(CQ.size * sizeof(int));


// Test cases
    addToCircularQueue(&CQ, 1);
    addToCircularQueue(&CQ, 2);
    addToCircularQueue(&CQ, 3);
    display(CQ);

    removeFromCircularQueue(&CQ);
    display(CQ);

    addToCircularQueue(&CQ, 4);
    addToCircularQueue(&CQ, 5);
    addToCircularQueue(&CQ, 6); // This will print "full"
    display(CQ);

    removeFromCircularQueue(&CQ);
    display(CQ);

    free(CQ.queue);


    return 0;
}