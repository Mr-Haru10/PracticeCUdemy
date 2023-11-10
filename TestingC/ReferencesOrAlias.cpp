#include<iostream>
int main(){
    // Reference or Alias is not avilable in C
    int a = 5;
    int &b = a;
    int c = 500;
    b = c;
    printf("%d",b);
    return 0;
}