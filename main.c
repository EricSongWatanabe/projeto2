#include <stdio.h>
#include "biblioteca.h"

int main() {
  int cod;
  char arquivo[] = "clientes";
  ListaDeClientes lc;

  int codE;
  char arquivo1[] = "extratos.txt";
  ListaDeExtratos le;

  cod = carregarLista(&lc, arquivo); 
  if (cod == 1){
      lc.qtd = 0;
  }

  codE = carregarExtrato(&le, arquivo1); 
  if (codE == 1){
      le.qtd = 0;
  }

  int opcao;
  do {
    printMenu();
    scanf("%d", &opcao);
    printf("%d\n", opcao);

    if (opcao == 0){
    } 
    else if (opcao == 1){
      criarCliente(&lc, &le);
    }
    else if (opcao == 2){
      deletarCliente(&lc);
    }
    else if (opcao == 3) {
      listarCliente(lc);
    }
    else if (opcao == 4) {
      debito(&lc, &le);
    }
    else if (opcao == 5) {
      deposito(&lc, &le);
    }
    else if (opcao == 6) {
      extrato(&lc, &le, arquivo1);
    }
    else if (opcao == 7){
      transferencia(&lc, &le);
    }
    else {
      printf("\nOpcao nao existente!\n");
    }
  } while (opcao != 0);

  cod = salvarLista(lc, arquivo); 
  if (cod != 0){
      printf("\nErro ao salvar os clientes!\n");
  }

  codE = salvarExtrato(le, arquivo1); 
  if (codE != 0){
      printf("\nErro ao salvar os extratos!\n");
  }
}
