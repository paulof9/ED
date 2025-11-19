#include <stdio.h>
#include "Lista.h"

int main(void){
    /* Smoke test to exercise the list API. */
    Lista *li = cria_lista();
    if(li == NULL){
        // fprint stderr diz qual erro especifico que deu.
        fprintf(stderr, "Falha ao criar a lista.\n");
        return 1;
    }

    li->id = 1;
    li->value = 42;
    printf("Lista criada: id=%d value=%d\n", li->id, li->value);

    printf("Lista vazia? %s\n", lista_vazia(li) ? "sim" : "nao");

    liberar_mem(&li);
    printf("Lista vazia apos liberar? %s\n", lista_vazia(li) ? "sim" : "nao");

    return 0;
}