#include <stdio.h>
#include "biblioteca.h"

int main() {
  int cod; // cria a variavel para verificar o arquivo
  char arquivo[] = "clientes"; // define o nome do arquivo
  ListaDeClientes lc; // cria a variavel da lista de clientes

  Extratos e; // cria a variavel dos extratos

  cod = carregarLista(&lc, arquivo);  // chama a funcao de carregar a lista
  if (cod == 1){ // caso a funcao retornar 1 a lista eh zerada
      lc.qtd = 0;
  }

  int opcao; // cria a variavel de opcao do menu
  do { // loop do menu
    printMenu(); // chama a funcao de imprimir o menu
    scanf("%d", &opcao); // recebe a opcao escolhida
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { } // limpa o buffer

    if (opcao == 0){ // caso a opcao seja 0
    } 
    else if (opcao == 1){ // caso a opcao seja 1
      criarCliente(&lc); // chama a funcao de criar cliente
    }
    else if (opcao == 2){ // caso a opcao seja 2
      deletarCliente(&lc); // chama a funcao de deletar cliente
    }
    else if (opcao == 3) { // caso a opcao seja 3
      listarCliente(lc); // chama a funcao de listar cliente
    }
    else if (opcao == 4) { // caso a opcao seja 4
      debito(&lc); // chama a funcao de debito
    }
    else if (opcao == 5) { // caso a opcao seja 5
      deposito(&lc); // chama a funcao de deposito
    }
    else if (opcao == 6) { // caso a opcao seja 6
      extrato(&lc, e); // chama a funcao de extrato
    }
    else if (opcao == 7){ // caso a opcao seja 7
      transferencia(&lc); // chama a funcao de transferencia
    }
    else { // caso a opcao nao exista
      printf("\nOpcao nao existente!\n");
    }
  } while (opcao != 0); // se a opcao for 0, o loop se encerra

  cod = salvarLista(lc, arquivo); // chama funcao de salvar a lista
  if (cod != 0){ // caso a funcao retorne algo diferente de 0, imprime a mensagem de erro
      printf("\nErro ao salvar os clientes!\n");
  }

}
