#ifndef LISTA_H
#define LISTA_H
#define MAX 100

typedef struct aluno {
    int mat;
    char nome[30];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

typedef struct lista Lista;

// Criação e destruição
Lista *cria_lista(void);
void liberar_mem(Lista **li);

// Consultas
int lista_vazia(const Lista *li);
int lista_cheia(const Lista *li);

// Inserções
int adicionar_inicio(Lista *li, Aluno aluno);
int adicionar_meio(Lista *li, Aluno aluno);
int adicionar_fim(Lista *li, Aluno aluno);
int adicionar_pos(Lista *li, int pos, Aluno aluno);

// Remoções
int remover_inicio(Lista *li);
int remover_meio(Lista *li);
int remover_final(Lista *li);
int remover_pos(Lista *li, int pos);

// Utilidades
void exibir_lista(const Lista *li);
#endif