
## 🔷 Nível 5: Desafios Avançados - Integração Total

> **Objetivo Pedagógico:** Integrar todos os conceitos aprendidos em projetos complexos e realistas que simulam sistemas reais.

---

### 💾 Exercício 5.1: Mini-Alocador de Memória (Custom Memory Allocator)
**Conceito:** Implementar `malloc` e `free` simplificados

**Contexto:**  
Você está desenvolvendo um sistema embarcado com memória limitada e quer controle total sobre alocações. Vai implementar seu próprio gerenciador de memória usando técnicas de sistemas operacionais reais. Este exercício combina ponteiros, listas ligadas, e gerenciamento de memória.

**Especificação:**
```c
#define POOL_SIZE 65536  // 64 KB de memória gerenciada

// Metadados de cada bloco alocado
typedef struct Bloco {
    size_t tamanho;          // Tamanho do bloco (sem incluir metadados)
    int livre;               // 1 = livre, 0 = ocupado
    struct Bloco* proximo;   // Próximo bloco na lista
    struct Bloco* anterior;  // Bloco anterior (lista duplamente ligada)
} Bloco;

// Estado global do alocador
typedef struct {
    unsigned char pool[POOL_SIZE];  // Pool de memória
    Bloco* head;                     // Início da lista de blocos
    size_t total_alocado;            // Total de bytes alocados
    size_t num_blocos;               // Número de blocos na lista
    size_t fragmentacao;             // Métrica de fragmentação
} Alocador;

GLOBAL Alocador alocador_global;

FUNÇÃO inicializar_alocador():
    // Inicializar pool de memória
    // Criar primeiro bloco livre ocupando todo o pool
    // 
    // Estrutura inicial:
    //   [Metadados_Bloco][Espaço_Livre...]
    //
    alocador_global.head = (Bloco*)alocador_global.pool
    alocador_global.head->tamanho = POOL_SIZE - sizeof(Bloco)
    alocador_global.head->livre = 1
    alocador_global.head->proximo = NULL
    alocador_global.head->anterior = NULL
FIM

FUNÇÃO meu_malloc(size_t tamanho):
    // 1. Arredondar tamanho para alinhamento (múltiplo de 8)
    size_t tamanho_alinhado = (tamanho + 7) & ~7
    
    // 2. Procurar bloco livre com first-fit, best-fit ou worst-fit
    Bloco* bloco = encontrar_bloco_livre(tamanho_alinhado)
    
    SE bloco == NULL:
        IMPRIMIR "Erro: Sem memória disponível!"
        retornar NULL
    
    // 3. SE bloco é muito maior, dividir (split)
    SE bloco->tamanho >= tamanho_alinhado + sizeof(Bloco) + 16:
        dividir_bloco(bloco, tamanho_alinhado)
    
    // 4. Marcar bloco como ocupado
    bloco->livre = 0
    alocador_global.total_alocado += bloco->tamanho
    
    // 5. Retornar ponteiro para área de dados (após metadados)
    retornar (void*)(bloco + 1)
FIM

FUNÇÃO encontrar_bloco_livre(size_t tamanho):
    // Implementar estratégia de busca:
    // - First Fit: Primeiro bloco que cabe
    // - Best Fit: Menor bloco que cabe (menos desperdício)
    // - Worst Fit: Maior bloco (menos fragmentação)
    
    Bloco* atual = alocador_global.head
    Bloco* melhor = NULL
    
    ENQUANTO atual != NULL:
        SE atual->livre E atual->tamanho >= tamanho:
            // First fit: retornar imediatamente
            // Best fit: guardar se menor que melhor anterior
            SE melhor == NULL OU atual->tamanho < melhor->tamanho:
                melhor = atual
        atual = atual->proximo
    
    retornar melhor
FIM

FUNÇÃO dividir_bloco(Bloco* bloco, size_t tamanho):
    // Dividir bloco em dois:
    //   1. Bloco ocupado de tamanho 'tamanho'
    //   2. Novo bloco livre com o resto
    //
    // [Bloco_A_Usado][Dados_A...][Bloco_B_Livre][Dados_B...]
    
    // Calcular posição do novo bloco
    Bloco* novo_bloco = (Bloco*)((char*)(bloco + 1) + tamanho)
    
    // Configurar novo bloco
    novo_bloco->tamanho = bloco->tamanho - tamanho - sizeof(Bloco)
    novo_bloco->livre = 1
    novo_bloco->proximo = bloco->proximo
    novo_bloco->anterior = bloco
    
    // Atualizar bloco original
    bloco->tamanho = tamanho
    bloco->proximo = novo_bloco
    
    // Atualizar lista ligada
    SE novo_bloco->proximo != NULL:
        novo_bloco->proximo->anterior = novo_bloco
    
    alocador_global.num_blocos++
FIM

FUNÇÃO meu_free(void* ptr):
    SE ptr == NULL:
        retornar
    
    // 1. Obter metadados (bloco está antes do ptr)
    Bloco* bloco = ((Bloco*)ptr) - 1
    
    // 2. Validar que ponteiro está dentro do pool
    SE NÃO validar_ponteiro(bloco):
        IMPRIMIR "Erro: Ponteiro inválido!"
        retornar
    
    // 3. Marcar como livre
    bloco->livre = 1
    alocador_global.total_alocado -= bloco->tamanho
    
    // 4. Coalescer (juntar) com blocos adjacentes livres
    coalescer(bloco)
FIM

FUNÇÃO coalescer(Bloco* bloco):
    // Juntar blocos livres adjacentes para reduzir fragmentação
    
    // Tentar juntar com próximo
    SE bloco->proximo != NULL E bloco->proximo->livre:
        bloco->tamanho += sizeof(Bloco) + bloco->proximo->tamanho
        bloco->proximo = bloco->proximo->proximo
        
        SE bloco->proximo != NULL:
            bloco->proximo->anterior = bloco
        
        alocador_global.num_blocos--
    
    // Tentar juntar com anterior
    SE bloco->anterior != NULL E bloco->anterior->livre:
        bloco->anterior->tamanho += sizeof(Bloco) + bloco->tamanho
        bloco->anterior->proximo = bloco->proximo
        
        SE bloco->proximo != NULL:
            bloco->proximo->anterior = bloco->anterior
        
        alocador_global.num_blocos--
FIM

FUNÇÃO visualizar_memoria():
    // Criar representação visual do estado da memória
    IMPRIMIR "\n╔══════════════ ESTADO DA MEMÓRIA ══════════════╗"
    IMPRIMIR "Total alocado:", alocador_global.total_alocado, "bytes"
    IMPRIMIR "Número de blocos:", alocador_global.num_blocos
    
    Bloco* atual = alocador_global.head
    int num = 0
    
    ENQUANTO atual != NULL:
        char status = atual->livre ? 'L' : 'O'  // Livre/Ocupado
        IMPRIMIR "[Bloco", num, "]", status, 
                 "- Tamanho:", atual->tamanho, "bytes"
        atual = atual->proximo
        num++
    
    IMPRIMIR "╚═══════════════════════════════════════════════╝\n"
FIM

FUNÇÃO calcular_fragmentacao():
    // Calcular fragmentação externa
    // Frag = (maior_bloco_livre) / (total_livre)
    // Valores próximos a 1 = pouca fragmentação
    // Valores baixos = muita fragmentação
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    IMPRIMIR "╔════════════════════════════════════════════╗"
    IMPRIMIR "║    MINI-ALOCADOR DE MEMÓRIA                ║"
    IMPRIMIR "╚════════════════════════════════════════════╝\n"
    
    inicializar_alocador()
    visualizar_memoria()
    
    // Teste 1: Alocações simples
    IMPRIMIR "=== Teste 1: Alocações Simples ==="
    int* arr1 = (int*)meu_malloc(10 * sizeof(int))
    char* str1 = (char*)meu_malloc(50)
    double* vals = (double*)meu_malloc(5 * sizeof(double))
    visualizar_memoria()
    
    // Teste 2: Liberações e coalescing
    IMPRIMIR "\n=== Teste 2: Liberando str1 (meio) ==="
    meu_free(str1)
    visualizar_memoria()
    
    // Teste 3: Fragmentação
    IMPRIMIR "\n=== Teste 3: Padrão de Fragmentação ==="
    void* ptrs[10]
    PARA i de 0 até 10:
        ptrs[i] = meu_malloc(100)
    
    // Liberar blocos alternados (fragmentação máxima)
    PARA i de 0 até 10 PASSO 2:
        meu_free(ptrs[i])
    
    visualizar_memoria()
    IMPRIMIR "Fragmentação:", calcular_fragmentacao()
    
    // Teste 4: Tentar alocar bloco grande (deve falhar ou consolidar)
    IMPRIMIR "\n=== Teste 4: Alocação Grande ==="
    void* grande = meu_malloc(1000)
    SE grande == NULL:
        IMPRIMIR "Falhou: memória fragmentada!"
    SENÃO:
        IMPRIMIR "Sucesso!"
    
    // Limpar tudo
    PARA i de 1 até 10 PASSO 2:
        meu_free(ptrs[i])
    meu_free(arr1)
    meu_free(vals)
    
    visualizar_memoria()
    IMPRIMIR "\n=== Memória completamente liberada ==="
FIM
```

**Aprendizados:**
- Técnicas de gerenciamento de memória de sistemas operacionais
- Fragmentação externa e estratégias de coalescing
- Metadados de alocação e overhead
- Alinhamento de memória para performance
- First-fit vs Best-fit vs Worst-fit

---

### 🖥️ Exercício 5.2: Shell Interativo com Sistema de Plugins
**Conceito:** Interpretador de comandos com callbacks e extensibilidade

**Contexto:**  
Você vai criar um mini-shell (como bash/zsh) que interpreta comandos e pode ser estendido com novos comandos dinamicamente. Sistema usa ponteiros de função para dispatch de comandos, similar a como shells reais funcionam.

**Especificação:**
```c
#define MAX_ARGS 32
#define MAX_COMANDOS 50

// Tipo para função handler de comando
// Recebe: array de argumentos, número de argumentos
// Retorna: código de status (0 = sucesso, != 0 = erro)
typedef int (*comando_handler)(char** args, int argc);

// Definição de comando
typedef struct {
    char* nome;                 // Nome do comando (ex: "ls", "echo")
    comando_handler handler;    // Função que executa o comando
    char* descricao;            // Descrição para ajuda
    char* uso;                  // Exemplo de uso
} Comando;

// Estado do shell
typedef struct {
    Comando comandos[MAX_COMANDOS];
    int num_comandos;
    int deve_sair;              // Flag para sair do loop
    char* prompt;               // String do prompt
    int ultimo_status;          // Status do último comando
} Shell;

GLOBAL Shell shell_global;

// ========== Comandos Built-in ==========

FUNÇÃO cmd_ajuda(char** args, int argc):
    IMPRIMIR "\n╔═══════════════════════════════════════╗"
    IMPRIMIR "║        COMANDOS DISPONÍVEIS           ║"
    IMPRIMIR "╚═══════════════════════════════════════╝\n"
    
    PARA i de 0 até shell_global.num_comandos:
        Comando* cmd = &shell_global.comandos[i]
        IMPRIMIR cmd->nome
        IMPRIMIR "  ", cmd->descricao
        SE argc > 1 E strcmp(args[1], cmd->nome) == 0:
            IMPRIMIR "  Uso:", cmd->uso
    
    retornar 0
FIM

FUNÇÃO cmd_sair(char** args, int argc):
    IMPRIMIR "Saindo do shell... Até logo!"
    shell_global.deve_sair = 1
    retornar 0
FIM

FUNÇÃO cmd_echo(char** args, int argc):
    // Imprimir todos os argumentos
    PARA i de 1 até argc:
        IMPRIMIR args[i], " "
    IMPRIMIR "\n"
    retornar 0
FIM

FUNÇÃO cmd_calc(char** args, int argc):
    // Mini calculadora: calc 10 + 20
    SE argc < 4:
        IMPRIMIR "Uso: calc <num1> <op> <num2>\n"
        retornar 1
    
    double a = atof(args[1])
    double b = atof(args[3])
    char op = args[2][0]
    double resultado
    
    ESCOLHER op:
        CASO '+': resultado = a + b
        CASO '-': resultado = a - b
        CASO '*': resultado = a * b
        CASO '/': 
            SE b == 0:
                IMPRIMIR "Erro: divisão por zero\n"
                retornar 1
            resultado = a / b
        PADRÃO:
            IMPRIMIR "Operador inválido\n"
            retornar 1
    
    IMPRIMIR resultado, "\n"
    retornar 0
FIM

// ========== Sistema de Gerenciamento ==========

FUNÇÃO inicializar_shell():
    shell_global.num_comandos = 0
    shell_global.deve_sair = 0
    shell_global.prompt = "myshell> "
    shell_global.ultimo_status = 0
    
    // Registrar comandos built-in
    registrar_comando("ajuda", cmd_ajuda, 
                     "Mostra ajuda sobre comandos", 
                     "ajuda [comando]")
    registrar_comando("echo", cmd_echo, 
                     "Imprime argumentos", "echo <texto>")
    registrar_comando("calc", cmd_calc, 
                     "Calculadora simples", "calc 10 + 5")
    registrar_comando("sair", cmd_sair, 
                     "Sai do shell", "sair")
FIM

FUNÇÃO registrar_comando(char* nome, comando_handler handler, 
                        char* descricao, char* uso):
    SE shell_global.num_comandos >= MAX_COMANDOS:
        IMPRIMIR "Erro: tabela de comandos cheia!\n"
        retornar
    
    Comando* cmd = &shell_global.comandos[shell_global.num_comandos]
    cmd->nome = strdup(nome)
    cmd->handler = handler
    cmd->descricao = strdup(descricao)
    cmd->uso = strdup(uso)
    
    shell_global.num_comandos++
FIM

FUNÇÃO executar_comando(char** args, int argc):
    SE argc == 0:
        retornar 0
    
    // Procurar comando na tabela
    PARA i de 0 até shell_global.num_comandos:
        SE strcmp(args[0], shell_global.comandos[i].nome) == 0:
            // Encontrou! Executar handler
            int status = shell_global.comandos[i].handler(args, argc)
            shell_global.ultimo_status = status
            retornar status
    
    // Comando não encontrado
    IMPRIMIR "Comando não encontrado:", args[0], "\n"
    retornar 127
FIM

FUNÇÃO loop_principal():
    char linha[1024]
    
    ENQUANTO NÃO shell_global.deve_sair:
        // Mostrar prompt
        IMPRIMIR shell_global.prompt
        
        // Ler linha e executar
        SE fgets(linha, sizeof(linha), stdin) == NULL:
            INTERROMPER
        
        // Parsear e executar comando
        // (implementação simplificada)
FIM
```

**Aprendizados:**
- Tabela de dispatch com ponteiros de função
- Parsing de comandos e tokenização
- Sistema de plugins extensível
- Pattern usado em shells e interpretadores

---

### 🧩 Exercício 5.3: Sistema de Referência Compartilhada (Smart Pointers)
**Conceito:** Reference counting e gerenciamento automático de memória

**Contexto:**  
Implementar smart pointers estilo C++ (`shared_ptr`) em C puro. Sistema rastreia quantas referências existem para um objeto e libera automaticamente quando não há mais referências.

**Especificação:**
```c
// Definir ponteiro genérico deletor
typedef void (*deletor_fn)(void* data);

// Smart Pointer com contagem de referências
typedef struct {
    void* dados;                // Ponteiro para os dados gerenciados
    int* contador_ref;          // Contador compartilhado de referências
    deletor_fn deletor;         // Função para liberar dados
} SmartPtr;

FUNÇÃO criar_smart_ptr(void* dados, deletor_fn deletor):
    // Alocar estrutura SmartPtr
    SmartPtr* sp = malloc(sizeof(SmartPtr))
    
    // Alocar contador de referências (compartilhado!)
    sp->contador_ref = malloc(sizeof(int))
    *(sp->contador_ref) = 1  // Primeira referência
    
    sp->dados = dados
    sp->deletor = deletor
    
    retornar sp
FIM

FUNÇÃO copiar_smart_ptr(SmartPtr* original):
    // Criar nova referência ao mesmo objeto
    // Incrementar contador compartilhado
    
    SmartPtr* copia = malloc(sizeof(SmartPtr))
    copia->dados = original->dados
    copia->contador_ref = original->contador_ref
    copia->deletor = original->deletor
    
    // Incrementar contador (compartilhado entre todas as cópias!)
    (*(copia->contador_ref))++
    
    retornar copia
FIM

FUNÇÃO liberar_smart_ptr(SmartPtr* sp):
    SE sp == NULL:
        retornar
    
    // Decrementar contador
    (*(sp->contador_ref))--
    
    // SE contador chegou a zero, liberar recursos
    SE *(sp->contador_ref) == 0:
        // Chamar deletor customizado
        SE sp->deletor != NULL:
            sp->deletor(sp->dados)
        
        // Liberar contador
        free(sp->contador_ref)
    
    // Liberar estrutura SmartPtr
    free(sp)
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    // Criar recurso
    Recurso* rec = criar_recurso()
    
    // Envolver em SmartPtr
    SmartPtr* sp1 = criar_smart_ptr(rec, deletor_recurso)
    
    // Criar mais referências
    SmartPtr* sp2 = copiar_smart_ptr(sp1)
    SmartPtr* sp3 = copiar_smart_ptr(sp1)
    // refcount = 3
    
    // Liberar referências gradualmente
    liberar_smart_ptr(sp2)  // refcount = 2
    liberar_smart_ptr(sp3)  // refcount = 1
    liberar_smart_ptr(sp1)  // refcount = 0, dados liberados automaticamente!
FIM
```

**Aprendizados:**
- Reference counting é técnica fundamental de gerenciamento de memória
- Contador compartilhado entre todas as referências
- Deletor customizado permite liberar recursos complexos
- Pattern usado em Objective-C, Python, Rust (Rc/Arc)

---

**🎓 Parabéns por completar o Nível 5!**

Você dominou técnicas usadas em sistemas operacionais e linguagens de programação profissionais!
