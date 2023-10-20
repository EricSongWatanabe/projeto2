#ifndef PROJETO2_BIBLIOTECA_H
#define PROJETO2_BIBLIOTECA_H

typedef struct cliente {
  char nome[20];
  long cpf;
  int tipoDeConta;
  float valor;
  char senha[20];
} Cliente;

typedef struct {
  Cliente c[1000];
  int qtd;
} ListaDeClientes;

typedef struct extrato {
  char acao[255];
} Extrato;

typedef struct {
  Extrato e[100];
  int qtd;
} ListaDeExtratos;

void printMenu();

int buscaCliente(ListaDeClientes lc, long cpf);

int criarCliente(ListaDeClientes *lc, ListaDeExtratos *le);
int deletarCliente(ListaDeClientes *lc);
int listarCliente(ListaDeClientes lc);
int debito(ListaDeClientes *lc, ListaDeExtratos *le);
int deposito(ListaDeClientes *lc, ListaDeExtratos *le);
int extrato(ListaDeClientes *lc, ListaDeExtratos *le, char aquivo1[]);
int transferencia(ListaDeClientes *lc, ListaDeExtratos *le);

int salvarExtrato(ListaDeExtratos le, char nome[]);
int carregarExtrato(ListaDeExtratos *le, char nome[]);

int salvarLista(ListaDeClientes lc, char nome[]);
int carregarLista(ListaDeClientes *lc, char nome[]);


#endif //PROJETO2_BIBLIOTECA_H
