
## Aritmética de Ponteiros

### 🧮 Como Funciona?

Ponteiros em C podem ser somados ou subtraídos. O compilador automaticamente ajusta o incremento baseado no tamanho do tipo!

<!--Nao acho que essa analogia fez tanto sentido, ou se relacionou bem com o tópico-->
**Analogia:** Navegar de ilha em ilha na Grand Line - cada "passo" te leva para a próxima ilha completa, não para o meio do mar!

### Regras Fundamentais

```c
int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;  // p aponta para arr[0]

p++;      // p agora aponta para arr[1]
p += 2;   // p agora aponta para arr[3]
p--;      // p agora aponta para arr[2]
```

**O que realmente acontece:**
```c
int arr[5];
int *p = arr;

p + 1  // NÃO é endereço + 1 byte
       // É endereço + sizeof(int) bytes (geralmente 4)

p + n  // É endereço + (n * sizeof(tipo_apontado))
```

### Operações Permitidas

| Operação | Exemplo | Resultado |
|----------|---------|-----------|
| Ponteiro + Inteiro | `p + 3` | Ponteiro avançado 3 elementos |
| Ponteiro - Inteiro | `p - 2` | Ponteiro recuado 2 elementos |
| Ponteiro - Ponteiro | `p2 - p1` | Número de elementos entre eles |
| Comparação | `p1 < p2` | Verdadeiro se p1 vem antes |

**IMPORTANTE:** Não pode somar dois ponteiros! (`p1 + p2` é inválido)

### Exemplo Prático: Percorrendo Arrays

```c
int arr[] = {1, 2, 3, 4, 5};
int *p = arr;

// Método 1: Índices
for (int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
}

// Método 2: Aritmética de ponteiros
for (int i = 0; i < 5; i++) {
    printf("%d ", *(p + i));
}

// Método 3: Incrementando o ponteiro
int *end = arr + 5;
for (p = arr; p < end; p++) {
    printf("%d ", *p);
}
```

### Diferença Entre Tipos

```c
// Array de ints
int arr_int[3] = {1, 2, 3};
int *p_int = arr_int;
printf("p_int: %p\n", p_int);
printf("p_int+1: %p\n", p_int + 1);  // +4 bytes (ou +8 em 64-bit)

// Array de chars
char arr_char[3] = {'a', 'b', 'c'};
char *p_char = arr_char;
printf("p_char: %p\n", p_char);
printf("p_char+1: %p\n", p_char + 1);  // +1 byte

// Array de structs
struct {int x; int y;} arr_struct[3];
void *p_struct = arr_struct;
printf("p_struct: %p\n", p_struct);
printf("p_struct+1: %p\n", p_struct + sizeof(struct));  // +8 bytes
```

---
