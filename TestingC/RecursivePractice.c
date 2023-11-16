#include<stdio.h>
int x=0;
int recursiveFunc(int num){
    
    if (num>0){
        x++;
        return recursiveFunc(num - 1) + x;
    }
    return 0;
}


int main(){

    int a = recursiveFunc(5);
    printf("a: %d",a);
    return 0;
}
