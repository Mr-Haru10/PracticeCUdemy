#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person{
    char name[50];
    int age;
    char gender;
};


int main(){
    // Here a object of Person struct is created in main memory and a pointer is attached to is 
    // struct Person p1;
    // strcpy(p1.name, "Harsha"); // Use strcpy to copy the string
    // p1.age = 55;
    // p1.gender = 'M';

    // struct Person *p;
    // p = &p1;

    // printf("%s",p->name);

    // Here a object of the struct is in HEAP memory

    // struct Person *p;

    // p = (struct Person *) malloc(sizeof(struct Person));
    // strcpy(p->name, "Harsha"); // Use strcpy to copy the string
    // p->gender = 'M';
    // p->age = 24;

    // printf("%c", p->gender);
    // free(p);

    return 0;
}