# Estrutura de dados 01
 * tenho de ver lista ordenadas!

## Tipos de Listas:
### 1. Lista Estática (ou Vetor)

É uma lista guardada em um array.
A memória é fixa: você decide o tamanho antes e não muda depois.

✔️ Vantagens

* Acesso rápido por índice (O(1)).

* Simples de usar.

❌ Desvantagens

* Tamanho fixo.

* Inserir/remover no meio pode ser custoso, pois precisa deslocar elementos.

### 2. Lista Ligada Simples (Singly Linked List)

Aqui cada elemento é um nó que guarda:

* um valor

* um ponteiro para o próximo nó

* É como uma corrente apontando para frente.

✔️ Vantagens

* Cresce dinamicamente.

* Inserção e remoção simples na cabeça da lista.

❌ Desvantagens

* Acesso lento: precisa percorrer um a um.

* Não dá pra voltar ao nó anterior.

🌱 Exemplo em C

```
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

int main() {
    No *n1 = malloc(sizeof(No));
    No *n2 = malloc(sizeof(No));

    n1->valor = 10;
    n1->prox = n2;

    n2->valor = 20;
    n2->prox = NULL;

    printf("%d -> %d\n", n1->valor, n2->valor);

    free(n1);
    free(n2);
    return 0;
}
```
### 3. Lista Duplamente Ligada (Doubly Linked List)

Cada elemento guarda:

- ponteiro para próximo

- ponteiro para anterior

É como um trilho onde você pode andar para frente e para trás.

✔️ Vantagens

* Inserção e remoção mais flexíveis.

* Pode percorrer nos dois sentidos.

❌ Desvantagens

* Mais memória por nó.

* Mais complexa de implementar.

🌱 Exemplo em C

```
typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;
```

## Lista de exercícios 01
1. Considere a lista: [4, 8, 10, 12, 20] (tamanho atual = 5). Simule um passo a passo para:
- (a) Inserir o elemento 15 na posição 2
- - Aqui devemos criar uma função que pegue a posição 2 com um for e a partir dessa posição adicione o elemento 15, então empurre os demais para n+1 posições e por fim adicione no tamanho da lista +1;
- (b) Remover o elemento da posição 4
- - A mesma ideia de inserir, porém empurra do ultimo para o primeiro os elementos de diminui a lista em -1;
- (c) Inserir 3 no início da lista
- - Com a mesma função de adicionar, insere, puxa pra frente e aumenta a lista;
- (d) Mostrar a lista após cada operação
- - For percorrendo a lista com printf;@

2. Dada uma lista estática já ordenada: [2, 5, 7, 11, 13], explique:
- (a) Por que não é possível inserir um elemento no meio sem deslocar os outros?
- (b) Onde o número 9 deveria ser inserido?
- (c) Quantos deslocamentos são necessários?

3. Liste e explique, conceitualmente, os 3 principais tipos de inserção em uma lista estática. Inclua na explicação o impacto no número de deslocamentos.
- (a) Inserção no início
- (b) Inserção no meio
- (c) Inserção no final

4. Uma escola quer armazenar no máximo 50 nomes de alunos para participar de um evento. O sistema usa uma lista estática. Perguntas:
- (a) O que acontece se o 51º aluno tentar se cadastrar?
- (b) Como o sistema deve tratar essa situação?
- (c) Por que uma lista estática talvez não seja a melhor estrutura nesse caso?

5. Implemente as seguintes funções para a estrutura de dados lista estática vista em sala de aula:
- (a) Implemente uma função que imprima todos os elementos da lista.
- (b) Ajuste a função de remoção em qualquer posição para que a mesma retorne o elemento removido e a posição na qual o mesmo foi removido.
- (c) Implemente uma função que ordene os elementos da lista. Assuma a premissa de que os elementos foram inseridos sempre no final.

6. Considerando listas estáticas, faça uma função em C que verifique se a lista está ordenada. A função deve ainda permitir determinar o tipo de ordenação (crescente ou decrescente).

7. Para listas estáticas, implemente uma função que elimine de uma determinada lista todas as ocorrências de um dado elemento. Considere que a lista está ordenada.

8. Considerando a implementação de listas estáticas apresentada em aula, implemente uma função para copiar todos os elementos de uma lista A em outra lista B.

9. Implemente uma função que inverta a lista.
10. Implemente uma função que seja capaz de concatenar duas listas, ou seja, que receba duas listas estáticas A e B e produza uma lista C com os elementos das duas.

11. Implemente uma função que seja capaz de receber duas listas estáticas ordenadas A e B e retorne uma terceira lista intercalada, como no exemplo a seguir:

|   Lista A    |
|-------------|
|{3, 5, 6, 9, 13}|

|   Lista B    |
|-------------|
|{1, 2, 6, 8, 11}|

|   Lista C |
|-------------|
|{1, 2, 3, 5, 6, 6, 8, 9, 11, 13}|

12. Em que circunstâncias seria preferível utilizar a implementação estática ao invés da dinâmica para listas? Cite algumas vantagens e desvantagens que podem contribuir para esta justificativa.

