#include<stdio.h>
#include<string.h>

enum Gender{
    Male,
    Female, 
    Other
};

struct  Person
{
    char name[50];
    int age;
    enum Gender gender;
};

struct Rectangle
{
    int length;
    int bredth;
};


int main(){
    
    struct Person person1;

    person1.name = "harsha";
    // strcpy(person1.name, "John"); // Use strcpy to copy the string
    person1.age = 25;
    person1.gender = Male ;

    // Print the values
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Gender: %d\n", person1.gender);

    // struct Rectangle rect01;
    // rect01.length = 59;
    // rect01.bredth = 09;
    // printf("lenght is: %d\n",rect01.length);
    // printf("bredth is: %d",rect01.bredth);
    return 0;
}