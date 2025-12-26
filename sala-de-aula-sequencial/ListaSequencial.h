#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 100

typedef struct aluno {
    int mat;
    char nome[30];
    float n1, n2, n3;
} Aluno;

typedef struct lista Lista;

Lista *criar_lista(void);
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int inserir_final(Lista *li, Aluno al);
int inserir_inicio(Lista *li, Aluno al);
int inserir_meio(Lista *li, Aluno al);
int inserir_ordenado(Lista *li, Aluno al);
int remove_final(Lista *li);
int remove_lista(Lista *li, int mat);
int remove_retorna_lista(Lista *li, int mat, Aluno *al, int *pos);
int consulta_lista_pos(Lista *li, int pos, Aluno *al);
int consulta_lista_mat(Lista *li, int mat, Aluno *al);
void imprime_lista(Lista *li);

#endif