// Vetor com operações de lista.
#include <stdio.h>
#include <string.h>
#include "Lista.h"

// pq foi usado o tipo static?? boa pratica, evita erros (é usado somente uma vez)
// por que essa funcao foi criado aqui e nao nos outros arquivos? uso local, pode ser usado em lista.c e declarado em lista.h. E sim esta inicializando.
static Aluno criar_aluno(int mat, const char *nome,
                         float n1, float n2, float n3){
    Aluno al;
    al.mat = mat;
    strncpy(al.nome, nome, sizeof(al.nome));
    al.nome[sizeof(al.nome) - 1] = '\0';
    al.nota1 = n1;
    al.nota2 = n2;
    al.nota3 = n3;
    return al;
}

int main(void){
    Lista *li = cria_lista();
    if(li == NULL){
        fprintf(stderr, "Falha ao criar a lista.\n");
        return 1;
    }

    /* Antes os dados eram adicionados sem informar o conteúdo do aluno.
     * Agora passamos a struct completa para cada inserção. */
    adicionar_fim(li, criar_aluno(1, "Ana", 8.5f, 7.0f, 9.0f));
    adicionar_fim(li, criar_aluno(2, "Bruno", 6.5f, 8.0f, 7.5f));
    adicionar_inicio(li, criar_aluno(3, "Carlos", 9.0f, 8.5f, 9.5f));
    adicionar_meio(li, criar_aluno(4, "Duda", 7.0f, 7.5f, 8.0f));
    adicionar_pos(li, 2, criar_aluno(5, "Eva", 10.0f, 9.5f, 9.0f));

    printf("Lista apos insercoes:\n");
    exibir_lista(li);

    remover_inicio(li);
    remover_meio(li);
    remover_final(li);
    remover_pos(li, 0);

    printf("\nLista apos remocoes:\n");
    exibir_lista(li);

    liberar_mem(&li);
    return 0;
}