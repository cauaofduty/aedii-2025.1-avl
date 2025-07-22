# 🌲 AVL Tree Implementation in C

Este repositório contém uma implementação completa e comentada de uma **Árvore AVL (Adelson-Velsky and Landis Tree)** em linguagem C.  
O projeto foi desenvolvido como atividade avaliativa sobre a própria, incluindo inserção, remoção  
e rotação automática para manter o fator de balanceamento da árvore.

---

## 📚 Sobre

As Árvores AVL são árvores binárias de busca auto-balanceadas que garantem complexidade **O(log n)** nas operações de  
inserção, remoção e busca. Essa implementação trata:

- Inserção com rotação simples e dupla para manter o balanceamento
- Remoção com atualizações do fator de balanceamento dos nós e rebalanceamento
- Impressão em pré-ordem com fatores de balanceamento

---

## 🛠️ Compilação

Você pode compilar o programa com `gcc`, colando no terminal:


gcc avl.h avl.c main.c -o avl.exe

---

## 💥Testagem

Podem ser criados arquivos personalizados para testar a implementação.
Crie o arquivo "in.txt" (no VS Code roda apenas com "in" sem formato) e gere as entradas à vontade. Elas podem estar em qualquer 
formato, espaçando as entradas, porem é recomendável ser feito o seguinte:

`in`:

1 11  
1 12  
3 12  
2  
99

`out`:

[11 0]

## 📘 Onde:

| Código   | Ação                          | Descrição                                                                 |
|----------|-------------------------------|---------------------------------------------------------------------------|
| `1 X`    | Inserção                      | Insere o valor `X` na árvore AVL                                          |
| `2`      | Print                         | Imprime todos os elementos da árvore em pré-ordem com indicação de coeficiente de balanceamento de cada nó |
| `3 X`    | Remoção                       | Remove o valor `X` da árvore AVL, aplicando rotações conforme necessário  |
| `99`     | Finalizar                     | Encerra o programa (obrigatório ao final da entrada)                      |


#### ⁉Como utilizar:


Após o passo anterior de compilar, basta colar no terminal o seguinte:

`avl.exe < in > out`

Caso não funcione, crie o arquivo out.

Dica: Não precisa redigitar/colar tudo, basta pressionar a tecla para cima (⬆) do teclado no terminal que a instrução anterior
será recuperada.

---

Podem ser adicionados prints ao longo dos desvios para observar seu comportamento (ex: das recursões). 


---

## 🧑‍💻 Autor  
Cauã de Souza Santos  
Estudante de Bacharelado em Ciências da Computação  
Desenvolvido como atividade da disciplina Algoritmos e Estruturas de Dados II






