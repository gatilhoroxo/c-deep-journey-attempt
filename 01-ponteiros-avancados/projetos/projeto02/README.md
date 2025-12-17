
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

### Estrutura de Dados

```c
typedef enum {
    BAIXA,
    MEDIA,
    ALTA,
    URGENTE
} Prioridade;

typedef enum {
    PENDENTE,
    EM_PROGRESSO,
    CONCLUIDA,
    CANCELADA
} Status;

typedef void (*NotificacaoCallback)(const char *mensagem, void *dados);

typedef struct Tarefa {
    int id;
    char *titulo;
    char *descricao;
    Prioridade prioridade;
    Status status;
    time_t criada_em;
    time_t prazo;
    struct Tarefa *proxima;
} Tarefa;

typedef struct {
    Tarefa *cabeca;
    NotificacaoCallback callbacks[10];
    int num_callbacks;
} GerenciadorTarefas;
```

### Requisitos Técnicos

1. **Callbacks Tipados**
   ```c
   void on_tarefa_criada(const char *msg, void *dados);
   void on_tarefa_concluida(const char *msg, void *dados);
   void on_prazo_proximo(const char *msg, void *dados);
   ```

2. **Ordenação Genérica**
   ```c
   typedef int (*ComparadorTarefa)(const Tarefa*, const Tarefa*);
   void ordenar_tarefas(Tarefa **lista, ComparadorTarefa comp);
   ```

3. **Persistência**
   - Salvar/carregar de arquivo
   - Formato: JSON simplificado ou binário

### Desafios Extras

- [ ] Sistema de tags para tarefas
- [ ] Subtarefas (árvore de tarefas)
- [ ] Estatísticas (tarefas concluídas por dia/semana)
- [ ] Interface colorida no terminal (ANSI codes)
