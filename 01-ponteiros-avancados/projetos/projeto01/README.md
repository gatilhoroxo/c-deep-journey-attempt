
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

### Estrutura de Dados

```c
typedef struct {
    char **linhas;        // Array dinâmico de strings
    int num_linhas;       // Número atual de linhas
    int capacidade;       // Capacidade atual do array
} EditorTexto;
```

### Requisitos Técnicos

1. **Redimensionamento Automático**
   - Dobrar capacidade quando cheia
   - Reduzir capacidade quando 75% vazia

2. **Gerenciamento de Memória**
   - Sem memory leaks
   - Liberar memória antiga ao redimensionar
   - Validar todas alocações

3. **Manipulação de Strings**
   - Usar apenas ponteiros (evitar strcpy direto)
   - Implementar suas próprias funções auxiliares

### Desafios Extras

- [ ] Implementar UNDO/REDO usando pilha
- [ ] Suporte a múltiplos buffers (abas)
- [ ] Syntax highlighting básico (colorir números, strings)
- [ ] Modo de busca com regex simplificado

### Teste

```bash
./editor
> insert 0 One Piece é incrível
> insert 1 Programar em C é poder
> show
0: One Piece é incrível
1: Programar em C é poder
> find Piece
Encontrado na linha 0
> save documento.txt
Arquivo salvo!
```
