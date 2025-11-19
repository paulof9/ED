#include <stdio.h>
#include "Lista.h"

int main(void){
    Lista *li = cria_lista();

    printf("Lista criada: id=%d value=%d\n", li->id, li->value);

    printf("Lista vazia? %s\n", lista_vazia(li) ? "sim" : "nao");

    liberar_mem(&li);
    printf("Lista vazia apos liberar? %s\n", lista_vazia(li) ? "sim" : "nao");

    return 0;
}