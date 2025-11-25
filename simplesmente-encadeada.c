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
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->valor = valor;
    novoNode->proximo = *head;
    // link do novo nó com o head
    *head = novoNode;
}