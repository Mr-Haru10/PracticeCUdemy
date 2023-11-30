#include<stdio.h>

void permutation(char s[],int k){
    static int A[4]={0};
    static char res[4];
    int i;
    if (s[k]=='\0'){
        res[k]='\0';
        printf("%s\n",res);
    }else{
        for(i=0;s[i]!='\0';i++){
            if (A[i]==0){
                res[k]=s[i];
                A[i]=1;
                permutation(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main(){
    char str[10]="ABC";
    printf("\n");
    permutation(str,0);
    printf("\n");
    return 0;
}