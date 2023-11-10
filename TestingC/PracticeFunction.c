#include<stdio.h>

int passByValues(int x, int y){
    x = 8;
    y = 2;
    printf("value of x: %d and y: %d\n",x,y);
}

void passByAddress(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 10;
    int b = 5;

    printf("initial value of a: %d and b: %d\n",a,b);
    passByValues(a,b);
    printf("after value of a: %d and b: %d\n",a,b);
    passByAddress(&a, &b);
    printf("a = 10 and b = 5 but when swaped it gets a = %d and b = %d\n",a,b);

    return 0;
}