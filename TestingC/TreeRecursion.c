#include<stdio.h>

void functionIs(int num){
    if (num > 0){
        printf("%d ",num);
        functionIs(num-1);
        functionIs(num-1);
        functionIs(num-1);
    }
}


int main(){
    functionIs(3);
    return 0;
}