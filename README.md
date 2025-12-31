# 🏴‍☠️ c-deep-journey-attempt

> *"Vou me tornar o Cavaleiro Negro da linguagem C!"*

Repositório de estudos avançados em C, focado em construir uma base sólida para desenvolvimento de sistemas operacionais, drivers e programação embarcada.

## 🗺️ Mapa da Jornada

Este repositório está organizado seguindo uma trilha progressiva de aprendizado, do básico avançado até o desenvolvimento de sistemas operacionais completos.

### 📍 Fase 1: Fortalecendo a Base (Grand Line - Primeira Metade)

#### 1. Ponteiros - Nível Profundo ⚔️ *[ESTAMOS AQUI]*
**O que você vai dominar:**
- Ponteiros para ponteiros e níveis múltiplos de indireção
- Aritmética de ponteiros e manipulação direta de memória
- Ponteiros de função (callbacks e tabelas de funções)
- Diferenças sutis entre arrays e ponteiros
- Ponteiros constantes vs ponteiros para constantes

**Por que é importante:** Ponteiros são a essência do C. Dominar ponteiros é como dominar o Haki - você vai ver através das abstrações e entender o que realmente acontece na memória.

**Diretório:** `i1-ponteiros-avancados/`

---

#### 2. Memória e Organização 🧠
**O que você vai aprender:**
- Stack vs Heap: como funcionam e quando usar cada um
- Segmentação de memória (text, data, bss, heap, stack)
- Memory alignment e padding em structs
- Endianness (big-endian vs little-endian)
- Cache locality e otimização de acesso à memória

**Por que é importante:** Para criar um OS, você precisa entender exatamente como a memória é organizada. É como conhecer cada ilha da Grand Line antes de navegar.

**Diretório:** `i2-memoria-organizacao/`

---

#### 3. Preprocessador e Compilação 🔧
**O que você vai dominar:**
- Macros avançadas e metaprogramação
- Header guards e organização modular
- Conditional compilation
- Pipeline completo: preprocessador → compilador → assembler → linker
- Makefiles e build systems

**Por que é importante:** Entender o processo de compilação é essencial para debugar problemas complexos e otimizar código.

**Diretório:** `i3-preprocessador-compilacao/`

---

### 📍 Fase 2: Descendo ao Nível do Hardware (New World)

#### 4. C e Assembly 💻
**O que você vai aprender:**
- Como C vira código de máquina
- Inline assembly em C
- Registradores e instruções básicas de CPU
- Convenções de chamada (calling conventions)
- Como otimizar código crítico com assembly

**Por que é importante:** Para drivers e OS, às vezes você precisa falar diretamente com o hardware. É como aprender a linguagem dos Poneglyphs.

**Diretório:** `i4-c-assembly/`

---

#### 5. Bare Metal Programming ⚡
**O que você vai dominar:**
- Programação sem sistema operacional
- Memory-mapped I/O
- A keyword `volatile` e quando usá-la
- Manipulação direta de hardware
- Interrupções e tratamento de exceções

**Por que é importante:** Este é o conhecimento necessário para microcontroladores e desenvolvimento de OS. Você vai programar o hardware diretamente.

**Diretório:** `i5-bare-metal/`

---

### 📍 Fase 3: Construindo Sistemas (Laugh Tale)

#### 6. Bootloaders 🚀
**O que você vai criar:**
- Bootloader básico em assembly e C
- Modo real vs modo protegido vs modo longo
- Carregamento do kernel na memória
- Configuração inicial do ambiente

**Diretório:** `i6-bootloaders/`

---

#### 7. Gerenciamento de Memória 🗃️
**Tópicos:**
- Paginação e segmentação
- Alocadores de memória (malloc/free customizados)
- Memory Management Unit (MMU)
- Virtual memory

**Diretório:** `i7-gerenciamento-memoria/`

---

#### 8. Escalonamento e Processos ⚙️
**O que você vai implementar:**
- Criação e gerenciamento de processos
- Algoritmos de escalonamento
- Context switching
- Threads e concorrência

**Diretório:** `i8-processos-escalonamento/`

---

#### 9. Drivers de Hardware 🔌
**Tópicos práticos:**
- Drivers de teclado, mouse, VGA
- Drivers de disco (IDE/SATA)
- Drivers de rede
- Framework para desenvolvimento de drivers

**Diretório:** `i9-drivers/`

---

#### 10. Sistema Operacional Completo 👑
**Projeto final:**
- Integração de todos os componentes
- Shell básico
- Sistema de arquivos
- Seu próprio OS rodando!

**Diretório:** `i10-os-completo/`

---

## 📚 Estrutura dos Diretórios

Cada tópico segue a mesma estrutura:

```
iX-nome-topico/
├── readme.md                  # Tutorial detalhado do tópico
├── recursos.md                # Links e referências
├── j1-teoria/                 # teoria
│   ├── teoria.md
│   ├── t1-nome/
│   └── t2-nome/
├── j2-exercicios/             # Códigos dos exercicios
│   ├── exercicios.md          # Atividades para fixar conceitos
│   ├── e1-nome/
│   └── e2-nome/
└── j3-projetos/               # Projetos práticos
    ├── p1-nome/
    ├── p2-nome/
    └── p3-nome/
```

## 🎯 Como Usar Este Repositório

1. **Estude o tutorial** de cada tópico no `README.md`
2. **Faça os exercícios** no `exercicios.md` (com pseudocódigo inicial)
3. **Implemente os projetos** práticos
4. **Consulte as referências** para aprofundamento
5. **Avance** para o próximo tópico quando se sentir confortável

## 🛠️ Ferramentas Recomendadas

- **Compilador:** GCC ou Clang
- **Debugger:** GDB
- **Editor:** VS Code, Vim, ou sua preferência
- **Emulador:** QEMU (para testar OS e bare metal)
- **Analisador:** Valgrind (para memory leaks)

## 📖 Recursos Gerais

- [The C Programming Language (K&R)](https://www.amazon.com.br/Programming-Language-Brian-W-Kernighan/dp/0131103628) - A bíblia do C
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/) - Guia gratuito e excelente
- [OSDev Wiki](https://wiki.osdev.org/) - Referência essencial para OS development
- [C Reference](https://en.cppreference.com/w/c) - Documentação completa

## 🎮 Microcontroladores

Para prática em microcontroladores, recomendo:
- **Arduino** (AVR) - Fácil para começar
- **STM32** (ARM Cortex-M) - Mais profissional
- **ESP32** - WiFi/Bluetooth integrado

## ⚡ Status do Repositório

- [x] Estrutura do repositório
- [x] Fase 1 - Tópico 1: Ponteiros Avançados
- [ ] Fase 1 - Tópico 2: Memória e Organização
- [ ] Fase 1 - Tópico 3: Preprocessador e Compilação
- [ ] Fase 2 - Tópico 4: C e Assembly
- [ ] Fase 2 - Tópico 5: Bare Metal Programming
- [ ] Fase 3 - Tópicos 6-10: Sistema Operacional Completo

---

## 🤝 Contribuições

Este é um repositório de estudo pessoal, mas sugestões são bem-vindas! Abra uma issue ou pull request.

---

**"O conhecimento é o maior tesouro que existe!"** 🏴‍☠️