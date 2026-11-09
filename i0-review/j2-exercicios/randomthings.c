#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int r;
    do {
        r = rand() % 100;
        printf("%d - ",r);
    } while (r != 13);
    printf("\nFirst round finished with %d\n", r);

    printf("Now with the srand\n");
    srand(time(NULL));
    do {
        r = rand() % 100;
        printf("%d - ", r);
    } while (r != 24);
    printf("\nSecond round finished with %d\n", r);
}