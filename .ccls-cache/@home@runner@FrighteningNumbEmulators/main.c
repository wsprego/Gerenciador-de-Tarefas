#include <stdio.h>
#include <stdlib.h>
#include "Proj.h"

int main(void) {
  Pilha* pend = (Pilha *) malloc(sizeof(Pilha));
  Pilha* conc = (Pilha *) malloc(sizeof(Pilha));
  if(pend == NULL || conc == NULL)
    printf("Erro ao alocar memória.\n");

  pend = iniciar();
  conc = iniciar();

  int op = 0, desfazer, marcar_tarefa = 0, remover_tarefa;
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
          remover_trf(pend, remover_tarefa);
          printf("\nTarefa removida.\n\n");
        }
        else
          printf("Tarefa não removida.\n");
      break;
      case 3 :
        printf("\n");
      break;
      case 4 :
        printf("\n");
      break;
      case 5 :
        imprimir(pend);
        printf("\n");
      break;
      case 6 :
        printf("\n");
      break;
      case 7 :
        printf("DESFAZER - Digite o número da operação: ");
        scanf("%d", &desfazer);

        if(desfazer != 1 && desfazer != 2 && desfazer != 3 && desfazer != 4)
          printf("Não é possível desfazer esta operação.\n");
        else
          switch(desfazer) {
            case 1 :
              desf_adc(pend);
            break;
            case 2 :
              desf_remov(pend);
            break;
            case 3 :
            break;
            case 4 :
            break;
          }
        printf("\n");
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