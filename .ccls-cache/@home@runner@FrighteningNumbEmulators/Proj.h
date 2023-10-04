struct tarefas {
  char nome_trf[30];
};
typedef struct elemento* Pilha;
typedef struct elemento Elem;

// funções basicas da pilha dinamica
Pilha* iniciar();
void liberar_pilha(Pilha* pi);
int consulta_topo_pilha(Pilha* pi, struct aluno *al);
int inserir(Pilha* pi, struct aluno al);
int remover(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int pilha_cheia(Pilha* pi);
void imprimir(Pilha* pi);

//funções do projeto
int adicionar_trf(Pilha* pi, struct tarefas *trf); // essa é quase a mesma coisa que a fc inserir
int remover_trf(Pilha* pi, struct tarefas *trf); // essa é quase a mesma coisa que a fc remover
void desf_adc(Pilha* pend);
Elem* desf_remov(Pilha* pend);
