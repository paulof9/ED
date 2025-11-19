# Estrutura de dados 01

## Lista de exercícios 01
1. Considere a lista: [4, 8, 10, 12, 20] (tamanho atual = 5). Simule um passo a passo para:
(a) Inserir o elemento 15 na posição 2
(b) Remover o elemento da posição 4
(c) Inserir 3 no início da lista
(d) Mostrar a lista após cada operação

2. Dada uma lista estática já ordenada: [2, 5, 7, 11, 13], explique:
(a) Por que não é possível inserir um elemento no meio sem deslocar os outros?
(b) Onde o número 9 deveria ser inserido?
(c) Quantos deslocamentos são necessários?

3. Liste e explique, conceitualmente, os 3 principais tipos de inserção em uma lista estática. Inclua
na explicação o impacto no número de deslocamentos.
(a) Inserção no início
(b) Inserção no meio
(c) Inserção no final

4. Uma escola quer armazenar no máximo 50 nomes de alunos para participar de um evento. O
sistema usa uma lista estática. Perguntas:
(a) O que acontece se o 51º aluno tentar se cadastrar?
(b) Como o sistema deve tratar essa situação?
(c) Por que uma lista estática talvez não seja a melhor estrutura nesse caso?

5. Implemente as seguintes funções para a estrutura de dados lista estática vista em sala de aula:
(a) Implemente uma função que imprima todos os elementos da lista.
(b) Ajuste a função de remoção em qualquer posição para que a mesma retorne o elemento
removido e a posição na qual o mesmo foi removido.
(c) Implemente uma função que ordene os elementos da lista. Assuma a premissa de que os
elementos foram inseridos sempre no final.

6. Considerando listas estáticas, faça uma função em C que verifique se a lista está ordenada. A
função deve ainda permitir determinar o tipo de ordenação (crescente ou decrescente).

7. Para listas estáticas, implemente uma função que elimine de uma determinada lista todas as
ocorrências de um dado elemento. Considere que a lista está ordenada.

8. Considerando a implementação de listas estáticas apresentada em aula, implemente uma função
para copiar todos os elementos de uma lista A em outra lista B.

9. Implemente uma função que inverta a lista.
10. Implemente uma função que seja capaz de concatenar duas listas, ou seja, que receba duas
listas estáticas A e B e produza uma lista C com os elementos das duas.

11. Implemente uma função que seja capaz de receber duas listas estáticas ordenadas A e B e
retorne uma terceira lista intercalada, como no exemplo a seguir:

|   Lista A    |
|-------------|
|{3, 5, 6, 9, 13}|
|   **Lista B**    |
|{1, 2, 6, 8, 11}|
|   **Lista C** |
|{1, 2, 3, 5, 6, 6, 8, 9, 11, 13}|

12. Em que circunstâncias seria preferível utilizar a implementação estática ao invés da dinâmica
para listas? Cite algumas vantagens e desvantagens que podem contribuir para esta justificativa.

