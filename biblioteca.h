#ifndef PROJETO2_BIBLIOTECA_H
#define PROJETO2_BIBLIOTECA_H

typedef struct extrato {
  char acao[255];
} Extratos;

typedef struct cliente {
  char nome[20];
  long cpf;
  int tipoDeConta;
  float valor;
  char senha[20];
  Extratos e[100];
  int qtd;
} Cliente;

typedef struct {
  Cliente c[10];
  int qtd;
} ListaDeClientes;


void printMenu();

int buscaCliente(ListaDeClientes lc, long cpf);

int criarCliente(ListaDeClientes *lc);
int deletarCliente(ListaDeClientes *lc);
int listarCliente(ListaDeClientes lc);
int debito(ListaDeClientes *lc);
int deposito(ListaDeClientes *lc);
int extrato(ListaDeClientes *lc, Extratos e);
int transferencia(ListaDeClientes *lc);

// int salvarExtrato(Extratos e, char nome[]);
// int carregarExtrato(Extratos *e, char nome[]);

// int salvarLista(ListaDeClientes lc, char nome[]);
// int carregarLista(ListaDeClientes *lc, char nome[]);


#endif //PROJETO2_BIBLIOTECA_H
