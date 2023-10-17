#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

void printMenu(){
    printf("\n========= MENU =========\n[1] Novo Cliente\n[2] Apagar Cliente\n[3] Listar Clientes\n[4] Debito\n[5] Deposito\n[6] Extrato\n[7] Transferencia entre Contas\n[0] Sair\n\nEscolha uma opcao: ");
}

int buscaCliente(ListaDeClientes lc, long cpf){
    int index = 0;
    for (index; index < 1000; index++){
        if (lc.c[index].cpf == cpf){
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
    int indexCliente = buscaCliente(*lc, cpf);
    if (indexCliente == -1) {
        lc->c[lc->qtd].cpf = cpf;
        printf("\nTipo de Conta (0 = Comum | 1 = Plus): ");
    }

    scanf("%d", &lc->c[lc->qtd].tipoDeConta);
    if (lc->c[lc->qtd].tipoDeConta != 1 && lc->c[lc->qtd].tipoDeConta != 0){
      printf("\nNumero invalido!\n");
      return 0;
    }

    printf("\nValor Inicial: ");
    scanf("%f", &lc->c[lc->qtd].valor);

    printf("\nSenha: ");
    while ((c = getchar()) != '\n' && c != EOF) { }
    fgets(lc->c[lc->qtd].senha, 20, stdin);
    lc->c[lc->qtd].senha[strcspn(lc->c[lc->qtd].senha, "\n")] = '\0';


    printf("\n\nNome: %s", lc->c[lc->qtd].nome);
    printf("\nCPF: %d", lc->c[lc->qtd].cpf);
    printf("\nTipo de Conta : %d", lc->c[lc->qtd].tipoDeConta);
    printf("\nValor Inicial: %.2f", lc->c[lc->qtd].valor);
    printf("\nSenha: %s\n\n", lc->c[lc->qtd].senha);

    lc->qtd = lc->qtd + 1;
    return 0;
}

int deletarCliente(ListaDeClientes *lc) {
  printf("\nDeletar cliente\n");
  long cpf;
  printf("Digite o CPF do cliente que deseja deletar: ");
  scanf("%ld", &cpf);

  int indexCliente = buscaCliente(*lc, cpf);
  if (indexCliente == -1) {
      printf("Cliente com CPF %ld não encontrado na lista.\n", cpf);
    return 0;
  }


  for (int j = indexCliente; j < lc->qtd - 1; j++) {
      lc->c[j] = lc->c[j + 1];
  }
  lc->qtd--;
  printf("Cliente com CPF %d foi deletado com sucesso.\n", cpf);
  return 0;
}

int listarCliente(ListaDeClientes lc) {
    printf("\nListar CLientes\n");
    for (int i = 0; i < lc.qtd; i++){
        printf("\nCliente %d:\n", i + 1);
        printf("Nome: %s\n", lc.c[i].nome);
        printf("CPF: %ld\n", lc.c[i].cpf);
        printf("Tipo de Conta (0 = Comum | 1 = Plus): %d\n", lc.c[i].tipoDeConta);
        printf("Valor: %.2f\n", lc.c[i].valor);
    }
    return 0;
}

int debito(ListaDeClientes *lc) {
  printf("\nDebito\n");
  long cpf;
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf);

  int indexCliente = buscaCliente(*lc, cpf);

  if (indexCliente == -1){
    printf("Cliente nao encontrado");
    return 0;
  }

  float valor;
  char senha[20];
  printf("\nDigite sua senha: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
  fgets(senha, 20, stdin);
  senha[strcspn(senha, "\n")] = '\0';


  int verificacaoSenha = strcmp(lc->c[indexCliente].senha, senha);

  if (verificacaoSenha == 0){
    float debito;
    printf("\nDigite o valor a ser debitado: ");
    scanf("%f", &debito);

    if (lc->c[indexCliente].tipoDeConta == 0){
      lc->c[indexCliente].valor = lc->c[indexCliente].valor - 1.05 * debito;
      if (lc->c[indexCliente].valor <= -1000){
        printf("\nSaldo negativo atingido! Nao foi possivel concluir a acao.\n");
        lc->c[indexCliente].valor = lc->c[indexCliente].valor + 1.05 * debito;
        return 0;
      }
        printf("\nDebito realizado com sucesso!\n");
    }

    else if (lc->c[indexCliente].tipoDeConta == 1){
      lc->c[indexCliente].valor = lc->c[indexCliente].valor - 1.03 * debito;
      if (lc->c[indexCliente].valor <= -5000){
        printf("\nSaldo negativo atingido! Nao foi possivel concluir a acao.\n");
        lc->c[indexCliente].valor = lc->c[indexCliente].valor + 1.03 * debito;
        return 0;
      }
        printf("\nDebito realizado com sucesso!\n");
    }
  }

  else {
    printf("\nSenha incorreta.\n");
    return 0;
  }


    return 0;
}

int deposito(ListaDeClientes *lc){
  printf("\nDeposito\n");
  long cpf;
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf);

  int indexCliente = buscaCliente(*lc, cpf);

  if (indexCliente == -1){
    printf("\nCliente nao encontrado\n");
    return 0;
  }

  else {
    float deposito;
    printf("\nDigite o valor a ser depositado: ");
    scanf("%f", &deposito);
    lc->c[indexCliente].valor = lc->c[indexCliente].valor + deposito;
    printf("\nDeposito realizado com sucesso!\n");
  }

  return 0;
}

int transferencia(ListaDeClientes *lc){
  printf("\nTransferencia\n");
  long cpf1;
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf1);

  int indexCliente1 = buscaCliente(*lc, cpf1);

  if (indexCliente1 == -1){
    printf("\nCliente nao encontrado\n");
    return 0;
  }

  char senha[20];
  printf("\nDigite sua senha: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
  fgets(senha, 20, stdin);
  senha[strcspn(senha, "\n")] = '\0';

  int verificacaoSenha = strcmp(lc->c[indexCliente1].senha, senha);

  if (verificacaoSenha == 0){
    long cpf2;
    printf("\nDigite o CPF do destinatario: ");
    scanf("%ld", &cpf2);

    int indexCliente2 = buscaCliente(*lc, cpf2);

    float valor;
    printf("\nDigite o valor a ser transferido: ");
    scanf("%f", &valor);
    if (lc->c[indexCliente1].tipoDeConta == 0){
      lc->c[indexCliente2].valor = lc->c[indexCliente2].valor + valor;
      lc->c[indexCliente1].valor = lc->c[indexCliente1].valor - valor * 1.05;
    }
    else if (lc->c[indexCliente1].tipoDeConta == 1){
      lc->c[indexCliente2].valor = lc->c[indexCliente2].valor + valor;
      lc->c[indexCliente1].valor = lc->c[indexCliente1].valor - valor * 1.03;
    }
    
    if (indexCliente2 == -1){
      printf("\nCliente nao encontrado\n");
      return 0;
    }
  }
  else {
    printf("\nSenha incorreta.\n");
    return 0;
  }
  return 0;
}