#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct lista {
    int qtd;
    Aluno dados[MAX];
};

Lista *criar_lista(void) {
    Lista *li = malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd==0);
}

int inserir_final(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int inserir_inicio(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    for(int i=li->qtd-1;i>=0;i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int inserir_meio(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i = 0;
    while (i<li->qtd && li->dados[i].mat < al.mat)
        i++;
    for(int k=li->qtd-1;k>=i;k--)
        li->dados[k+1]=li->dados[k];
    li->dados[i]=al;
    li->qtd++;
    return 1;
}

int inserir_ordenado(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    int k=0;
    while(k < li->qtd && li->dados[k].mat < al.mat)
        k++;
    for(int i=li->qtd-1;i>=k;i--)
        li->dados[i+1] = li->dados[i];
    li->dados[k] = al;
    li->qtd++;
    return 1;
}

int remove_final(Lista* li){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;

    li->qtd--;
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;

        int k, i=0;
    while(i<li->qtd && li->dados[i].mat != mat)
    i++;
    if(i == li->qtd)
        return 0;

    for(k=i; k<li->qtd-1;k++)
        li->dados[k] = li->dados[k+1];

    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, Aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    // pos relativa
    *al = li->dados[pos-1];
    return 1;
}
int consulta_lista_mat(Lista* li, int mat, Aluno *al){
    if(li == NULL)
        return 0;
    int i=0;
    while (i<li->qtd && li->dados[i].mat != mat)
        i++;

    if(i==li->qtd)
        return 0;

    *al = li->dados[i];
    return 1;
}

void imprime_lista(Lista *li){
    if(li != NULL){
        if(lista_vazia(li))
            printf("Lista vazia\n");
        else{
            for(int i=0; i<li->qtd; i++){
                printf("%d\t\t", li->dados[i].mat);
                printf("%s\n", li->dados[i].nome);
            }
        }
    }
}

// complicadinho
int remove_retorna_lista(Lista *li, int mat, Aluno *al, int *pos){
    if(li == NULL || lista_vazia(li))
        return 0;

    int i = 0;
    while(i < li->qtd && li->dados[i].mat != mat)
        i++;

    if(i == li->qtd)
        return -1;

    if(al != NULL)
        *al = li->dados[i]; // al recebe dados do aluno removido
    if(pos != NULL)
        *pos = i;           // pos recebe index

    for(int k=i; k<li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];  // ajusta o tamanho do vetor partindo do lugar removido, empurrando

    li->qtd--;
    return 1;
}