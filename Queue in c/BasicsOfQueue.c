#include<stdio.h>
#include<stdlib.h>

struct Qq
{
    int start;
    int last;
    int size;
    int *queue;
};

void pushToQueue(struct Qq *q,int numberIs){
    if (q->last != q->size - 1){
        q->last += 1;
        q->queue[q->last] = numberIs;
    }else {
        printf("enter size\n");
    }
}

void popFromQueue(struct Qq *q){
    if (q->start != q->last){
        q->start += 1;
        q->queue[q->start] = INT8_MIN;
    }else{
        printf("is empty\n");
    }
}

void displayQueue(struct Qq q){
    if (q.start != q.last && q.size - 1 >= 0){
        printf("\nqueue is: ");
        for (int i = q.start + 1; i <= q.last; i++){
            printf("%d ",q.queue[i]);
        }
        printf("\n");
    }else{
        printf("empty\n");
    }
}

int main(){
    struct Qq queue;
    printf("enter the size of the queue\n");
    scanf("%d",&queue.size);
    queue.start = -1;
    queue.last = -1;
    queue.queue = (int *)malloc(queue.size * sizeof(int));


    printf("\n");
    pushToQueue(&queue, 2);
    pushToQueue(&queue, 4);
    pushToQueue(&queue, 5);
    pushToQueue(&queue, 6);
    pushToQueue(&queue, 1);

    displayQueue(queue);

    popFromQueue(&queue);
    popFromQueue(&queue);
    popFromQueue(&queue);

    displayQueue(queue);
    return 0;
}