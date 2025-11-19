#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista {
    int qtd;
    Aluno dados[MAX];
};

Lista *cria_lista(void){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

int lista_vazia(const Lista *li){
    if(li == NULL)
        return 1;
    return li->qtd == 0;
}

int lista_cheia(const Lista *li){
    if(li == NULL)
        return 0;
    return li->qtd == MAX;
}

/* Antes você fazia li->dados[i] = li->dados[i+1] nas inserções (entao eu fazia o contrario do que deveria ser feito), o que sobrescrevia
 * os elementos existentes e ainda não escrevia o novo aluno em lugar nenhum.
 * Centralizamos o deslocamento em uma função auxiliar para garantir que os espaços
 * sejam abertos na direção correta (do fim para o início). */
static int inserir_na_posicao(Lista *li, int pos, Aluno aluno){
    if(li == NULL || lista_cheia(li) || pos < 0 || pos > li->qtd)
        return 0;

    // pq do fim ao inicio?
    // Porque ao inserir precisamos abrir espaço deslocando para a direita. Se começarmos do início,
    // sobrescrevemos li->dados[0] antes de copiá-lo. Movendo do fim (qtd-1 até pos) preservamos
    // cada elemento e só depois gravamos o novo aluno na posição desejada.
    for(int i = li->qtd - 1; i >= pos; i--){
        li->dados[i + 1] = li->dados[i];
    }
    li->dados[pos] = aluno;
    li->qtd++;
    return 1;
}

/* Nas remoções anteriores você só fazia li->qtd-- sem limpar o "buraco".
 * Agora deslocamos os elementos para fechar o espaço e manter a ordem. */
static int remover_na_posicao(Lista *li, int pos){
    if(li == NULL || lista_vazia(li) || pos < 0 || pos >= li->qtd)
        return 0;

    for(int i = pos; i < li->qtd - 1; i++){
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}

int adicionar_inicio(Lista *li, Aluno aluno){
    return inserir_na_posicao(li, 0, aluno);
}

int adicionar_meio(Lista *li, Aluno aluno){
    if(li == NULL)
        return 0;
    int meio = li->qtd / 2; // novo aluno cai exatamente no meio atual
    // e se for impar?
    // A divisão inteira já arredonda para baixo (ex.: 5/2 == 2), então o novo elemento fica no meio "inferior".
    return inserir_na_posicao(li, meio, aluno);
}

int adicionar_fim(Lista *li, Aluno aluno){
    if(li == NULL)
        return 0;
    return inserir_na_posicao(li, li->qtd, aluno);
}
// qual a diferença de adicionar e de inserir na posicao?
// As funções adicionar_* são a interface pública e apenas chamam inserir_na_posicao com o índice certo,
// deixando o código de quem usa a lista mais semântico (início/meio/fim sem precisar calcular pos).
int adicionar_pos(Lista *li, int pos, Aluno aluno){
    return inserir_na_posicao(li, pos, aluno);
}

int remover_inicio(Lista *li){
    return remover_na_posicao(li, 0);
}

int remover_meio(Lista *li){
    if(li == NULL)
        return 0;
    int meio = (li->qtd - 1) / 2; // remove o elemento central real
    return remover_na_posicao(li, meio);
}

// delega a remover_na_posicao, mesma ideia das inserções: apenas calcula o índice do último elemento
int remover_final(Lista *li){
    if(li == NULL)
        return 0;
    return remover_na_posicao(li, li->qtd - 1);
}

int remover_pos(Lista *li, int pos){
    return remover_na_posicao(li, pos);
}

void exibir_lista(const Lista *li){
    if(li == NULL){
        printf("Lista inexistente.\n");
        return;
    }
    if(lista_vazia(li)){
        printf("Lista vazia.\n");
        return;
    }

    for(int i = 0; i < li->qtd; i++){
        const Aluno *al = &li->dados[i];
        printf("[%d] Matricula:%d Nome:%s Notas: %.1f %.1f %.1f\n",
               i, al->mat, al->nome, al->nota1, al->nota2, al->nota3);
    }
}

void liberar_mem(Lista **li){
    if(li == NULL || *li == NULL)
        return;
    free(*li);
    *li = NULL;
}