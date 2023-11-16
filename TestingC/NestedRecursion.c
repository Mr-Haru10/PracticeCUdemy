#include<stdio.h>

int func(int num){
    if (num > 100){
        return num - 10;
    }else{
        return func(func(num + 11));
    }
}

int main(){
    int a = func(102);
    printf("%d isisis",a);
    return 0;
}