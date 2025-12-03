// ordenação por matricula!
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int mat;
    char nome[30];
    float n1, n2, n3;
}Aluno;

typedef struct{
    int qtd;
    Aluno dados[MAX];
}Lista;

Lista *cria_lista(void);
int ordenada(Lista *li, int ordem);
int lista_vazia(Lista *li);
int tamanho_lista(Lista *li);

int main(void) {
    Lista *li = cria_lista();
    int i, ordem = 0;

    if(li == NULL)
        printf("Falha ao alocar memoria para a lista.\n"), exit(1);

    printf("Quantidade de elementos (0-%d): ", MAX);
    // pega quantidade de elementos
    scanf("%d", &li->qtd);
    if(li->qtd < 0 || li->qtd > MAX)
        printf("Quantidade invalida.\n"), free(li), exit(1);

    // Coleta apenas as matrículas necessárias para verificar a ordenação por matricula
    for(i=0; i<li->qtd; i++){
        printf("Mat %d: ", i+1);
        scanf("%d", &li->dados[i].mat);
        if(li->dados[i].mat < 0)
            printf("Matricula invalida.\n"), free(li), exit(1);
    }

    printf("Digite 1 para ordem crescente ou 2 para decrescente: ");
    scanf("%d", &ordem);
    if(ordem != 1 && ordem != 2)
        printf("Ordem invalida.\n"), free(li), exit(1);
    if(ordenada(li, ordem)){
        // 1
        printf("A lista esta ordenada .\n");
    }else{ 
        // 2
        printf("A lista não esta ordenada.\n");
    }
    
    free(li);
    return 0;
}

Lista *cria_lista(void){
    Lista *li = malloc(sizeof(Lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

int ordenada(Lista *li, int ordem){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 1;

    int n = tamanho_lista(li);
    if(n <= 1)
        return 1;

    for(int i = 0; i < n - 1; i++){ // n-1 pois compara com o proximo
        if(ordem == 1){ // crescente
            if(li->dados[i].mat > li->dados[i+1].mat)
                return 0;
        }else{ // ordem == 2 decrescente
            if(li->dados[i].mat < li->dados[i+1].mat)
                return 0;
        }
    }
    return 1;
}

int lista_vazia(Lista *li){
    // Se retorna 1, está vazia
    if(li == NULL)
        return 1;
    if(li->qtd == 0)
        return 1;
    return 0;
}

int tamanho_lista(Lista *li){
    if(li == NULL)
        return -1;
    return li->qtd;
}