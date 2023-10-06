#include <stdio.h>
#include "biblioteca.h"

int main() {
    int cod;
    char arquivo[] = "clientes";
    ListaDeClientes lc;
    

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
        else {
            printf("Opcao nao existente!\n");
        }
    } while (opcao != 0);
}
