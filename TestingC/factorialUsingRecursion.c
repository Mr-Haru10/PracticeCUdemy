#include<stdio.h>

int func(int num){
    if (num <= 0){
        return 1;
    }else{
        return func(num - 1) * num;
    }
}
int main(){
    int sumToFind;
    printf("enter a number to find the factorial of it\n");
    scanf("%d",&sumToFind);
    int a = func(sumToFind);
    printf("factorial of %d is: %d",sumToFind,a);
    return 0;
}