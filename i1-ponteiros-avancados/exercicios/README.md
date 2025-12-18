
## 💡 Dicas Gerais

### Para Todos os Exercícios:

1. **Sempre compile com warnings:**
   ```bash
   gcc -Wall -Wextra -Werror -g seu_codigo.c -o programa
   ```

2. **Use Valgrind:**
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all ./programa
   ```

3. **Teste casos extremos:**
   - Ponteiros NULL
   - Arrays vazios
   - Tamanho 0
   - Valores negativos

4. **Documente seu código:**
   - Explique o que cada ponteiro aponta
   - Desenhe diagramas de memória
   - Comente decisões de design

---

## ✅ Critérios de Avaliação

Seu código deve:
- [ ] Compilar sem warnings
- [ ] Não ter memory leaks (valgrind clean)
- [ ] Tratar casos extremos
- [ ] Ter código limpo e bem comentado
- [ ] Seguir boas práticas de C
- [ ] Usar ponteiros de forma idiomática

---

## 🎯 Próximos Passos

Depois de completar estes exercícios:
1. Compare suas soluções com diferentes abordagens
2. Meça performance (tempo de execução)
3. Otimize partes críticas
4. Avance para os **Projetos Práticos** em `projetos/`

---

**Lembre-se:** Cada exercício resolvido é uma habilidade conquistada! 🏴‍☠️