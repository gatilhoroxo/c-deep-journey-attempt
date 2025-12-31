
## 🔶 Nível 2: Ponteiros para Ponteiros

> **Objetivo Pedagógico:** Dominar alocação dinâmica bidimensional, manipulação de arrays de strings e modificação de ponteiros via referência.

---

### 🎮 Exercício 2.1: Sistema de Mapa de Jogo (Matriz Dinâmica)
**Conceito:** Alocação e manipulação de matrizes 2D com `int**`

**Contexto:**  
Você está criando o sistema de mapa para um jogo estilo roguelike. O mapa é uma grade onde cada célula contém um código representando o tipo de terreno. O tamanho do mapa é definido em tempo de execução (diferentes níveis têm tamanhos diferentes).

**Especificação:**
```c
// Códigos de terreno
#define VAZIO 0
#define PAREDE 1
#define JOGADOR 2
#define TESOURO 3
#define INIMIGO 4

FUNÇÃO criar_mapa(inteiro altura, inteiro largura):
    // Alocar matriz dinâmica usando int**
    // Processo:
    //   1. Alocar array de ponteiros (linhas): malloc(altura * sizeof(int*))
    //   2. Para cada linha, alocar array de inteiros: malloc(largura * sizeof(int))
    //   3. Retornar o ponteiro para a matriz
    // IMPORTANTE: Inicializar tudo com VAZIO (0)
FIM

FUNÇÃO gerar_mapa_aleatorio(int** mapa, inteiro altura, inteiro largura):
    // Preencher o mapa com elementos aleatórios
    // Bordas devem ser PAREDE
    // Interior: 70% VAZIO, 20% PAREDE, 5% TESOURO, 5% INIMIGO
    // Colocar JOGADOR em posição aleatória não-parede
FIM

FUNÇÃO imprimir_mapa(int** mapa, inteiro altura, inteiro largura):
    // Imprimir mapa em formato visual
    // Use caracteres: . (vazio), # (parede), @ (jogador), $ (tesouro), M (inimigo)
    // Exemplo:
    //   ######### 
    //   #...#...$#
    //   #.@...M..#
    //   #...#....#
    //   #########
FIM

FUNÇÃO contar_elemento(int** mapa, inteiro altura, inteiro largura, inteiro tipo):
    // Contar quantas células contêm determinado tipo
    // Útil para verificar quantos tesouros/inimigos existem
FIM

FUNÇÃO liberar_mapa(int** mapa, inteiro altura):
    // Liberar TODA memória alocada
    // IMPORTANTE: Ordem correta!
    //   1. Liberar cada linha (for loop)
    //   2. Depois liberar o array de ponteiros
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    srand(time(NULL))  // Seed para números aleatórios
    
    // Criar mapa pequeno para teste
    altura = 10
    largura = 15
    
    IMPRIMIR "=== Criando Mapa", altura, "x", largura, "==="
    mapa = criar_mapa(altura, largura)
    
    SE mapa == NULL:
        IMPRIMIR "Erro ao alocar mapa!"
        retornar 1
    
    gerar_mapa_aleatorio(mapa, altura, largura)
    
    IMPRIMIR "\nMapa gerado:"
    imprimir_mapa(mapa, altura, largura)
    
    // Estatísticas
    IMPRIMIR "\n=== Estatísticas do Mapa ==="
    IMPRIMIR "Tesouros:", contar_elemento(mapa, altura, largura, TESOURO)
    IMPRIMIR "Inimigos:", contar_elemento(mapa, altura, largura, INIMIGO)
    IMPRIMIR "Paredes:", contar_elemento(mapa, altura, largura, PAREDE)
    
    liberar_mapa(mapa, altura)
    IMPRIMIR "\nMemória liberada com sucesso!"
FIM
```

**Aprendizados:**
- Matriz dinâmica é "array de arrays" - `int**` aponta para array de `int*`
- Alocação em dois níveis: primeiro as linhas, depois cada linha
- Liberação deve ser na ordem inversa da alocação
- `mapa[i][j]` é açúcar sintático para `*(*(mapa + i) + j)`

---

### 📝 Exercício 2.2: Processador de Comandos (Tokenização de Strings)
**Conceito:** Manipulação de arrays de strings (`char**`)

**Contexto:**  
Você está desenvolvendo um shell simples (terminal) que precisa dividir comandos digitados pelo usuário em palavras separadas. Por exemplo, o comando `"ls -la /home/user"` precisa ser dividido em `["ls", "-la", "/home/user"]`.

**Especificação:**
```c
FUNÇÃO contar_palavras(const char* texto):
    // Contar quantas palavras existem no texto
    // Palavra = sequência de caracteres não-espaço
    // Exemplo: "  hello   world  " -> 2 palavras
    // Dica: Use isspace() ou verifique ' ', '\t', '\n'
FIM

FUNÇÃO dividir_comando(const char* comando):
    // Dividir comando em array de strings
    // Retornar char** (array de ponteiros para string)
    // 
    // Processo:
    //   1. Contar número de palavras
    //   2. Alocar array de ponteiros: malloc((n_palavras + 1) * sizeof(char*))
    //      +1 para o NULL no final (convenção de argv)
    //   3. Para cada palavra:
    //      - Calcular tamanho da palavra
    //      - Alocar espaço: malloc(tamanho + 1) para o '\0'
    //      - Copiar palavra usando strncpy
    //   4. Última posição = NULL
    // 
    // IMPORTANTE: NÃO modificar a string original (use const char*)
FIM

FUNÇÃO imprimir_tokens(char** tokens):
    // Imprimir cada token em uma linha
    // Parar quando encontrar NULL
    // Formato: [0]: "palavra1"
    //          [1]: "palavra2"
FIM

FUNÇÃO liberar_tokens(char** tokens):
    // Liberar toda memória alocada
    // Processo:
    //   1. Liberar cada string (loop até NULL)
    //   2. Liberar o array de ponteiros
FIM

FUNÇÃO executar_comando_mock(char** args):
    // Simular execução de comando
    // Apenas imprimir o que seria executado
    // Exemplo: "Executando: ls com argumentos: -la /home"
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    // Teste 1: Comando simples
    IMPRIMIR "=== Teste 1: Comando Simples ==="
    comando1 = "ls -la"
    tokens1 = dividir_comando(comando1)
    imprimir_tokens(tokens1)
    liberar_tokens(tokens1)
    
    // Teste 2: Comando com múltiplos espaços
    IMPRIMIR "\n=== Teste 2: Espaços Extras ==="
    comando2 = "  grep   -r   'pattern'   /home/user  "
    tokens2 = dividir_comando(comando2)
    imprimir_tokens(tokens2)
    executar_comando_mock(tokens2)
    liberar_tokens(tokens2)
    
    // Teste 3: Comando longo
    IMPRIMIR "\n=== Teste 3: Pipeline Complexo ==="
    comando3 = "find . -name '*.c' -type f"
    tokens3 = dividir_comando(comando3)
    IMPRIMIR "Número de tokens:", contar_palavras(comando3)
    imprimir_tokens(tokens3)
    liberar_tokens(tokens3)
    
    // Teste 4: Verificar memory leaks com valgrind
    IMPRIMIR "\n=== Execute com: valgrind ./programa ==="
FIM
```

**Aprendizados:**
- `char**` é array de strings (cada string é `char*`)
- Convenção: último elemento = NULL (estilo `argv`)
- Alocação em dois níveis: array de ponteiros + cada string
- Importante: preservar string original (const char*)
- Tokenização é base de parsers e interpretadores

---

### 📈 Exercício 2.3: Sistema de Lista Dinâmica com Redimensionamento
**Conceito:** Modificar ponteiro original via ponteiro para ponteiro

**Contexto:**  
Você está implementando um sistema de monitoramento de rede que coleta IPs de dispositivos conectados. A lista de IPs precisa crescer dinamicamente conforme novos dispositivos se conectam.

**Especificação:**
```c
ESTRUTURA ListaIPs:
    int* ips           // Array de IPs (representados como int)
    int capacidade     // Capacidade atual do array
    int tamanho        // Número de elementos em uso
FIM

FUNÇÃO criar_lista(int capacidade_inicial):
    // Criar e retornar ListaIPs*
    // Alocar estrutura e array interno
    // Inicializar tamanho = 0
FIM

FUNÇÃO adicionar_ip(ListaIPs* lista, int ip):
    // Adicionar IP à lista
    // SE tamanho == capacidade:
    //     redimensionar para capacidade * 2
    // Adicionar novo IP
    // Incrementar tamanho
FIM

FUNÇÃO redimensionar_lista(int** array, int* capacidade_atual, int nova_capacidade):
    // Redimensionar array apontado por *array
    // Usar realloc OU malloc+memcpy+free
    // Atualizar *capacidade_atual
    // 
    // IMPORTANTE: Modificar o ponteiro original!
    // Por isso precisamos de int** (ponteiro para ponteiro)
    // 
    // Processo com realloc:
    //   novo = realloc(*array, nova_capacidade * sizeof(int))
    //   SE novo != NULL:
    //       *array = novo
    //       *capacidade_atual = nova_capacidade
FIM

FUNÇÃO remover_ip(ListaIPs* lista, int indice):
    // Remover IP no índice especificado
    // Deslocar elementos subsequentes para a esquerda
    // Decrementar tamanho
    // OPCIONAL: Reduzir capacidade se tamanho < capacidade/4
FIM

FUNÇÃO imprimir_lista(ListaIPs* lista):
    // Imprimir todos os IPs
    // Formato: 192.168.1.100 (usando conversão de int para IP)
    // Mostrar também: Tamanho: X, Capacidade: Y
FIM

FUNÇÃO liberar_lista(ListaIPs* lista):
    // Liberar array interno e depois a estrutura
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    IMPRIMIR "=== Sistema de Monitoramento de Rede ==="
    
    // Criar lista pequena para testar redimensionamento
    lista = criar_lista(2)
    
    IMPRIMIR "\nAdicionando IPs..."
    adicionar_ip(lista, 0xC0A80101)  // 192.168.1.1
    IMPRIMIR "Capacidade:", lista->capacidade, "Tamanho:", lista->tamanho
    
    adicionar_ip(lista, 0xC0A80102)  // 192.168.1.2
    IMPRIMIR "Capacidade:", lista->capacidade, "Tamanho:", lista->tamanho
    
    adicionar_ip(lista, 0xC0A80103)  // Deve redimensionar!
    IMPRIMIR "Capacidade após redimensionamento:", lista->capacidade
    
    adicionar_ip(lista, 0xC0A80104)
    adicionar_ip(lista, 0xC0A80105)  // Outro redimensionamento
    
    IMPRIMIR "\nLista final:"
    imprimir_lista(lista)
    
    IMPRIMIR "\nRemovendo IP no índice 1..."
    remover_ip(lista, 1)
    imprimir_lista(lista)
    
    liberar_lista(lista)
    IMPRIMIR "\nMemória liberada!"
FIM
```

**Aprendizados:**
- Ponteiro para ponteiro (`int**`) permite modificar ponteiro original
- `realloc` pode mover memória - nunca assuma que endereço permanece igual
- Estratégia de redimensionamento: dobrar capacidade (amortização O(1))
- Pattern comum: estrutura com ponteiro interno + metadados (capacidade/tamanho)
- Sempre verificar retorno de `malloc`/`realloc` (pode ser NULL)

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
