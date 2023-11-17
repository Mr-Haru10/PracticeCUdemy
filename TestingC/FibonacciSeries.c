// #include<stdio.h>

// int fibo(int n){
//     if (n<=1){
//         return n;
//     }else{
//         return fibo(n-2)+fibo(n-1);
//     }
// }

// int main(){
//     int num = 0;
//     printf("enter a positive number\n");
//     scanf("%d",&num);
//     int a = fibo(num);
//     printf("fibonacci number for %d is: %d", num,a);
//     return 0;
// }

#include<stdio.h>

long findFibo(int n){
    long arrIs[n];
    if (n<=1){
        return n;
    }else{
        for(int i = 0; i <= n; i++){
            if (i == 0 || i == 1){
                arrIs[i] = i;     
            }else{
                long num = arrIs[i-2] + arrIs[i-1];
                arrIs[i] = num;
            }
        }
    }
    printf("array is: ");
    for(int i=0; i<= n; i++){
        printf("%ld ",arrIs[i]);
    }

    return arrIs[n];
}
int main(){
    int s = 0;
    printf("enter a positive number\n");
    scanf("%d",&s);
    long a = findFibo(s);
    printf("\nfibonacci number for %d is: %ld", s,a);
    return 0;
}