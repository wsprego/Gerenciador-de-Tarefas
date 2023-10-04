struct tarefas {
  char nome_trf[30];
};
typedef struct elemento* Pilha;
typedef struct elemento* Pilha1;
typedef struct elemento* PilhaA;
typedef struct elemento* Pilha2;
typedef struct elemento Elem;

// funções basicas da pilha dinamica
Pilha* iniciar();
Pilha1* iniciar_conc();
void liberar_pilha(Pilha* pi);
int consulta_topo_pilha(Pilha* pi, struct aluno *al);
int inserir(Pilha* pi, struct aluno al);
void imprimir_conc(Pilha1* conc);
PilhaA* remover(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int pilha_cheia(Pilha* pi);
void imprimir_pend(Pilha* pi);

//funções do projeto
int adicionar_trf(Pilha* pi, struct tarefas *trf); // essa é quase a mesma coisa que a fc inserir
int adicionar_conc(Pilha1* conc, Pilha* pend);
int remover_trf(Pilha* pi); // essa é quase a mesma coisa que a fc remover
char trf_removi(Pilha* piAux, struct tarefas *trf);
void desf_adc(Pilha* pend);
Elem* desf_remov(Pilha* pend);
int adicionar_desfaz(Pilha1* conc, Pilha2* desfaz);
void imprimir_desfaz(Pilha2* desfaz, Pilha1* conc);
