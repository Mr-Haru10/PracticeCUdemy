#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int column;
    int data;
    struct Matrix *next;
};
void createMatric(){
    int rows = 0;
    int columns = 0;
    int nonZero = 0;
    printf("Eter the size of the matric in termas of Rows X Columns\n");
    scanf("%d%d",&rows,&columns);
    printf("Enter number of non zero numbers\n");
    scanf("%d",&nonZero);
    struct Matrix **ptr = (struct Matrix **)malloc(rows*sizeof(struct Matrix));

    int row[nonZero],colum[nonZero],num[nonZero];
    printf("Enter non zero numbers in terms of Rows Colum Number\n");
    for (int i = 0; i < nonZero; i++){
        scanf("%d%d%d",&row[i],&colum[i],&num[i]);
    }

    int lastRow = 999;
    struct Matrix * new,*last,*temp;
    new=last=temp=NULL;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < nonZero; j++)
        {
            if (i == row[j]){
                if (lastRow == 999){
                    new = (struct Matrix *)malloc(sizeof(struct Matrix));
                    new->column = colum[j];
                    new->data = num[j];
                    new->next = NULL;
                    last = new;
                }else{
                    temp = (struct Matrix *)malloc(sizeof(struct Matrix));
                    temp->column = colum[j];
                    temp->data = num[j];
                    temp->next = NULL;
                    last->next = temp;
                    last = temp;
                }
                lastRow = i;
                ptr[i] = new;
            }
        }
        lastRow = 999;
        last = NULL;
    }
    
    printf("\n");
    printf("Matrix Is\n");
    
    for (int i = 0; i < rows; i++)
    {
        struct Matrix *p = ptr[i];
        for (int j = 0; j < columns; j++)
        {
            if (p != NULL && p->column == j)
            {
                printf("%d ", p->data);
                p = p->next;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    

    
   
    
}
int main(){

    createMatric();
    return 0;
}