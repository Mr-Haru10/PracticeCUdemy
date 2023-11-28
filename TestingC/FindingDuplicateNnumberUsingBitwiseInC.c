#include<stdio.h>

int main(){
    char arr[]="harsha";
    long int h=0,x=0;

    for(int i=0;arr[i]!='\0';i++){
        x=1;
        x = x << (arr[i]-97);
        printf("%ld \n",h);
        if((x&h)>0){
            printf("dup char is %c\n",arr[i]);
        }else{
            h = x|h;
        }
        
    }

    return 0;
}