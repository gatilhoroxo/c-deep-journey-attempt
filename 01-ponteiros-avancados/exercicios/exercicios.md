# 📝 Exercícios - Ponteiros Avançados

> *"A prática leva à perfeição. Cada exercício é uma ilha a conquistar!"*

## Instruções

- Os exercícios estão em pseudocódigo
- Implemente-os em C puro
- Compile com flags: `-Wall -Wextra -g`
- Use `valgrind` para checar memory leaks
- Teste com diferentes inputs

---

## 🔰 Nível 1: Fundamentos

### Exercício 1.1: Troca com Ponteiros
**Objetivo:** Dominar passagem de ponteiros para funções

```
FUNÇÃO trocar(ponteiro para inteiro a, ponteiro para inteiro b):
    // Trocar os valores apontados por a e b
    // Sem usar variável temporária de tipo int
    // Dica: Operações XOR ou aritmética de ponteiros
FIM
```

**Teste:**
```
PRINCIPAL:
    x = 10
    y = 20
    IMPRIMIR "Antes: x =", x, "y =", y
    trocar(&x, &y)
    IMPRIMIR "Depois: x =", x, "y =", y
FIM
```

---

### Exercício 1.2: Tamanho de Array
**Objetivo:** Entender diferença entre array e ponteiro

```
FUNÇÃO tamanho_array(array de inteiros arr):
    // Calcular e retornar o número de elementos
    // Usar apenas operações com ponteiros e sizeof
FIM

FUNÇÃO tamanho_ponteiro(ponteiro para inteiros p, inteiro n):
    // Receber tamanho explicitamente
    // Explicar por que precisa de 'n' como parâmetro
FIM
```

**Teste:**
```
PRINCIPAL:
    arr[] = {1, 2, 3, 4, 5}
    tamanho = tamanho_array(arr)
    IMPRIMIR "Tamanho:", tamanho
    
    ponteiro p = arr
    // Por que tamanho_array(p) não funcionaria?
FIM
```

---

### Exercício 1.3: Reverter Array In-Place
**Objetivo:** Aritmética de ponteiros

```
FUNÇÃO reverter(ponteiro para inteiros arr, inteiro tamanho):
    // Reverter array usando APENAS aritmética de ponteiros
    // Não usar índices (sem arr[i])
    // Usar dois ponteiros: início e fim
FIM
```

**Teste:**
```
PRINCIPAL:
    arr[] = {1, 2, 3, 4, 5}
    IMPRIMIR "Antes:", arr
    reverter(arr, 5)
    IMPRIMIR "Depois:", arr  // [5, 4, 3, 2, 1]
FIM
```

---

## 🔶 Nível 2: Ponteiros para Ponteiros

### Exercício 2.1: Matriz Dinâmica
**Objetivo:** Alocar e manipular matriz 2D

```
FUNÇÃO criar_matriz(inteiro linhas, inteiro colunas):
    // Alocar matriz dinâmica usando ponteiro para ponteiros
    // Retornar ponteiro duplo para inteiros
FIM

FUNÇÃO preencher_matriz(ponteiro duplo matriz, inteiro linhas, inteiro colunas):
    // Preencher com valores sequenciais (0, 1, 2, ...)
FIM

FUNÇÃO imprimir_matriz(ponteiro duplo matriz, inteiro linhas, inteiro colunas):
    // Imprimir em formato de grid
FIM

FUNÇÃO liberar_matriz(ponteiro duplo matriz, inteiro linhas):
    // Liberar toda memória alocada
FIM
```

**Teste:**
```
PRINCIPAL:
    mat = criar_matriz(3, 4)
    preencher_matriz(mat, 3, 4)
    imprimir_matriz(mat, 3, 4)
    liberar_matriz(mat, 3)
FIM
```

---

### Exercício 2.2: Dividir String
**Objetivo:** Manipular array de strings (char**)

```
FUNÇÃO dividir_string(string texto, caractere delimitador):
    // Dividir 'texto' pelo 'delimitador'
    // Retornar array de strings (char**)
    // Exemplo: "a,b,c" com ',' -> ["a", "b", "c"]
    // Alocar memória dinamicamente
FIM

FUNÇÃO contar_tokens(string texto, caractere delimitador):
    // Contar quantas partes teremos
FIM

FUNÇÃO liberar_strings(ponteiro duplo strings, inteiro quantidade):
    // Liberar array de strings
FIM
```

**Teste:**
```
PRINCIPAL:
    texto = "One,Piece,é,incrível"
    partes = dividir_string(texto, ',')
    // Imprimir cada parte
    liberar_strings(partes, quantidade)
FIM
```

---

### Exercício 2.3: Redimensionar Array
**Objetivo:** Modificar ponteiro original

```
FUNÇÃO redimensionar(ponteiro para ponteiro array, inteiro tamanho_atual, inteiro novo_tamanho):
    // Redimensionar array apontado por *array
    // Copiar dados antigos se novo_tamanho > tamanho_atual
    // Usar realloc ou malloc+memcpy+free
FIM
```

**Teste:**
```
PRINCIPAL:
    arr = alocar array com 5 inteiros
    preencher arr com [1, 2, 3, 4, 5]
    
    redimensionar(&arr, 5, 10)
    // arr agora tem espaço para 10 elementos
    
    preencher novos elementos com valores
    imprimir todos os 10 elementos
FIM
```

---

## 🔷 Nível 3: Ponteiros de Função

### Exercício 3.1: Calculadora com Callbacks
**Objetivo:** Usar ponteiros de função básicos

```
TIPO ponteiro_operacao = ponteiro para função(inteiro, inteiro) retorna inteiro

FUNÇÃO somar(inteiro a, inteiro b):
    retornar a + b
FIM

FUNÇÃO subtrair(inteiro a, inteiro b):
    retornar a - b
FIM

// Criar mais funções: multiplicar, dividir, potencia

FUNÇÃO executar_operacao(inteiro a, inteiro b, ponteiro_operacao op):
    // Chamar a função apontada por 'op'
FIM
```

**Teste:**
```
PRINCIPAL:
    IMPRIMIR executar_operacao(10, 5, somar)      // 15
    IMPRIMIR executar_operacao(10, 5, subtrair)   // 5
    IMPRIMIR executar_operacao(10, 5, multiplicar) // 50
FIM
```

---

### Exercício 3.2: Ordenação Genérica
**Objetivo:** Callbacks para comparação

```
TIPO comparador = ponteiro para função(ponteiro void, ponteiro void) retorna inteiro

FUNÇÃO ordenar_generico(ponteiro void array, inteiro tamanho, inteiro tamanho_elemento, comparador comp):
    // Implementar bubble sort ou insertion sort
    // Funcionar para qualquer tipo de dado
    // Usar comp para comparar elementos
FIM

FUNÇÃO comparar_inteiros(ponteiro void a, ponteiro void b):
    // Cast para int* e comparar
FIM

FUNÇÃO comparar_strings(ponteiro void a, ponteiro void b):
    // Cast para char** e usar strcmp
FIM
```

**Teste:**
```
PRINCIPAL:
    ints[] = {5, 2, 8, 1, 9}
    ordenar_generico(ints, 5, sizeof(int), comparar_inteiros)
    
    strings[] = {"zebra", "apple", "mango", "banana"}
    ordenar_generico(strings, 4, sizeof(char*), comparar_strings)
FIM
```

---

### Exercício 3.3: Sistema de Eventos
**Objetivo:** Tabela de callbacks

```
TIPO evento_handler = ponteiro para função(ponteiro void dados)

ESTRUTURA EventManager:
    handlers: array de evento_handler
    num_handlers: inteiro
FIM

FUNÇÃO registrar_evento(ponteiro EventManager em, evento_handler handler):
    // Adicionar handler à lista
FIM

FUNÇÃO disparar_eventos(ponteiro EventManager em, ponteiro void dados):
    // Chamar todos os handlers registrados
FIM

// Criar alguns handlers de exemplo:
FUNÇÃO on_iniciar(ponteiro void dados):
    IMPRIMIR "Sistema iniciado!"
FIM

FUNÇÃO on_erro(ponteiro void dados):
    IMPRIMIR "Erro detectado!"
FIM
```

**Teste:**
```
PRINCIPAL:
    manager = criar EventManager
    
    registrar_evento(&manager, on_iniciar)
    registrar_evento(&manager, on_erro)
    
    disparar_eventos(&manager, NULL)
    // Deve chamar on_iniciar e on_erro
FIM
```

---

## 🔶 Nível 4: Arrays vs Ponteiros

### Exercício 4.1: Análise de Memória
**Objetivo:** Entender layout de memória

```
FUNÇÃO analisar_memoria():
    // Criar um array e um ponteiro
    arr: array de 5 inteiros
    p: ponteiro para inteiro = arr
    
    // Imprimir e explicar cada valor:
    1. sizeof(arr)
    2. sizeof(p)
    3. &arr
    4. &arr + 1
    5. &p
    6. &p + 1
    7. arr
    8. arr + 1
    9. p
    10. p + 1
    
    // Explicar a diferença em comentários
FIM
```

---

### Exercício 4.2: Array de Arrays vs Array de Ponteiros
**Objetivo:** Entender diferença crucial

```
FUNÇÃO comparar_estruturas():
    // Estrutura 1: Array 2D real
    mat1: array[3][4] de inteiros
    
    // Estrutura 2: Array de ponteiros
    mat2: array de 3 ponteiros para inteiros
    PARA i de 0 até 2:
        mat2[i] = alocar 4 inteiros
    FIM
    
    // Comparar:
    // - Memória contígua?
    // - sizeof total?
    // - Acesso mat[i][j]?
    // - Qual é mais eficiente?
FIM
```

---

### Exercício 4.3: Passagem de Arrays Multidimensionais
**Objetivo:** Sintaxe correta para funções

```
// Implemente 3 formas diferentes:

FUNÇÃO processar_v1(array de ponteiros, linhas, colunas):
    // Usando ponteiro simples
FIM

FUNÇÃO processar_v2(ponteiro para array[COLUNAS], linhas):
    // Usando ponteiro para array de tamanho fixo
FIM

FUNÇÃO processar_v3(ponteiro duplo, linhas, colunas):
    // Usando ponteiro duplo
FIM

// Explicar quando usar cada uma
```

---

## 🔷 Nível 5: Desafios Avançados

### Exercício 5.1: Sistema de Alocação Personalizado
**Objetivo:** Criar seu próprio malloc/free simplificado

```
ESTRUTURA Bloco:
    tamanho: inteiro
    livre: booleano
    proximo: ponteiro para Bloco
FIM

GLOBAL pool_memoria: array de bytes
GLOBAL lista_blocos: ponteiro para Bloco

FUNÇÃO meu_malloc(tamanho):
    // Procurar bloco livre na lista
    // Se não encontrar, dividir um bloco maior
    // Marcar como usado e retornar ponteiro
FIM

FUNÇÃO meu_free(ponteiro):
    // Marcar bloco como livre
    // Tentar juntar blocos adjacentes livres
FIM

FUNÇÃO imprimir_memoria():
    // Visualizar estado da memória
FIM
```

---

### Exercício 5.2: Interpretador de Comandos
**Objetivo:** Tabela de dispatch com ponteiros de função

```
ESTRUTURA Comando:
    nome: string
    handler: ponteiro para função(array de strings) retorna inteiro
    ajuda: string
FIM

GLOBAL tabela_comandos: array de Comando

FUNÇÃO cmd_ajuda(argumentos):
    // Listar todos comandos disponíveis
FIM

FUNÇÃO cmd_sair(argumentos):
    // Encerrar programa
FIM

// Adicionar mais comandos: echo, calc, etc.

FUNÇÃO registrar_comando(nome, handler, ajuda):
    // Adicionar à tabela_comandos
FIM

FUNÇÃO executar_comando(nome, argumentos):
    // Procurar na tabela e executar
FIM

FUNÇÃO loop_principal():
    ENQUANTO verdadeiro:
        ler linha
        parsear em comando e argumentos
        executar_comando(comando, argumentos)
FIM
```

---

### Exercício 5.3: Smart Pointers em C
**Objetivo:** Criar sistema de contagem de referências

```
ESTRUTURA SmartPointer:
    dados: ponteiro void
    contador_ref: ponteiro para inteiro
FIM

FUNÇÃO criar_smart_ptr(ponteiro dados):
    // Alocar contador_ref
    // Inicializar com 1
    // Retornar SmartPointer
FIM

FUNÇÃO copiar_smart_ptr(SmartPointer original):
    // Incrementar contador
    // Retornar cópia
FIM

FUNÇÃO liberar_smart_ptr(ponteiro SmartPointer sp):
    // Decrementar contador
    // Se contador == 0, liberar dados e contador
FIM

// Teste com struct complexa
ESTRUTURA Pessoa:
    nome: string
    idade: inteiro
FIM
```

---
