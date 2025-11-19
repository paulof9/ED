#ifndef LISTA_H
#define LISTA_H

typedef struct lista {
	int id;
	int value;
} Lista;

// Funções
Lista *cria_lista(void);
int adicionar_inicio(Lista *li, int id);
int adicionar_meio(Lista *li, int id);
int adicionar_fim(Lista *li, int id);
int adicionar_pos(Lista *li, int id);
int remover_item(Lista *li, int id);
void excluir_lista(Lista *li);
int lista_existe(const Lista *li);
int lista_vazia(const Lista *li);
// Menu e liberação de memória
void menu(Lista *li, int op, int id);
void liberar_mem(Lista **li);
#endif