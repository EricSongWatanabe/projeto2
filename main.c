#include <stdio.h>
#include "biblioteca.h"

int main() {
  int cod;
  char arquivo[] = "clientes";
  ListaDeClientes lc;

  cod = carregarLista(&lc, arquivo); 
  if (cod == 1){
      lc.qtd = 0;
  }

  int opcao;
  do {
    printMenu();
    scanf("%d", &opcao);
    printf("%d\n", opcao);

    if (opcao == 0){
    } 
    else if (opcao == 1){
      criarCliente(&lc);
    }
    else if (opcao == 2){
      deletarCliente(&lc);
    }
    else if (opcao == 3) {
      listarCliente(lc);
    }
    else if (opcao == 4) {
      debito(&lc);
    }
    else if (opcao == 5) {
      deposito(&lc);
    }
    else if (opcao == 7){
      transferencia(&lc);
    }
    else {
      printf("\nOpcao nao existente!\n");
    }
  } while (opcao != 0);

  cod = salvarLista(lc, arquivo); 
  if (cod != 0)
      printf("\nErro ao salvar os clientes!\n");

}
