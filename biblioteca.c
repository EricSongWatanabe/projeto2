#include "biblioteca.h"
#include <stdio.h>

void printMenu(){
    printf("\n========= MENU =========\n[1] Novo Cliente\n[2] Apagar Cliente\n[3] Listar Clientes\n[4] Debito\n[5] Deposito\n[6] Extrato\n[7] Transferencia entre Contas\n[0] Sair\n\nEscolha uma opcao: ");
}

int criarCliente(ListaDeClientes *lc) {
    printf("\nCriar cliente\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\nNome: ");
    fgets(lc->c[lc->qtd].nome, 20, stdin);
    lc->c[lc->qtd].nome[strcspn(lc->c[lc->qtd].nome, "\n")] = '\0';
    printf("\nCPF: ");
    scanf("%d", &lc->c[lc->qtd].cpf);
    printf("\nTipo de Conta (0 = Comum | 1 = Plus): ");
    scanf("%d", &lc->c[lc->qtd].tipoDeConta);
    if (lc->c[lc->qtd].tipoDeConta != 1 && lc->c[lc->qtd].tipoDeConta != 0){
      printf("\nNumero invalido!\n");
      return 0;
    }
    printf("\nValor Inicial: ");
    scanf("%d", &lc->c[lc->qtd].valor);
    printf("\nSenha: ");
    while ((c = getchar()) != '\n' && c != EOF) { }
    fgets(lc->c[lc->qtd].senha, 20, stdin);
    lc->c[lc->qtd].senha[strcspn(lc->c[lc->qtd].senha, "\n")] = '\0';
    

    printf("\n\nNome: %s", lc->c[lc->qtd].nome);
    printf("\nCPF: %d", lc->c[lc->qtd].cpf);
    printf("\nTipo de Conta: %d", lc->c[lc->qtd].tipoDeConta);
    printf("\nValor Inicial: %d", lc->c[lc->qtd].valor);
    printf("\nSenha: %s\n\n", lc->c[lc->qtd].senha);
    
    lc->qtd = lc->qtd + 1;
    return 0;
}

int deletarCliente(ListaDeClientes *lc) {
    printf("\nDeletar cliente\n");
    return 0;
}

int listarCliente(ListaDeClientes lc) {
    printf("\nListar CLientes\n");
    for (int i = 0; i < lc.qtd; i++){
        printf("\nCliente %d:\n", i + 1);
        printf("Nome: %s\n", lc.c[i].nome);
        printf("CPF: %d\n", lc.c[i].cpf);
        printf("Tipo de Conta: %d\n", lc.c[i].tipoDeConta);
        printf("Valor: %d\n", lc.c[i].valor);
    }
    return 0;
}