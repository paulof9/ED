#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *proximo;
} Node;

void inserirInicio(Node **head, int valor);

int main(){
    Node* head = NULL;
    int MAX;
    
    // definir tamanho da lista
    printf("Quantos nos voce quer: ");
    scanf("%d", &MAX);

    // computar
    printf("Digite os valores hipoteticos de cada no:\n");
    for(int i = 0; i < MAX; i++){
        int valor;
        printf("No %d: ", i + 1);
        scanf("%d", &valor);
        inserirInicio(&head, valor);
    }

    // imprimir
    printf("Lista simplesmente encadeada:\n");
    Node* lista = head;
    while(lista != NULL){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
    printf("NULL\n");

    return 0;
}

void inserirInicio(Node **head, int valor){
    // definindo valores do novo nó
    Node* novoNode = (Node*)malloc(sizeof(Node));   // novo struct "node"
    novoNode->valor = valor;
    novoNode->proximo = *head;
    // link do novo nó com o head
    *head = novoNode;
}

void inserirFinal(Node **head, int valor){
    // criando novo node AINDA NAO INSERIDO
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->valor = valor;
    novoNode->proximo = NULL;

    // inserindo novo node
    if(*head == NULL){
        *head = novoNode;   // aqui caso nao tenha nada em head, entao o ultimo é o primeiro
    }else{
        Node* atual = *head;
        while(atual->proximo != NULL){  // enquanto nao chegar no final:
            atual = atual->proximo;     // avança para o proximo nó
        }
        // chegou no final, entao o proximo é o novoNode
        atual->proximo = novoNode;      // ligando o ultimo nó (estamos nele) com o ao nó novo criado
    }
}