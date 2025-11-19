#include <stdlib.h>
#include "Lista.h"

Lista *cria_lista(void){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li){
        // inicializa com 0;
        li->id = 0;
        li->value = 0;
    }
    return li;
}

int lista_vazia(const Lista *li){
    return li == NULL;
}

void liberar_mem(Lista **li){
    if(li != NULL && *li != NULL){
        free(*li);
        *li = NULL;
    }
}