
## Ponteiros de Função

### 🎭 O Conceito

Funções também têm endereços na memória! Ponteiros de função permitem armazenar e chamar funções dinamicamente.

**Analogia:** É como ter um Den Den Mushi que pode chamar diferentes tripulações dependendo de qual número você disca!

### Sintaxe Básica

```c
// Declaração de uma função normal
int soma(int a, int b) {
    return a + b;
}

// Declaração de ponteiro para função
int (*ptr_func)(int, int);

// Atribuição
ptr_func = soma;  // Ou ptr_func = &soma; (ambos válidos)

// Chamada
int resultado = ptr_func(5, 3);  // Chama soma(5, 3)
// Ou: int resultado = (*ptr_func)(5, 3);
```

**Lendo a declaração:**
- `int (*ptr_func)(int, int)` = "ptr_func é um ponteiro para função que recebe dois ints e retorna int"

### Quando Usar?

1. **Callbacks**
```c
// Função que ordena um array usando uma função de comparação
void ordenar(int *arr, int n, int (*comparar)(int, int)) {
    // ... algoritmo de ordenação
    if (comparar(arr[i], arr[j]) > 0) {
        // troca elementos
    }
}

// Funções de comparação
int crescente(int a, int b) { return a - b; }
int decrescente(int a, int b) { return b - a; }

// Uso:
int nums[] = {5, 2, 8, 1};
ordenar(nums, 4, crescente);   // Ordena crescente
ordenar(nums, 4, decrescente); // Ordena decrescente
```

2. **Tabelas de Funções (Dispatch Tables)**
```c
typedef enum {
    ADICAO,
    SUBTRACAO,
    MULTIPLICACAO,
    DIVISAO
} Operacao;

int adicionar(int a, int b) { return a + b; }
int subtrair(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }
int dividir(int a, int b) { return b != 0 ? a / b : 0; }

// Tabela de funções
int (*operacoes[])(int, int) = {
    adicionar,
    subtrair,
    multiplicar,
    dividir
};

// Uso:
int resultado = operacoes[ADICAO](10, 5);  // Chama adicionar(10, 5)
```

3. **State Machines (Máquinas de Estado)**
```c
typedef enum { IDLE, RUNNING, PAUSED } Estado;

void estado_idle() { /* ... */ }
void estado_running() { /* ... */ }
void estado_paused() { /* ... */ }

void (*tabela_estados[])() = {
    estado_idle,
    estado_running,
    estado_paused
};

Estado estado_atual = IDLE;
tabela_estados[estado_atual]();  // Executa função do estado atual
```

### Typedef para Facilitar

```c
// Em vez de escrever sempre:
int (*funcao)(int, int);

// Crie um tipo:
typedef int (*OperacaoBinaria)(int, int);

// Agora use:
OperacaoBinaria func1, func2, func3;
```

---
