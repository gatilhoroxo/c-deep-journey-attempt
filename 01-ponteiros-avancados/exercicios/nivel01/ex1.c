#include <stdio.h>

void trocar(int* pa, int* pb){
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}

int main(){
    int x = 10;
    int y = 20;
    printf("Antes: x = %d, y =%d\n", x, y);
    trocar(&x,&y);
    printf("Depois: x = %d, y =%d\n", x, y);
    return 0;
}