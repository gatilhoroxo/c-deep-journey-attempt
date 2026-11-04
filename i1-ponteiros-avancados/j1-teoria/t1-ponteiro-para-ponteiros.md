
## Ponteiros para Ponteiros

### 🎯 O Que São?

Ponteiros para ponteiros são ponteiros que apontam para outros ponteiros. Podem ter múltiplos níveis de indireção.

**Analogia:** É como ter um Vivre Card que aponta para outro Vivre Card, que por sua vez aponta para a pessoa real.

### Sintaxe e Declaração

```c
int x = 100;
int *ptr1 = &x;      // Ponteiro simples para x
int **ptr2 = &ptr1;  // Ponteiro para ponteiro
int ***ptr3 = &ptr2; // Ponteiro triplo (raro, mas possível)
```

**Visualização da memória:**
```
x:     [100]      <- valor real
       ↑
ptr1:  [&x]       <- endereço de x
       ↑
ptr2:  [&ptr1]    <- endereço de ptr1
       ↑
ptr3:  [&ptr2]    <- endereço de ptr2
```

### Quando Usar?

1. **Modificar um ponteiro dentro de uma função**
```c
// Problema: Isso NÃO funciona!
void alocar_errado(int *p) {
    p = malloc(sizeof(int));  // Só modifica a cópia local
}

// Solução: Passar ponteiro para ponteiro
void alocar_correto(int **p) {
    *p = malloc(sizeof(int)); // Modifica o ponteiro original
}

// Uso:
int *meu_ptr = NULL;
alocar_correto(&meu_ptr);  // Agora funciona!
```

2. **Arrays bidimensionais dinâmicos**
```c
int **matriz = malloc(linhas * sizeof(int*));
for (int i = 0; i < linhas; i++) {
    matriz[i] = malloc(colunas * sizeof(int));
}
```

3. **Listas encadeadas e árvores**
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Para modificar o início da lista
void inserir_inicio(Node **head, int valor) {
    Node *novo = malloc(sizeof(Node));
    novo->data = valor;
    novo->next = *head;
    *head = novo;  // Modifica o ponteiro original
}
```

### Exercício Mental

**Pergunta:** O que cada expressão retorna?
```c
int x = 42;
int *p = &x;
int **pp = &p;

// p ?       -> endereço de x
// *p ?      -> 42
// pp ?      -> endereço de p  
// *pp ?     -> endereço de x (mesmo que p)
// **pp ?    -> 42 (mesmo que x)
```

---
