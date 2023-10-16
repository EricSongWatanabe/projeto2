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

void printMenu();

int buscaCliente(ListaDeClientes lc, long cpf);

int criarCliente(ListaDeClientes *lc);
int deletarCliente(ListaDeClientes *lc);
int listarCliente(ListaDeClientes lc);
int debito(ListaDeClientes *lc);


int salvarLista(ListaDeClientes lc, char nome[]);
int carregarLista(ListaDeClientes *lc, char nome[]);

#endif //PROJETO2_BIBLIOTECA_H
