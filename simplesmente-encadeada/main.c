#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    Node *prox;
}Node;

// funcao criar no
void liberar_mem(Node **head);
int inserir_inicio(Node **head, int valor);
int inserir_final(Node **head, int valor);
int remover_inicio(Node **head);
int remover_final(Node **head);
int remover_valor(Node **head, int valor);
int buscar(Node **head, int valor);

int main(){
    Node *head = NULL;

}

void liberar_mem(Node **head){
    Node *temporario;

    while(*head != NULL){
        temporario = *head;
        *head = (*head)->prox;  //  vai avançando com o head msm pq o primeiro tem q ser perdido, cada iteração o primeiro é perdido e o proximo é apontado
        free(temporario);       // limpa o head a cada iteração
    }
}
int inserir_inicio(Node **head, int valor){
    Node *novoNode = (Node*)malloc(sizeof(Node));

    novoNode->valor = valor;
    novoNode->prox = *head;
    *head = novoNode;

    return 1;
}
int inserir_final(Node **head, int valor){
    Node *novoNode = (Node*)malloc(sizeof(Node));
    novoNode->valor = valor;
    novoNode->prox = NULL;

    if(*head == NULL){
        *head = novoNode;
    }else{
        Node* atual = *head;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novoNode;
    }
    return 1;
}
int remover_inicio(Node **head){
    if(*head == NULL){
        return 0;
    }
    Node *temporario = *head;
    *head = (*head)->prox;   // avança o head
    free(temporario);
    return 1;
}
int remover_final(Node **head){
    if(*head == NULL){
        return 0;
    }

    // caso especial: apenas um nó
    if ((*head)->prox == NULL) {
        free(*head);
        *head = NULL;
        return 1;
    }

    Node *atual = *head;
    Node *anterior = NULL;
    while(atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }
    anterior->prox = NULL;
    free(atual);
    return 1;
}
int remover_valor(Node **head, int valor){
    if(*head == NULL){
        return 0;
    }

    // caso especial: apenas um nó
    if((*head)->prox == NULL && (*head)->valor == valor){
        free(*head);
        *head = NULL;
        return 1;
    }
    Node *anterior = *head;
    Node *atual = (*head)->prox;

    while(atual->prox != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        return 0;
    }

    anterior->prox = atual->prox;
    free(atual);
}
int buscar(Node **head, int valor){
    Node *atual = head;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;       // se valor existe, retorna 1;
        }
        atual = atual->prox; // aqui tem q ter nesse while pra avançar pro proximo nó.
    }

    return 0;
}