
## Ponteiros Constantes

### 🔒 Quatro Combinações

**Analogia:** É como diferentes níveis de proteção em um tesouro!

```c
int valor = 42;
int novo = 100;

// 1. Ponteiro normal
int *p1 = &valor;
*p1 = 50;     // OK - modifica o valor
p1 = &novo;   // OK - modifica o ponteiro

// 2. Ponteiro para constante (const int*)
const int *p2 = &valor;
*p2 = 50;     // ERRO! - não pode modificar o valor
p2 = &novo;   // OK - pode modificar o ponteiro

// 3. Ponteiro constante (int* const)
int* const p3 = &valor;
*p3 = 50;     // OK - pode modificar o valor
p3 = &novo;   // ERRO! - não pode modificar o ponteiro

// 4. Ponteiro constante para constante (const int* const)
const int* const p4 = &valor;
*p4 = 50;     // ERRO! - não pode modificar o valor
p4 = &novo;   // ERRO! - não pode modificar o ponteiro
```

### Regra de Leitura

**Leia da direita para esquerda:**

```c
const int *p;        // p é um ponteiro para int constante
int const *p;        // p é um ponteiro para constante int (mesmo que acima)
int * const p;       // p é um ponteiro constante para int
const int * const p; // p é um ponteiro constante para int constante
```

### Uso Prático

```c
// Em funções, para indicar que não vai modificar o argumento
void imprimir_array(const int *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
        // arr[i] = 0;  // ERRO de compilação!
    }
}

// Retornar string literal (que é const)
const char* obter_mensagem() {
    return "Hello, World!";  // String literal é const
}
```

---
