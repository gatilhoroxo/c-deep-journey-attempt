#include <stdio.h>

int main(){
    char name[50];
    int age;
    printf("What's your name? ");
    scanf("%s", &name); // warning .....
    printf("What is your age? ");
    scanf("%d", &age);

    printf("Welcome to my wolrd, %s\n", name);
    if(age > 0){
        if(age < 18){
            printf("You are not alowed to get in, go play with something else\n");
        } else {
            if(age > 100) { printf("You lived a lot huh\n"); } 
            printf("The place is a mess and i'm still organizing and that's it\n");
        }
    } else {
        printf("I don't think you exist\n");
    }

    return 0;
}