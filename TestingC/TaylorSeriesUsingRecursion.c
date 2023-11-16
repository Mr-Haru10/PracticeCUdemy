#include<stdio.h>

double calculateFor(int e, int n){
    static double p = 1, f = 1;
    double r;
    if (n == 0 || e == 0){
        return 1;
    }else{
        r = calculateFor(e, n - 1);
        p = p*e;
        f = f*n;
        return r + p/f;
    }
}

int main(){
    double a = calculateFor(1, 100);
    printf("%f",a);
    return 0;
}