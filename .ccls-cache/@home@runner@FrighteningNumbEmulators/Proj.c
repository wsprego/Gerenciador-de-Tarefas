#include <stdio.h>
#include <stdlib.h> 
#include "Proj.h"

struct elemento {
    struct tarefas dados;
    struct elemento *prox;
};

Pilha* iniciar() {
  Pilha* pi = (Pilha *) malloc(sizeof(Pilha));
  if(pi != NULL)
    *pi = NULL;

  return pi;
}

int adicionar_trf(Pilha* pi, struct tarefas *trf) {
  if(pi == NULL)
    return 0;
  
  Elem* no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL)
    return 0;
    no->dados = *trf;
    no->prox = *pi;
    *pi = no;
  
  return 1;
}

int remover_trf(Pilha* pi, struct tarefas *trf) {
  if(pi == NULL)
    return 0;
  if((*pi) == NULL)
      return 0;
  
  Elem *no = *pi;
  *pi = no->prox; 
  free(no);
  
  return 1;
}

void imprimir(Pilha* pi) {
  if(pi == NULL)
    return;

  int count = 0;
  Elem* no = *pi;
    while(no != NULL){
        printf("Tarefa: %s\n",no->dados.nome_trf);
        no = no->prox;
        count++;
    }
   if(count == 0)
    pilha_vazia(pi);
    if(pilha_vazia(pi) != 0)
      printf("Nenhuma tarefa pendente.\n");
}

int pilha_vazia(Pilha* pi) {
  if(pi == NULL)
    return 1;
  if(*pi == NULL)
    return 1;
  
  return 0;
  
}

void desf_adc(Pilha* pend) {
  if(pend == NULL)
    return;
  if(*pend == NULL) {
    printf("ERRO: Pilha vazia.\n");
    return;
  }

  Elem* no = *pend;
  *pend = no->prox;
  free(no);

  printf("Operação 'Adicionar' desfeita.\n");
}

Elem* desf_remov(Pilha* pend) {
  if(pend == NULL)
    return 0;
  if(*pend == NULL) {
    printf("ERRO: Pilha vazia.\n");
    return 0;
  }

  Elem* no = *pend;
  Elem* no_ant = (Elem*) malloc(sizeof(Elem));
  no_ant->dados = no->dados;
  no_ant->prox = no;
  free(pend);

  printf("Operação 'Remover' desfeita.\n");
  
  return no_ant;
}