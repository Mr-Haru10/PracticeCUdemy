#include<stdio.h>

int main(){
    int arr[3][3];

    int c = 100;
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            arr[i][j] = i+j+1;
        }
    }
    printf("before\n");
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            int temp = arr[i][j] + c;
            arr[i][j]=arr[j][i];
            arr[j][i] = temp + c;
        }
    }
    printf("\n");
    printf("After\n");
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}