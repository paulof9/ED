#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista *cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
       li->qtd = 0;
    return li;
}

int adicionar_inicio(Lista *li){
    if (li == NULL)
        return 0;
    if (lista_vazia(li))
        return 0;

    int i;
    for(i=0;i<li->qtd-1;i++){
        li->dados[i] = li->dados[i+1]; // aqui pega sempre 1 e +1
    }
    li->qtd++;
}

int adicionar_meio(Lista *li){
    if (li == NULL)
        return 0;
    if (lista_vazia(li))
        return 0;

    if(li->qtd % 2 == 0) {
        for(int i=li->qtd/2; i<li->qtd-1;i++){
            li->dados[i] = li->dados[i+1];
        }
        li->qtd++;
    }else{
        for(int i=li->qtd % 2 == 1; i<li->qtd-1;i++){
            li->dados[i] = li->dados[i+1];
        }
        li->qtd++;
    }
    return 1;
}

int adicionar_fim(Lista *li){
    if (li == NULL)
        return 0;
    if (lista_vazia(li))
        return 0;

    li->qtd++;
    return 1;
}

int adicionar_pos(Lista *li, int pos){
    if (li == NULL)
        return 0;
    if (lista_vazia(li) || li->qtd < pos)
        return 0;
    // pos maior [1,2, '', '', 3]

    for(int i=pos; i<li->qtd-1;i++){
        li->dados[i] = li->dados[i+1];
    }
    
    li->qtd++;
    return 1;
}   

int remover_inicio(Lista *li){
    if (li == NULL)
        return 0;
    if (lista_vazia(li))
        return 0;

    int i;
    for(i=0;i<li->qtd-1;i++){
        li->dados[i] = li->dados[i+1]; // aqui pega sempre 1 e +1
    }
    li->qtd--;
    return 1;
}

int remover_meio(Lista *li){
    if (li == NULL)
        return 0;
    if (lista_vazia(li))
        return 0;

    if(li->qtd % 2 == 0) {
        for(int i=li->qtd/2; i<li->qtd-1;i++){
            li->dados[i] = li->dados[i+1];
        }
        li->qtd--;
    }else{
        for(int i=li->qtd % 2 == 1; i<li->qtd-1;i++){
            li->dados[i] = li->dados[i+1];
        }
        li->qtd--;
    }
    return 1;
}

int remover_final(Lista *li){
    if (li == NULL)
        return 0;
    if (lista_vazia(li))
        return 0;

    li->qtd--; // só deleta mesmo
    return 1;
}

int remover_pos(Lista *li, int pos){
    if (li == NULL)
        return 0;
    if (lista_vazia(li) || li->qtd < pos || li->qtd > pos)
        return 0;
    
    for(int i=pos; i<li->qtd-1;i++){
        li->dados[i] = li->dados[i+1];
    }

    li->qtd--;
    return 1;
}

int lista_vazia(Lista *li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void liberar_mem(Lista **li){
    free(*li);
    *li = NULL;
}