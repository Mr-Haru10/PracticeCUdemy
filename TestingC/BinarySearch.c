#include<stdio.h>




int binarySearch(int arr[],int arraySizeIs,int find){
    int l,mid,h;
    l=0;
    h=arraySizeIs;

    while (l<=h)
    {
        mid = (l+h)/2;
        if (find == arr[mid]){
            return mid;
        }else if (find<arr[mid]){
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    

    return -1;
}

int main(){

    int a1[10] = {21,23,28,30,31,33,34,37,40};
    int a = binarySearch(a1,9,31);
    printf("At this index '%d'",a);
    
    return 0;
}