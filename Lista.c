#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/*
int adicionar_inicio(Lista *li, int id);
int adicionar_meio(Lista *li, int id);
int adicionar_fim(Lista *li, int id);
int adicionar_pos(Lista *li, int id);
int remover_item(Lista *li, int id);
void excluir_lista(Lista *li) é o mesmo que liberar_mem(Lista **li)
*/

Lista *cria_lista(void){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li){
        // inicializa com 0;
        li->id = 0;
        li->value = 0;
    }else{
        fprintf(stderr, "Erro ao alocar memoria para a lista.\n");
        return NULL;
    }
    return li;
}

int adicionar_inicio(int id, Lista *li){
    
    return 1;
}

int adicionar_meio(int id, Lista *li){
    // implementação fictícia
    return 1;
}

int adicionar_fim(int id, Lista *li){
    // implementação fictícia
    return 1;
}

int adicionar_pos(int id, Lista *li){
    // implementação fictícia
    return 1;
}   

int remover_item(int id, Lista *li){
    // implementação fictícia
    return 1;
}


int lista_existe(Lista *li){
    if(!lista_vazia(li) || cria_lista() != NULL)
        return 1;
    else
        return 0;
}

int lista_vazia(const Lista *li){
    return li == NULL;
}

void menu(Lista *li, int op, int id){
    printf("Digite a opção:\n");
    printf("1-Criar lista\n\t");
    printf("2-Adicionar item no inicio\n\t");
    printf("3-Adicionar item no meio\n\t");
    printf("4-Adicionar item no fim\n\t");
    printf("5-Adicionar item na posicao onde queres\n\t");
    printf("6-Remover item\n\t");
    printf("7-Excluir lista\n\t");

    scanf("%d", &op);

    switch(op){
        case 1:
            if(lista_existe(li)){
                *cria_lista();
                return 1;
            } else {
                return 0;
            }
        case 2:
            if(lista_existe(li)){
                adicionar_inicio(id, li);
                return 1;
            } else {
                return 0;
            }
        case 3:
            if(lista_existe(li)){
                adicionar_meio(id, li);
                return 1;
            } else {
                return 0;
            }
        case 4:
            if(lista_existe(li)){
                adicionar_fim(id, li);
                return 1;
            } else {
                fprintf(stderr, "Lista nao existe.\n");
                return 0;
            }
        case 5:
            if(lista_existe(li)){
                adicionar_pos(id, li);
                return 1;
            } else {
                return 0;
            }
        case 6:
            if(lista_existe(li)){
                remover_item(id, li);
                return 1;
            } else {
                return 0;
            }
        case 7:
            if(lista_existe(li)){
                excluir_lista(li);
                return 1;
            } else {
                return 0;
            }
        default:
            return 0;
    }
}

void liberar_mem(Lista **li){
    if(li != NULL && *li != NULL){
        free(*li);
        *li = NULL;
    }
}