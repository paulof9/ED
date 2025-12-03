#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main(void){
    Lista *li = criar_lista();
    if(li == NULL){
        fprintf(stderr, "Falha ao criar a lista.\n");
        return 1;
    }

    // definindo valores de alunos
    Aluno al1 = {1, "Ana", 7.5f, 8.0f, 9.0f};
    Aluno al2 = {3, "Bruno", 6.5f, 7.0f, 8.0f};
    Aluno al3 = {2, "Carla", 8.5f, 8.0f, 9.5f};

    inserir_final(li, al1);
    inserir_inicio(li, al2);
    inserir_ordenado(li, al3);

    printf("Tamanho apos insercoes: %d\n", tamanho_lista(li));
    imprime_lista(li);

    remove_final(li);
    printf("Tamanho apos remover ultimo: %d\n", tamanho_lista(li));
    imprime_lista(li);

    Aluno removido;
    int posRemovida = -1;
    int res = remove_retorna_lista(li, 2, &removido, &posRemovida);

    if(res == 1)
        printf("Aluno %s removido na posicao %d.\n", removido.nome, posRemovida);
    else if(res == -1)
        printf("Matricula nao encontrada.\n");
    else
        printf("Lista vazia ou ponteiro invalido.\n");

    printf("Tamanho final: %d\n", tamanho_lista(li));
    imprime_lista(li);

    libera_lista(li);
    return 0;
}

