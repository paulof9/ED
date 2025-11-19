#ifndef LISTA_H
#define LISTA_H
#define MAX 100

struct aluno {
	int mat;
    char nome[30];
    int nota1, nota2, nota3
};

typedef struct lista Lista;

// Funções
Lista *cria_lista();
int adicionar_inicio(Lista *li);
int adicionar_meio(Lista *li);
int adicionar_fim(Lista *li);
int adicionar_pos(Lista *li, int pos);
int remover_inicio(Lista *li);
int remover_meio(Lista *li);
int remover_final(Lista *li);
int remover_pos(Lista *li, int pos);
int lista_vazia(Lista *li);
void liberar_mem(Lista **li);
#endif