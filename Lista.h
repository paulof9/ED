#ifndef LISTA_H
#define LISTA_H

typedef struct lista {
	int id;
	int value;
} Lista;

Lista *cria_lista(void);
int lista_vazia(const Lista *li);
void liberar_mem(Lista **li);

#endif /* LISTA_H */
