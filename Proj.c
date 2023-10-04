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

Pilha1* iniciar_conc() {
  Pilha1* conc = (Pilha *) malloc(sizeof(Pilha));
  if(conc != NULL)
    *conc = NULL;

  return conc;
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

int adicionar_conc(Pilha1* conc, Pilha* pend) {
  if(conc == NULL)
    return 0;
  
  Elem* no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL)
    return 0;
    
  no->dados = (*pend)->dados;
  no->prox = *conc;
  *conc = no;
  
  return 1;
}

int adicionar_desfaz(Pilha1* conc, Pilha2* desfaz) {
  if(conc == NULL || desfaz == NULL)
    return 0;
  
  Elem* no = (Elem *) malloc(sizeof(Elem));
  if(no == NULL)
    return 0;
    
    no->dados = (*conc)->dados;
    no->prox = *desfaz;
    *desfaz = no;
  
  return 1;
}
int consulta_topo_Pilha(Pilha pi, struct tarefas *trf){
    if(pi == NULL)
        return 0;
    if((pi) == NULL)
        return 0;
  
    *trf = (pi)->dados;
    return 1;
}

int remover_trf(Pilha* pi) {
  if(pi == NULL)
    return 0;
  if((*pi) == NULL)
      return 0;

  Elem *no = *pi;
  Elem *removi = *pi;
  *pi = no->prox;
  
  free(no);
  return 1;
}

void imprimir_pend(Pilha* pi) {
  int cont = 0;
  
  if(pi == NULL)
    return;

  Elem* no = *pi;
    while(no != NULL){
        printf("Tarefa: %s\n",no->dados.nome_trf);
        no = no->prox;
        cont++;
    }
  
  if(cont == 0){
    printf("Nemhuma tarefa pendente\n");
  }
}

void imprimir_desfaz(Pilha2* desfaz, Pilha1* conc) {
  if(desfaz == NULL)
    return;


  Elem* no = *desfaz;
    while(no != NULL){
      printf("Tarefa: %s\n",no->dados.nome_trf);
      no = no->prox;
      
    }
   
}

void imprimir_conc(Pilha1* conc) {
  if(conc == NULL)
    return;

  int count = 0;
  Elem* no = *conc;
  printf("Tarefas concluidas:\n\n");
    while(no != NULL){
      printf("Tarefa: %s\n",no->dados.nome_trf);
      no = no->prox;
      count++;
    }
   if(count == 0)
    pilha_vazia(conc);
    if(pilha_vazia(conc) != 0)
      printf("Nenhuma tarefa concluida.\n");
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

PilhaA* remover(Pilha* pi) {
  if(pi == NULL)
    return 0;
  if((*pi) == NULL)
      return 0;

  Elem *no = *pi;
  Elem *removi = *pi;
  *pi = no->prox;
  
  free(no);
  return 1;

}