#ifndef PROJETO2_BIBLIOTECA_H
#define PROJETO2_BIBLIOTECA_H

typedef struct extrato { // struct de operacoes no extrato
  char acao[255];
} Extratos;

typedef struct cliente { // struct de informacoes do cliente
  char nome[20];
  long cpf;
  int tipoDeConta;
  float valor;
  char senha[20];
  Extratos e[100];
  int qtd;
} Cliente;

typedef struct { // struct de lista de clientes
  Cliente c[1000];
  int qtd;
} ListaDeClientes;


void printMenu(); // cria a funcao de imprimir o menu

int buscaCliente(ListaDeClientes lc, long cpf); // cria a funcao de buscar clientes a partir do cpf

int criarCliente(ListaDeClientes *lc); // cria a funcao de criar clientes
int deletarCliente(ListaDeClientes *lc); // cria a funcao de deletar clientes
int listarCliente(ListaDeClientes lc); // cria a funcao de listar clientes
int debito(ListaDeClientes *lc); // cria a funcao de debito
int deposito(ListaDeClientes *lc); // cria a funcao de deposito
int extrato(ListaDeClientes *lc, Extratos e); // cria a funcao de extrato
int transferencia(ListaDeClientes *lc); // cria a funcao de transferencia

int salvarLista(ListaDeClientes lc, char nome[]); // cria a funcao de salvar a lista de clientes
int carregarLista(ListaDeClientes *lc, char nome[]); // cria a funcao de carregar a lista de clientes


#endif //PROJETO2_BIBLIOTECA_H
