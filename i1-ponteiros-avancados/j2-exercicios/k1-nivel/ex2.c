#include <stdio.h>

float calcular_media_local(){
    float leituras[] = {20,22,19,23,21};
    int tam = sizeof(leituras) / sizeof(leituras[0]);

    float soma = 0;
    for(int i=0; i<tam; i++){ soma += leituras[i]; }

    printf("Sizeof's media local\n");
    printf("\tsizeof array: %ld\n\tsizeof: %ld\n", sizeof(leituras), sizeof(leituras[0]));

    return soma/tam;
}

float calcular_media_func(float* leituras, int num){
    float soma = 0;
    int i=0;
    for(float* p = leituras, i=0; i<num; p++,i++){
        soma += (*p);
    }

    printf("Sizeof's media func\n");
    printf("\tsizeof ponteiro: %ld\n\tsizeof: %ld\n", sizeof(leituras), sizeof(leituras[0]));

    return soma / num;
}

int main(){
    printf("=== Teste com Array Local ===\n");
    float media_local = calcular_media_local();
    printf("Media calculada localmente: %.2f\n", media_local);

    printf("=== Teste com Array na Funcao ===\n");
    float sensores[] = {13.5, 16.8, 30.4, 17, 19.7};
    int num = sizeof(sensores) / sizeof(sensores[0]);
    media_local=0;
    for(int i=0; i<num;i++) media_local += sensores[i];
    media_local = media_local / num;
    printf("Na main, sizeof(sensores) = %ld\n", sizeof(sensores));
    printf("Media calculada na main: %.2f\n", media_local);

    media_local = calcular_media_func(sensores, num);
    printf("Media calculada na funcao: %.2f\n", media_local);

    return 0;
}