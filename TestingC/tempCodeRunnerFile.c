void passByAddress(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}