#include "biblioteca.h"
#include <stdio.h>

void printMenu(){
    printf("\n========= MENU =========\n[1] Novo Cliente\n[2] Apagar Cliente\n[3] Listar Clientes\n[4] Debito\n[5] Deposito\n[6] Extrato\n[7] Transferencia entre Contas\n[0] Sair\n\nEscolha uma opcao: ");
}

int buscaCliente(ListaDeClientes lc, long cpf){
    int index = 0;
    for (index; index < 1000; index++){
        if (lc.c[lc.qtd].cpf == cpf){
            return index;
        }
    }
    return -1;
}

int criarCliente(ListaDeClientes *lc) {
    printf("\nCriar cliente\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("\nNome: ");
    fgets(lc->c[lc->qtd].nome, 20, stdin);
    lc->c[lc->qtd].nome[strcspn(lc->c[lc->qtd].nome, "\n")] = '\0';

    long cpf;
    printf("\nCPF: ");
    scanf("%ld", &cpf);
    int busca = buscaCliente(ListaDeClientes, cpf);
    if (busca == -1) {
        printf("\nTipo de Conta (0 = Comum | 1 = Plus): ");
    }
    
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
    int cpf;
    printf("Digite o CPF do cliente que deseja deletar: ");
    scanf("%d", &cpf);

    int encontrado = 0;  

    for (int i = 0; i < lc->qtd; i++) {
        if (lc->c[i].cpf == cpf) {
            for (int j = i; j < lc->qtd - 1; j++) {
                lc->c[j] = lc->c[j + 1];
            }
            lc->qtd--;
            printf("Cliente com CPF %d foi deletado com sucesso.\n", cpf);
            encontrado = 1; 
            break;
        }
    }
    if (!encontrado) {
        printf("Cliente com CPF %d não encontrado na lista.\n", cpf);
    }

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

int debito(ListaDeClientes *lc) {
    printf("\nDebito\n");
    long cpf;
    printf("Digite seu CPF: ");
    scanf("%d", &cpf);

    int encontrado = 0;  

    int indexCliente = 0;

    for (int i = 0; i < lc->qtd; i++) {
        if (lc->c[i].cpf == cpf) {
            indexCliente = i;
            encontrado = 1;
            break 
        
        
            char = senha[20];
            printf("Digite sua senha: ");
            while ((c = getchar()) != '\n' && c != EOF) { }
            fgets(senha, 20, stdin);
            if (lc->c[i].senha == senha){
                int debito;
                printf("Digite o valor a ser debitado: ");
                scanf("%d", &debito);
                if (lc->c[i].tipoDeConta == 0){
                    if (lc->c[i].valor >= -1000){
                        lc->c[i].valor = lc->c[i].valor - debito * 0.05;
                    }
                    
                }
                else if(lc->c[i].tipoDeConta == 1){
                    lc->c[i].valor = lc->c[i].valor - debito * 0.03;
                }
            }

            break;
        }
    }
    if (!encontrado) {
        printf("Cliente com CPF %d não encontrado na lista.\n", cpf);
    }

}