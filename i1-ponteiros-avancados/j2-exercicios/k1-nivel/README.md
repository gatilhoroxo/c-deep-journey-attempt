
## 🔰 Nível 1: Fundamentos

> **Objetivo Pedagógico:** Dominar passagem por referência, aritmética de ponteiros e entender o decaimento de arrays para ponteiros.

---

### 📦 Exercício 1.1: Sistema de Inventário de Loja
**Conceito:** Passagem de ponteiros para modificar variáveis

**Contexto:**  
Você está desenvolvendo um sistema para uma loja que precisa trocar produtos entre prateleiras. Quando um produto mais vendido está em uma prateleira menos acessível, o gerente quer trocar as posições dos produtos.

**Especificação:**
```c
FUNÇÃO trocar_produtos(ponteiro para inteiro codigo_a, ponteiro para inteiro codigo_b):
    // Trocar os códigos dos produtos nas prateleiras
    // Implementar usando apenas ponteiros
    // Dica: Você pode usar uma variável temporária int
FIM

FUNÇÃO trocar_sem_temp(ponteiro para inteiro a, ponteiro para inteiro b):
    // DESAFIO: Trocar sem variável temporária
    // Usar operações XOR: x ^= y; y ^= x; x ^= y;
    // CUIDADO: Não funciona se a e b apontam para o mesmo endereço!
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    produto_prateleira_A = 101  // Produto menos vendido
    produto_prateleira_B = 205  // Produto mais vendido
    
    IMPRIMIR "Antes da troca:"
    IMPRIMIR "  Prateleira A (frontal): Produto", produto_prateleira_A
    IMPRIMIR "  Prateleira B (fundos): Produto", produto_prateleira_B
    
    trocar_produtos(&produto_prateleira_A, &produto_prateleira_B)
    
    IMPRIMIR "\nDepois da troca:"
    IMPRIMIR "  Prateleira A (frontal): Produto", produto_prateleira_A
    IMPRIMIR "  Prateleira B (fundos): Produto", produto_prateleira_B
FIM
```

**Aprendizados:**
- Passagem por referência permite modificar variáveis originais
- Ponteiros permitem que funções tenham "efeitos colaterais" controlados
- Diferença entre passar valor (`int x`) e passar referência (`int *x`)

---

### 📊 Exercício 1.2: Analisador de Dados de Sensores
**Conceito:** Arrays, ponteiros e sizeof - entendendo o decaimento

**Contexto:**  
Você está programando um sistema embarcado que coleta dados de sensores de temperatura. O sistema precisa calcular estatísticas sobre as leituras, mas você precisa entender a diferença entre trabalhar com arrays locais e arrays passados para funções.

**Especificação:**
```c
FUNÇÃO calcular_media_local():
    // Criar array local: leituras[] = {20, 22, 19, 23, 21}
    // Calcular tamanho usando: sizeof(leituras) / sizeof(leituras[0])
    // Calcular e retornar a média
    // EXPLICAR: Por que sizeof funciona aqui?
FIM

FUNÇÃO calcular_media_funcao(ponteiro para float leituras, inteiro num_leituras):
    // Receber array de leituras e seu tamanho
    // Calcular e retornar a média
    // EXPLICAR: Por que sizeof(leituras) NÃO funciona aqui?
    // DEMONSTRAR: Imprimir sizeof(leituras) dentro da função
FIM

FUNÇÃO imprimir_info_array():
    leituras[] = {20.5, 22.3, 19.8, 23.1, 21.0}
    
    IMPRIMIR "Array Local:"
    IMPRIMIR "  sizeof(leituras) =", sizeof(leituras)
    IMPRIMIR "  sizeof(leituras[0]) =", sizeof(leituras[0])
    IMPRIMIR "  Número de elementos =", sizeof(leituras)/sizeof(leituras[0])
    
    // Agora passar para outra função
    calcular_media_funcao(leituras, 5)
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    // Teste 1: Array local
    IMPRIMIR "=== Teste com Array Local ==="
    media_local = calcular_media_local()
    IMPRIMIR "Média calculada localmente:", media_local
    
    // Teste 2: Entendendo o decaimento
    IMPRIMIR "\n=== Entendendo Array Decay ==="
    sensores[] = {18.5, 22.0, 20.5, 19.0, 23.5, 21.0}
    num_sensores = sizeof(sensores) / sizeof(sensores[0])
    
    IMPRIMIR "No main, sizeof(sensores) =", sizeof(sensores)
    media = calcular_media_funcao(sensores, num_sensores)
    IMPRIMIR "Média dos sensores:", media
    
    // Teste 3: Demonstração completa
    IMPRIMIR "\n=== Demonstração Completa ==="
    imprimir_info_array()
FIM
```

**Aprendizados:**
- Arrays locais preservam informação de tamanho
- Quando arrays são passados para funções, "decaem" para ponteiros
- `sizeof` em array local retorna bytes totais, em ponteiro retorna tamanho do ponteiro
- Por isso funções precisam receber o tamanho como parâmetro separado

---

### 🔄 Exercício 1.3: Sistema de Reversão de Esteira
**Conceito:** Aritmética de ponteiros e manipulação in-place

**Contexto:**  
Você está programando o controlador de uma esteira transportadora que organiza pacotes. Às vezes é necessário inverter a ordem dos pacotes na esteira sem usar memória extra (a esteira tem espaço limitado). Você precisa fazer isso usando apenas ponteiros.

**Especificação:**
```c
FUNÇÃO reverter_esteira(ponteiro para inteiros pacotes, inteiro quantidade):
    // Inverter ordem dos pacotes usando APENAS aritmética de ponteiros
    // REGRAS:
    //   - NÃO usar notação de array (sem pacotes[i])
    //   - Usar dois ponteiros: inicio e fim
    //   - Mover ponteiros um em direção ao outro
    //   - Parar quando se encontrarem
    
    // Pseudocódigo:
    // inicio = pacotes
    // fim = pacotes + (quantidade - 1)
    // ENQUANTO inicio < fim:
    //     trocar(*inicio, *fim)
    //     inicio++
    //     fim--
FIM

FUNÇÃO imprimir_esteira(ponteiro para inteiros pacotes, inteiro quantidade):
    // Imprimir usando APENAS aritmética de ponteiros
    // Use um loop com ponteiro temporário
FIM

FUNÇÃO verificar_palindromo(ponteiro para inteiros pacotes, inteiro quantidade):
    // DESAFIO: Verificar se a ordem dos pacotes é um palíndromo
    // Exemplo: [1, 2, 3, 2, 1] é palíndromo
    // Usar mesma técnica de dois ponteiros
    // Retornar 1 se for palíndromo, 0 caso contrário
FIM
```

**Teste Esperado:**
```c
PRINCIPAL:
    // Teste 1: Esteira com ordem normal
    IMPRIMIR "=== Teste 1: Reverter Esteira Simples ==="
    esteira[] = {101, 102, 103, 104, 105}
    quantidade = sizeof(esteira) / sizeof(esteira[0])
    
    IMPRIMIR "Ordem original dos pacotes:"
    imprimir_esteira(esteira, quantidade)
    
    reverter_esteira(esteira, quantidade)
    
    IMPRIMIR "Ordem após reversão:"
    imprimir_esteira(esteira, quantidade)
    
    // Teste 2: Quantidade ímpar e par
    IMPRIMIR "\n=== Teste 2: Quantidade Ímpar ==="
    esteira2[] = {1, 2, 3, 4, 5, 6, 7}
    reverter_esteira(esteira2, 7)
    imprimir_esteira(esteira2, 7)
    
    IMPRIMIR "\n=== Teste 3: Verificar Palíndromo ==="
    palindromo[] = {1, 2, 3, 2, 1}
    nao_palindromo[] = {1, 2, 3, 4, 5}
    
    SE verificar_palindromo(palindromo, 5):
        IMPRIMIR "Primeiro caso É palíndromo!"
    
    SE NÃO verificar_palindromo(nao_palindromo, 5):
        IMPRIMIR "Segundo caso NÃO é palíndromo!"
FIM
```

**Aprendizados:**
- Aritmética de ponteiros: `ptr + n` avança n elementos
- Técnica dos dois ponteiros é eficiente (O(n/2))
- Manipulação in-place economiza memória
- Diferença entre `ptr++` (avança) e `ptr--` (retrocede)
- `*ptr` acessa o valor, `ptr` é o endereço
