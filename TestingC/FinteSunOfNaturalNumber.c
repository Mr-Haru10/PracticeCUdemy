#include<stdio.h>
// int findSumFor(int num){
//     int sumIs = 0;
//     while (num >= 0)
//     {
//         sumIs += num;
//         num -= 1;
//     }
//     return sumIs;
// }

int findSum(int num){
    if (num == 0){
        return 0;
    }else{
        return findSum(num - 1) + num;
    }
}

int main(){
    int sumToFind;
    printf("enter a number to find the sum of all the natural numbers\n");
    scanf("%d",&sumToFind);
    int a = findSum(sumToFind);
    printf("Sum of all the natural numbers till %d is: %d",sumToFind,a);
    return 0;
}