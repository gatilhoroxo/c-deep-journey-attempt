
## Arrays vs Ponteiros

### ⚖️ As Diferenças Sutis

**Analogia:** Arrays são como ilhas - fixas no mapa. Ponteiros são como navios - podem se mover livremente!

### Similaridades

Na maioria dos contextos, arrays "decaem" para ponteiros:

```c
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;  // arr decai para ponteiro

arr[2];    // Mesmo que *(arr + 2)
p[2];      // Mesmo que *(p + 2)
```

### Diferenças Cruciais

1. **Sizeof**
```c
int arr[10];
int *p = arr;

sizeof(arr);  // 40 (10 * sizeof(int))
sizeof(p);    // 8 (tamanho do ponteiro em 64-bit)
```

2. **Address-of**
```c
int arr[5];
int *p = arr;

&arr;   // Ponteiro para o array inteiro (tipo: int (*)[5])
&p;     // Ponteiro para o ponteiro (tipo: int **)

// &arr + 1 pula o array inteiro (20 bytes)
// &p + 1 pula apenas o ponteiro (8 bytes)
```

3. **Modificação**
```c
int arr[5];
int *p = arr;

p = p + 1;   // OK - ponteiros podem ser reatribuídos
arr = arr + 1;  // ERRO! - Arrays são constantes
```

4. **Inicialização**
```c
int arr[] = {1, 2, 3};  // OK - inicializa o array
int *p = {1, 2, 3};     // ERRO! - sintaxe inválida
```

### Arrays Multidimensionais

```c
// Array 2D real - contíguo na memória
int matriz[3][4];  // 3*4 = 12 ints consecutivos
matriz[1][2];      // Acesso direto

// Array de ponteiros - não contíguo
int *arr_ptrs[3];  // 3 ponteiros
for (int i = 0; i < 3; i++) {
    arr_ptrs[i] = malloc(4 * sizeof(int));  // Aloca cada linha
}
arr_ptrs[1][2];  // Precisa de duas dereferências
```

---
