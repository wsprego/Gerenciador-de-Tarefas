#include <stdio.h>
#include <stdlib.h>
#include "Proj.h"

int main(void) {
  PilhaA* piAux = (Pilha *) malloc(sizeof(Pilha));
  Pilha* pend = (Pilha *) malloc(sizeof(Pilha));
  Pilha1* conc = (Pilha *) malloc(sizeof(Pilha));
  Pilha2* desfaz = (Pilha *) malloc(sizeof(Pilha));
  if(pend == NULL || conc == NULL || piAux == NULL || desfaz == NULL)
    printf("Erro ao alocar memória.\n");

  pend = iniciar();
  conc = iniciar();
  piAux = iniciar();
  desfaz = iniciar();
  
  int op = 0,op2=0, desfazer, marcar_tarefa = 0, desfazer_conc, remover_tarefa;
  char tarefa[30];
  Elem* tst;
  printf("BEM-VINDO AO SEU GERENCIADOR DE TAREFAS!\n\n");
  do {
    printf("\n\n");
    printf("== MENU DE OPERAÇÕES ==\n\n");
    printf("0 - SAIR\n");
    printf("1 - ADICIONAR TAREFAS\n");
    printf("2 - REMOVER TAREFAS\n");
    printf("3 - MARCAR TAREFA COMO CONCLUÍDA\n");
    printf("4 - DESFAZER A MARCAÇÃO DE UMA TAREFA CONCLUÍDA\n");
    printf("5 - LISTAR TAREFAS PENDENTES\n");
    printf("6 - LISTAR TAREFAS CONCLUÍDAS\n");
    printf("7 - DESFAZER OPERAÇÃO\n");
    printf("\n");

    printf("Realizar operação... ");
    scanf("%d", &op);

    switch(op) {
      case 0 :
        printf("Encerrando...\n");
      break;
      case 1 :
        printf("ADICIONAR - Nome da tarefa: ");
        scanf(" %s[^\n]", tarefa);

        adicionar_trf(pend, tarefa);
        printf("\nTarefa adicionada.\n\n");
      break;
      case 2 :
        printf("REMOVER - Remover a última tarefa? 1 - SIM: ");
        scanf("%d", &remover_tarefa);

        if(remover_tarefa == 1) {
          adicionar_conc(desfaz, pend);
          remover_trf(pend);
          printf("\nTarefa removida.\n\n");

        }
        else
          printf("Tarefa não removida.\n");
      break;
      case 3 :
        printf("voce marcou como concluida a ultima tarefa\n 1-sim 2-nao");
        scanf("%d", &remover_tarefa);

        if(remover_tarefa == 1){
          adicionar_conc(conc, pend);
          remover_trf(pend);
        }
        printf("\nTarefa foi concluida...\n");
      break;
      case 4 :
        printf("DESFAZER a marcação da última tarefa concluída?\n (essa tarefa ficar no fim da fila)\n1 - SIM / 2 - NÃO: ");
        scanf("%d", &desfazer_conc);

        if(desfazer_conc == 1) {
          adicionar_conc(pend, conc);
          //adicionar_desfaz(conc, desfaz); nao pecisa mais.
          remover_trf(conc);
          printf("Tarefa desmarcada.\n");
        }
        else
          printf("Tarefa inalterada.\n");
        printf("\n");
        printf("\n");
      break;
      case 5:
        printf("\nTarefas pendentes:\n\n");
        imprimir_pend(pend);
        //imprimir_desfaz(desfaz, pend);noa pecisa mais.
        printf("\n");
      break;
      case 6 :
        imprimir_conc(conc);
        printf("\n");
      break;
      case 7 :
        printf("\n>>>QUAL OPERAÇÃO DEVE SER DESFEITA:\n");
        printf("0 - Volta para o inicio\n");
        printf("1 - DESFEITA: ADICIONAR TAREFAS\n");
        printf("2 - DESFEITA: REMOVER TAREFAS\n");
        printf("3 - DESFEITA: MARCAR TAREFA COMO CONCLUÍDA\n");
        printf("4 - DESFEITA: DESFAZER A MARCAÇÃO DE UMA TAREFA CONCLUÍDA\n");
        scanf("%d", &op2);
          switch(op2) {
          case 0 : 
          break;
          case 1:
            remover_trf(pend);
          break;
          case 2:
            adicionar_conc(pend, desfaz);
          break;
          case 3:
            adicionar_conc(pend, conc);
            remover_trf(conc);
          break;
          case 4:
            adicionar_conc(conc, pend);
            remover_trf(pend);
          break; 
          default :
          printf("ERRO: Operação inexistente.\n");
          break;
          }
      break;
      
      default :
        printf("ERRO: Operação inexistente.\n");
      break;
    }
  } while(op != 0);
  printf("\n");
  printf("Obrigado por utilizar o sistema.\n");

  return 0;
}