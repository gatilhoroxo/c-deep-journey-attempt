# 🚀 Projetos Práticos - Ponteiros Avançados

> *"Grandes projetos formam grandes programadores!"*

## Estrutura dos Projetos

Cada projeto deve ter:
- `README.md` - Descrição e instruções
- `src/` - Código fonte
- `tests/` - Testes
- `Makefile` - Build automation
- `docs/` - Documentação adicional

---

## 🎮 Projeto 1: Editor de Texto em Memória

**Nível:** Intermediário  
**Conceitos:** Ponteiros para ponteiros, alocação dinâmica, manipulação de strings  
**Tempo estimado:** 4-6 horas

### Descrição

Implementar um editor de texto simples que mantém linhas em memória usando array dinâmico de strings.

### Funcionalidades

```
Comandos:
- insert <linha> <texto>  : Inserir texto em uma linha
- delete <linha>          : Deletar uma linha
- show                    : Mostrar todas as linhas
- save <arquivo>          : Salvar em arquivo
- load <arquivo>          : Carregar de arquivo
- find <texto>            : Buscar texto
- replace <old> <new>     : Substituir texto
- quit                    : Sair
```

---

## 🎯 Projeto 2: Gerenciador de Tarefas com Callbacks

**Nível:** Intermediário  
**Conceitos:** Ponteiros de função, callbacks, event system  
**Tempo estimado:** 5-7 horas

### Descrição

Sistema de gerenciamento de tarefas com prioridades e sistema de notificações usando callbacks.

### Funcionalidades

1. **CRUD de Tarefas**
   - Criar, ler, atualizar, deletar
   - Listar por prioridade/status
   - Buscar por ID ou título

2. **Sistema de Notificações**
   - Registrar callbacks para eventos
   - Notificar quando tarefa muda de status
   - Alertar quando prazo está próximo
   - Log de todas as operações

3. **Ordenação e Filtros**
   - Ordenar por prioridade (usar ponteiro de função)
   - Ordenar por data
   - Filtrar por múltiplos critérios

---

## 🎲 Projeto 3: Alocador de Memória Customizado

**Nível:** Avançado  
**Conceitos:** Ponteiros avançados, gerenciamento de memória, algoritmos  
**Tempo estimado:** 8-12 horas

### Descrição

Implementar um sistema de alocação de memória similar ao malloc/free, com estatísticas e debugging.

### Estrutura de Dados

```c
typedef struct BlocoMemoria {
    size_t tamanho;
    int livre;
    struct BlocoMemoria *proximo;
    struct BlocoMemoria *anterior;
    char dados[1];  // Flexible array member
} BlocoMemoria;

typedef struct {
    BlocoMemoria *cabeca;
    size_t total_alocado;
    size_t total_livre;
    size_t num_blocos;
    size_t num_fragmentos;
} GerenciadorMemoria;
```

### Funcionalidades

1. **Alocação**
   ```c
   void* mem_alloc(size_t tamanho);
   void* mem_calloc(size_t num, size_t tamanho);
   void* mem_realloc(void *ptr, size_t novo_tamanho);
   void mem_free(void *ptr);
   ```

2. **Estratégias de Alocação**
   - First Fit (primeira região que cabe)
   - Best Fit (menor região que cabe)
   - Worst Fit (maior região)
   - Comparar performance

3. **Otimizações**
   - Coalescing (juntar blocos livres adjacentes)
   - Splitting (dividir blocos grandes)
   - Boundary tags

4. **Debugging**
   ```c
   void mem_dump();              // Visualizar memória
   void mem_stats();             // Estatísticas
   int mem_check_leaks();        // Detectar vazamentos
   void mem_validate(void *ptr); // Validar ponteiro
   ```

### Algoritmos a Implementar

1. **First Fit**
   ```
   PARA cada bloco na lista:
       SE bloco.livre E bloco.tamanho >= tamanho_requisitado:
           retornar este bloco
   ```

2. **Best Fit**
   ```
   melhor = NULL
   PARA cada bloco na lista:
       SE bloco.livre E bloco.tamanho >= tamanho_requisitado:
           SE melhor == NULL OU bloco.tamanho < melhor.tamanho:
               melhor = bloco
   retornar melhor
   ```

3. **Coalescing**
   ```
   Quando liberar bloco:
       SE proximo está livre:
           juntar com próximo
       SE anterior está livre:
           juntar com anterior
   ```

### Requisitos Técnicos

1. **Pool de Memória**
   ```c
   #define POOL_SIZE (1024 * 1024)  // 1MB
   static char memory_pool[POOL_SIZE];
   ```

2. **Magic Numbers**
   - Detectar corrupção de memória
   - Guardar assinatura antes/depois do bloco

3. **Alinhamento**
   - Garantir alinhamento correto (8 bytes)
   - Usar operações bit a bit

### Desafios Extras

- [ ] Implementar buddy allocation
- [ ] Suporte a multithreading (locks)
- [ ] Compactação de memória (garbage collection)
- [ ] Profiling (quais tamanhos são mais alocados)
- [ ] Exportar métricas para gráficos

### Teste de Performance

```c
// Comparar com malloc do sistema
void benchmark() {
    clock_t inicio, fim;
    
    // Teste 1: Muitas alocações pequenas
    inicio = clock();
    for (int i = 0; i < 10000; i++) {
        void *p = mem_alloc(32);
        mem_free(p);
    }
    fim = clock();
    
    // Teste 2: Alocações variadas
    // Teste 3: Fragmentação
    // ...
}
```

---

## 🎨 Projeto 4: Sistema de Plugins Dinâmicos

**Nível:** Avançado  
**Conceitos:** Ponteiros de função, dlopen/dlsym, modularidade  
**Tempo estimado:** 6-10 horas

### Descrição

Sistema que carrega plugins dinamicamente em runtime usando shared libraries.

### Arquitetura

```
aplicacao_principal
    ├── plugin_interface.h
    ├── plugin_loader.c
    └── plugins/
        ├── plugin_log.so
        ├── plugin_calc.so
        └── plugin_game.so
```

### Interface de Plugin

```c
// plugin_interface.h
typedef struct {
    const char *nome;
    const char *versao;
    const char *autor;
    
    int (*inicializar)(void);
    int (*executar)(int argc, char **argv);
    void (*finalizar)(void);
    const char* (*ajuda)(void);
} Plugin;

// Cada plugin deve exportar esta função
Plugin* plugin_create(void);
```

### Sistema Loader

```c
typedef struct {
    void *handle;           // dlopen handle
    Plugin *plugin;
    char *caminho;
    int ativo;
} PluginCarregado;

typedef struct {
    PluginCarregado **plugins;
    int num_plugins;
    int capacidade;
} GerenciadorPlugins;

// Funções principais
int carregar_plugin(GerenciadorPlugins *gm, const char *caminho);
int descarregar_plugin(GerenciadorPlugins *gm, const char *nome);
Plugin* obter_plugin(GerenciadorPlugins *gm, const char *nome);
void listar_plugins(GerenciadorPlugins *gm);
```

### Exemplo de Plugin

```c
// plugin_log.c
#include "plugin_interface.h"

static int log_init(void) {
    printf("Plugin Log inicializado\n");
    return 0;
}

static int log_run(int argc, char **argv) {
    if (argc < 2) {
        printf("Uso: log <mensagem>\n");
        return 1;
    }
    
    FILE *f = fopen("app.log", "a");
    fprintf(f, "[%ld] %s\n", time(NULL), argv[1]);
    fclose(f);
    return 0;
}

static void log_cleanup(void) {
    printf("Plugin Log finalizado\n");
}

static const char* log_help(void) {
    return "Plugin de logging - Uso: log <mensagem>";
}

Plugin* plugin_create(void) {
    static Plugin p = {
        .nome = "log",
        .versao = "1.0",
        .autor = "Seu Nome",
        .inicializar = log_init,
        .executar = log_run,
        .finalizar = log_cleanup,
        .ajuda = log_help
    };
    return &p;
}
```

### Funcionalidades

1. **Carregamento Dinâmico**
   - Usar dlopen/dlsym (Linux) ou LoadLibrary (Windows)
   - Tratar erros de carregamento
   - Validar interface do plugin

2. **Gerenciamento**
   - Listar plugins disponíveis
   - Carregar/descarregar em runtime
   - Verificar dependências

3. **Comunicação**
   - Passar dados entre aplicação e plugins
   - Sistema de mensagens
   - Callbacks entre plugins

### Requisitos Técnicos

1. **Compilação de Plugins**
   ```makefile
   plugin_%.so: plugins/plugin_%.c
       gcc -shared -fPIC -o $@ $<
   ```

2. **Carregamento Seguro**
   ```c
   void *handle = dlopen(caminho, RTLD_LAZY);
   if (!handle) {
       fprintf(stderr, "Erro: %s\n", dlerror());
       return -1;
   }
   
   Plugin* (*create)(void) = dlsym(handle, "plugin_create");
   ```

3. **Versionamento**
   - Verificar versão da interface
   - Compatibilidade entre plugins

### Desafios Extras

- [ ] Hot-reload (recarregar sem reiniciar)
- [ ] Sandboxing de plugins (segurança)
- [ ] Dependências entre plugins
- [ ] Plugin marketplace (baixar novos plugins)
- [ ] Interface gráfica para gerenciar plugins

---

## 🕹️ Projeto 5: Motor de Jogo Simples 2D

**Nível:** Avançado  
**Conceitos:** Todos os conceitos de ponteiros, otimização  
**Tempo estimado:** 15-20 horas

### Descrição

Motor de jogo 2D com sistema de entidades, callbacks para eventos, e gerenciamento eficiente de memória.

### Arquitetura ECS (Entity Component System)

```c
// Entidade
typedef struct {
    int id;
    int ativo;
    void **componentes;  // Array de ponteiros void*
    int num_componentes;
} Entidade;

// Componentes
typedef struct {
    float x, y;
} ComponentePosicao;

typedef struct {
    float vx, vy;
} ComponenteVelocidade;

typedef struct {
    char sprite[64];
    int largura, altura;
} ComponenteSprite;

typedef struct {
    void (*callback)(Entidade*, void*);
} ComponenteScript;

// Sistema
typedef void (*SistemaUpdate)(Entidade**, int, float);

typedef struct {
    SistemaUpdate update;
    const char *nome;
} Sistema;
```

### Sistemas a Implementar

1. **Sistema de Movimento**
   ```c
   void sistema_movimento_update(Entidade **entidades, int n, float dt) {
       for (int i = 0; i < n; i++) {
           ComponentePosicao *pos = obter_componente(entidades[i], COMP_POSICAO);
           ComponenteVelocidade *vel = obter_componente(entidades[i], COMP_VELOCIDADE);
           
           if (pos && vel) {
               pos->x += vel->vx * dt;
               pos->y += vel->vy * dt;
           }
       }
   }
   ```

2. **Sistema de Colisão**
   - Broad phase (grid spatial partitioning)
   - Narrow phase (AABB collision)
   - Resolução de colisões

3. **Sistema de Renderização**
   - Ordenar sprites por profundidade
   - Culling (não renderizar fora da tela)
   - Usar ponteiros de função para diferentes renderizadores

4. **Sistema de Input**
   - Callbacks para teclas
   - Mouse tracking
   - Gamepad support (opcional)

### Funcionalidades do Motor

1. **Gerenciamento de Entidades**
   ```c
   Entidade* criar_entidade();
   void destruir_entidade(Entidade *e);
   void adicionar_componente(Entidade *e, int tipo, void *dados);
   void* obter_componente(Entidade *e, int tipo);
   ```

2. **Game Loop**
   ```c
   while (rodando) {
       float dt = calcular_delta_time();
       
       processar_input();
       
       for (int i = 0; i < num_sistemas; i++) {
           sistemas[i].update(entidades, num_entidades, dt);
       }
       
       renderizar();
   }
   ```

3. **Pool de Objetos**
   - Pré-alocar entidades
   - Reutilizar ao invés de criar/destruir
   - Cache-friendly (arrays contíguos)

### Jogo de Exemplo: Snake

```c
void criar_jogo_snake() {
    // Criar cobra
    Entidade *cabeca = criar_entidade();
    adicionar_componente(cabeca, COMP_POSICAO, &(ComponentePosicao){10, 10});
    adicionar_componente(cabeca, COMP_VELOCIDADE, &(ComponenteVelocidade){1, 0});
    adicionar_componente(cabeca, COMP_SPRITE, &(ComponenteSprite){"snake_head", 16, 16});
    
    // Criar comida
    Entidade *comida = criar_entidade();
    adicionar_componente(comida, COMP_POSICAO, posicao_aleatoria());
    adicionar_componente(comida, COMP_SPRITE, &(ComponenteSprite){"food", 16, 16});
    
    // Script de colisão
    adicionar_componente(cabeca, COMP_SCRIPT, criar_script(on_comer_comida));
}
```

### Otimizações

1. **Cache Locality**
   - Componentes do mesmo tipo em arrays contíguos
   - Reduzir cache misses

2. **Object Pooling**
   - Pool de entidades
   - Pool de componentes

3. **Spatial Partitioning**
   - Grid para colisões
   - Quadtree (opcional)

### Desafios Extras

- [ ] Editor de níveis
- [ ] Sistema de partículas
- [ ] Animações sprite
- [ ] Audio system (callbacks para efeitos)
- [ ] Serialização de cenas (salvar/carregar)
- [ ] Profiler integrado (medir performance de cada sistema)

---

## 📊 Projeto Bônus: Benchmark Suite

**Nível:** Intermediário  
**Conceitos:** Medição de performance, otimização  
**Tempo estimado:** 4-6 horas

### Descrição

Suite de benchmarks para comparar diferentes implementações de algoritmos usando ponteiros.

### Testes a Implementar

1. **Acesso a Array**
   ```c
   // Via índice
   for (int i = 0; i < n; i++)
       soma += arr[i];
   
   // Via ponteiro
   int *p = arr;
   for (int i = 0; i < n; i++)
       soma += *p++;
   
   // Via ponteiro com limite
   int *end = arr + n;
   for (int *p = arr; p < end; p++)
       soma += *p;
   ```

2. **Ordenação**
   - Comparar diferentes algoritmos
   - Comparar ponteiros de função vs if/else

3. **Alocação de Memória**
   - malloc vs pool allocation
   - Stack vs heap

4. **Cache Performance**
   - Row-major vs column-major
   - Struct of arrays vs array of structs

### Estrutura

```c
typedef struct {
    const char *nome;
    void (*funcao)(void);
    double tempo_medio;
    int repeticoes;
} Benchmark;

void executar_benchmark(Benchmark *b) {
    clock_t inicio = clock();
    for (int i = 0; i < b->repeticoes; i++) {
        b->funcao();
    }
    clock_t fim = clock();
    b->tempo_medio = (double)(fim - inicio) / CLOCKS_PER_SEC / b->repeticoes;
}
```

### Visualização

- Gerar CSV com resultados
- Script Python para gráficos
- Comparar com diferentes flags de compilação

---
