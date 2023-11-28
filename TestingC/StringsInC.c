#include<stdio.h>

#include <stdio.h>

int main() {
    char name[25];
    int i,scount;
    
    printf("Enter your name:\n");
    scanf(" %[^\n]", name);  // Note the space before %[^\n] to consume any leading whitespace

    printf("Your name is %s\n", name);

    for (i = 0; name[i] != '\0'; i++) {
        if(name[i]==' '){
            scount++;
        }
    }

    printf("Your name contains %d characters!\n", scount);

    return 0;
}
