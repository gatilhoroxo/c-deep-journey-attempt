
## 🔷 Nível 3: Ponteiros de Função

> **Objetivo Pedagógico:** Dominar callbacks, polimorfismo em C, e design patterns baseados em ponteiros de função.

---

### 🧮 Exercício 3.1: Sistema de Plugin de Operações Matemáticas
**Conceito:** Ponteiros de função básicos e tabelas de dispatch

**Contexto:**  
Você está desenvolvendo uma calculadora científica modular onde novas operações podem ser adicionadas como "plugins". Cada operação é uma função que pode ser registrada e chamada dinamicamente. Isso é similar ao sistema de plugins de editores de texto ou IDEs.

**Especificação:**
```c
// Definir tipo para ponteiro de função de operação
typedef double (*operacao_fn)(double a, double b);

ESTRUTURA Operacao:
    char* nome              // Nome da operação (ex: "soma", "multiplicacao")
    char simbolo            // Símbolo (ex: '+', '*')
    operacao_fn funcao      // Ponteiro para a função
FIM

ESTRUTURA Calculadora:
    Operacao* operacoes     // Array dinâmico de operações
    int num_operacoes       // Quantidade de operações registradas
    int capacidade          // Capacidade do array
FIM

// Implementar operações básicas
FUNÇÃO somar(double a, double b):
    retornar a + b
FIM

FUNÇÃO subtrair(double a, double b):
    retornar a - b
FIM

FUNÇÃO multiplicar(double a, double b):
    retornar a * b
FIM

FUNÇÃO dividir(double a, double b):
    SE b == 0:
        IMPRIMIR "Erro: divisão por zero!"
        retornar NAN  // Not a Number
    retornar a / b
FIM

FUNÇÃO potencia(double a, double b):
    retornar pow(a, b)  // #include <math.h>
FIM

// Sistema de gerenciamento
FUNÇÃO criar_calculadora():
    // Alocar e inicializar Calculadora
    // Capacidade inicial: 5 operações
FIM

FUNÇÃO registrar_operacao(Calculadora* calc, char* nome, char simbolo, operacao_fn fn):
    // Adicionar nova operação ao sistema
    // Redimensionar array se necessário
FIM

FUNÇÃO buscar_operacao(Calculadora* calc, char simbolo):
    // Buscar operação por símbolo
    // Retornar ponteiro para Operacao, ou NULL se não encontrar
FIM

FUNÇÃO executar(Calculadora* calc, double a, char simbolo, double b):
    // Buscar operação pelo símbolo
    // Executar a operação: funcao(a, b)
    // Retornar resultado
FIM

FUNÇÃO listar_operacoes(Calculadora* calc):
    // Listar todas as operações disponíveis
    // Formato: + : soma
    //          - : subtração
FIM

FUNÇÃO liberar_calculadora(Calculadora* calc):
    // Liberar recursos
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    IMPRIMIR "=== Calculadora Modular com Plugins ==="
    
    calc = criar_calculadora()
    
    // Registrar operações (como plugins)
    registrar_operacao(calc, "soma", '+', somar)
    registrar_operacao(calc, "subtração", '-', subtrair)
    registrar_operacao(calc, "multiplicação", '*', multiplicar)
    registrar_operacao(calc, "divisão", '/', dividir)
    registrar_operacao(calc, "potência", '^', potencia)
    
    IMPRIMIR "\nOperações disponíveis:"
    listar_operacoes(calc)
    
    // Testes
    IMPRIMIR "\n=== Executando Operações ==="
    IMPRIMIR "10 + 5 =", executar(calc, 10, '+', 5)
    IMPRIMIR "10 - 5 =", executar(calc, 10, '-', 5)
    IMPRIMIR "10 * 5 =", executar(calc, 10, '*', 5)
    IMPRIMIR "10 / 5 =", executar(calc, 10, '/', 5)
    IMPRIMIR "2 ^ 8 =", executar(calc, 2, '^', 8)
    
    // Teste de erro
    IMPRIMIR "\nTeste de divisão por zero:"
    resultado = executar(calc, 10, '/', 0)
    
    liberar_calculadora(calc)
FIM
```

**Aprendizados:**
- Ponteiros de função permitem "polimorfismo" em C
- Pattern de plugin system: registrar funções dinamicamente
- Typedef simplifica declarações complexas
- Tabela de dispatch é base de máquinas virtuais e interpretadores

---

### 📊 Exercício 3.2: Sistema de Ordenação Universal
**Conceito:** Funções genéricas com callbacks de comparação (estilo `qsort`)

**Contexto:**  
Você precisa implementar um sistema de ordenação que funcione para QUALQUER tipo de dado. Isso é exatamente o que a função `qsort` da stdlib faz. Você vai entender como bibliotecas como stdlib implementam funções genéricas em C puro.

**Especificação:**
```c
// Tipo para função de comparação
// Retorna: < 0 se a < b, 0 se a == b, > 0 se a > b
typedef int (*comparador_fn)(const void* a, const void* b);

FUNÇÃO ordenar_generico(void* array, int tamanho, int tamanho_elemento, comparador_fn comparar):
    // Implementar ordenação genérica (Bubble Sort ou Insertion Sort)
    // Trabalhar com void* - não sabe o tipo!
    // 
    // Processo:
    //   1. Tratar array como array de bytes: char* base = (char*)array
    //   2. Para acessar elemento i: base + (i * tamanho_elemento)
    //   3. Usar comparar() para comparar elementos
    //   4. Para trocar elementos, usar memcpy ou função auxiliar
    //
    // Dica: Criar buffer temporário para swap
    //   char temp[tamanho_elemento]
    //   memcpy(temp, elem1, tamanho_elemento)
FIM

FUNÇÃO trocar_bytes(void* a, void* b, int tamanho):
    // Trocar 'tamanho' bytes entre a e b
    // Usar buffer temporário
FIM

// Comparadores para diferentes tipos
FUNÇÃO comparar_int(const void* a, const void* b):
    int val_a = *(const int*)a
    int val_b = *(const int*)b
    retornar val_a - val_b
FIM

FUNÇÃO comparar_int_decrescente(const void* a, const void* b):
    // Inverter ordem
    retornar comparar_int(b, a)
FIM

FUNÇÃO comparar_string(const void* a, const void* b):
    // a e b são ponteiros para char*
    const char* str_a = *(const char**)a
    const char* str_b = *(const char**)b
    retornar strcmp(str_a, str_b)
FIM

ESTRUTURA Pessoa:
    char nome[50]
    int idade
FIM

FUNÇÃO comparar_pessoa_por_idade(const void* a, const void* b):
    const Pessoa* p1 = (const Pessoa*)a
    const Pessoa* p2 = (const Pessoa*)b
    retornar p1->idade - p2->idade
FIM

FUNÇÃO comparar_pessoa_por_nome(const void* a, const void* b):
    const Pessoa* p1 = (const Pessoa*)a
    const Pessoa* p2 = (const Pessoa*)b
    retornar strcmp(p1->nome, p2->nome)
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    // Teste 1: Ordenar inteiros
    IMPRIMIR "=== Teste 1: Ordenar Inteiros ==="
    int numeros[] = {64, 34, 25, 12, 22, 11, 90}
    int n = sizeof(numeros) / sizeof(numeros[0])
    
    ordenar_generico(numeros, n, sizeof(int), comparar_int)
    IMPRIMIR "Crescente:", numeros
    
    ordenar_generico(numeros, n, sizeof(int), comparar_int_decrescente)
    IMPRIMIR "Decrescente:", numeros
    
    // Teste 2: Ordenar strings
    IMPRIMIR "\n=== Teste 2: Ordenar Strings ==="
    char* frutas[] = {"banana", "maçã", "laranja", "abacaxi", "uva"}
    n = sizeof(frutas) / sizeof(frutas[0])
    
    ordenar_generico(frutas, n, sizeof(char*), comparar_string)
    PARA i de 0 até n:
        IMPRIMIR frutas[i]
    
    // Teste 3: Ordenar estruturas
    IMPRIMIR "\n=== Teste 3: Ordenar Pessoas ==="
    Pessoa pessoas[] = {
        {"João", 25},
        {"Maria", 30},
        {"Pedro", 20},
        {"Ana", 28}
    }
    n = sizeof(pessoas) / sizeof(pessoas[0])
    
    IMPRIMIR "Ordenado por idade:"
    ordenar_generico(pessoas, n, sizeof(Pessoa), comparar_pessoa_por_idade)
    // Imprimir pessoas
    
    IMPRIMIR "\nOrdenado por nome:"
    ordenar_generico(pessoas, n, sizeof(Pessoa), comparar_pessoa_por_nome)
    // Imprimir pessoas
    
    // Teste 4: Comparar com qsort da stdlib
    IMPRIMIR "\n=== Comparação com qsort ==="
    int nums[] = {5, 2, 8, 1, 9}
    qsort(nums, 5, sizeof(int), comparar_int)
    IMPRIMIR "qsort resultado:", nums
FIM
```

**Aprendizados:**
- `void*` permite polimorfismo genérico em C
- Aritmética de ponteiros com bytes: `(char*)base + offset`
- Callbacks de comparação padronizam interface (< 0, 0, > 0)
- `memcpy` é essencial para manipular dados genéricos
- Padrão usado por `qsort`, `bsearch` e outras funções stdlib

---

### 🎯 Exercício 3.3: Sistema de Eventos e Observadores (Observer Pattern)
**Conceito:** Callbacks múltiplos e gerenciamento de eventos

**Contexto:**  
Você está desenvolvendo um sistema de monitoramento IoT onde múltiplos componentes precisam reagir a eventos (sensor detectou movimento, temperatura alta, etc). Este é o padrão Observer, usado em GUIs, sistemas de eventos de jogos, e arquiteturas reativas.

**Especificação:**
```c
// Tipo de evento
typedef enum {
    EVENTO_TEMPERATURA_ALTA,
    EVENTO_MOVIMENTO_DETECTADO,
    EVENTO_PORTA_ABERTA,
    EVENTO_BATERIA_BAIXA,
    NUM_TIPOS_EVENTO
} TipoEvento;

// Dados do evento
typedef struct {
    TipoEvento tipo;
    double valor;           // Valor do sensor (temperatura, etc)
    char* localizacao;      // Onde ocorreu
    time_t timestamp;       // Quando ocorreu
} DadosEvento;

// Callback para tratar evento
typedef void (*callback_evento)(DadosEvento* dados);

// Observer (observador registrado)
typedef struct {
    char* nome;                 // Nome do observador
    callback_evento callback;   // Função a chamar
    TipoEvento tipo_interesse;  // Tipo de evento que interessa
} Observer;

// Gerenciador de eventos
typedef struct {
    Observer** observers;       // Array dinâmico de observers
    int num_observers;
    int capacidade;
} GerenciadorEventos;

// Funções do sistema
FUNÇÃO criar_gerenciador():
    // Alocar e inicializar GerenciadorEventos
FIM

FUNÇÃO registrar_observer(GerenciadorEventos* ger, char* nome, 
                          TipoEvento tipo, callback_evento callback):
    // Adicionar novo observer
    // Redimensionar array se necessário
FIM

FUNÇÃO remover_observer(GerenciadorEventos* ger, char* nome):
    // Remover observer pelo nome
FIM

FUNÇÃO disparar_evento(GerenciadorEventos* ger, TipoEvento tipo, 
                       double valor, char* localizacao):
    // Criar DadosEvento
    // Percorrer observers
    // Chamar callback de cada observer interessado no tipo
FIM

FUNÇÃO listar_observers(GerenciadorEventos* ger):
    // Listar todos os observers registrados
FIM

// Callbacks de exemplo (handlers)
FUNÇÃO handler_alarme(DadosEvento* dados):
    IMPRIMIR "[ALARME] Temperatura alta detectada!"
    IMPRIMIR "  Local:", dados->localizacao
    IMPRIMIR "  Temperatura:", dados->valor, "°C"
FIM

FUNÇÃO handler_notificacao(DadosEvento* dados):
    IMPRIMIR "[NOTIFICAÇÃO] Movimento detectado em", dados->localizacao
FIM

FUNÇÃO handler_log(DadosEvento* dados):
    IMPRIMIR "[LOG]", ctime(&dados->timestamp), "-", 
             "Evento tipo", dados->tipo, "em", dados->localizacao
FIM

FUNÇÃO handler_seguranca(DadosEvento* dados):
    SE dados->tipo == EVENTO_PORTA_ABERTA:
        IMPRIMIR "[SEGURANÇA] Porta aberta em", dados->localizacao
        IMPRIMIR "  Iniciando protocolo de segurança..."
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    IMPRIMIR "=== Sistema de Monitoramento IoT ==="
    
    ger = criar_gerenciador()
    
    // Registrar observers para diferentes eventos
    IMPRIMIR "\n--- Registrando Observers ---"
    registrar_observer(ger, "Sistema de Alarme", 
                      EVENTO_TEMPERATURA_ALTA, handler_alarme)
    registrar_observer(ger, "Notificador Push", 
                      EVENTO_MOVIMENTO_DETECTADO, handler_notificacao)
    registrar_observer(ger, "Sistema de Log", 
                      EVENTO_TEMPERATURA_ALTA, handler_log)
    registrar_observer(ger, "Central de Segurança", 
                      EVENTO_PORTA_ABERTA, handler_seguranca)
    registrar_observer(ger, "Log de Segurança", 
                      EVENTO_PORTA_ABERTA, handler_log)
    
    listar_observers(ger)
    
    // Simular eventos
    IMPRIMIR "\n\n=== Simulando Eventos ==="
    
    IMPRIMIR "\n[1] Temperatura alta na sala de servidores:"
    disparar_evento(ger, EVENTO_TEMPERATURA_ALTA, 
                   45.5, "Sala de Servidores")
    
    IMPRIMIR "\n[2] Movimento detectado no corredor:"
    disparar_evento(ger, EVENTO_MOVIMENTO_DETECTADO, 
                   0, "Corredor Principal")
    
    IMPRIMIR "\n[3] Porta aberta - entrada lateral:"
    disparar_evento(ger, EVENTO_PORTA_ABERTA, 
                   0, "Entrada Lateral")
    
    // Remover observer
    IMPRIMIR "\n\n--- Removendo 'Sistema de Alarme' ---"
    remover_observer(ger, "Sistema de Alarme")
    
    IMPRIMIR "\n[4] Nova temperatura alta (sem alarme agora):"
    disparar_evento(ger, EVENTO_TEMPERATURA_ALTA, 
                   50.0, "Data Center")
    
    liberar_gerenciador(ger)
FIM
```

**Aprendizados:**
- Observer Pattern: desacoplar emissor de evento de receptores
- Múltiplos callbacks podem responder a um único evento
- Sistema de eventos é base de arquiteturas event-driven
- Array de ponteiros de função permite "polimorfismo múltiplo"
- Pattern usado em GUI frameworks (Qt signals/slots, JavaScript events)

---
