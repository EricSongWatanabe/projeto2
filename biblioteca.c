#include "biblioteca.h"
#include <stdio.h> 
#include <string.h>

void printMenu(){ // função print menu
  printf("\n========= MENU =========\n[1] Novo Cliente\n[2] Apagar Cliente\n[3] Listar Clientes\n[4] Debito\n[5] Deposito\n[6] Extrato\n[7] Transferencia entre Contas\n[0] Sair\n\nEscolha uma opcao: ");
}

int buscaCliente(ListaDeClientes lc, long cpf){ // funcao de buscar o cliente a partir do cpf
  int index = 0;
  for (index; index < 1000; index++){ // percorre por toda a lista de clientes ate achar o cpf digitado
    if (lc.c[index].cpf == cpf){
    return index; // retorna o index do cliente
    }  
  }
  return -1; // caso nao encontre, retorna -1
  }

int criarCliente(ListaDeClientes *lc) { // funcao de criar o cliente
  printf("\nCriar cliente\n");
  int c;

  printf("\nNome: ");
  fgets(lc->c[lc->qtd].nome, 20, stdin); // armazena a variavel nome
  lc->c[lc->qtd].nome[strcspn(lc->c[lc->qtd].nome, "\n")] = '\0'; 

  long cpf;
  printf("\nCPF: ");
  scanf("%ld", &cpf); // armazena a variavel cpf
  
  int indexCliente = buscaCliente(*lc, cpf);
  if (indexCliente == -1) { // caso nao encontre o cpf na lista, a funcao continua
    lc->c[lc->qtd].cpf = cpf;
    printf("\nTipo de Conta (0 = Comum | 1 = Plus): ");
  }

  else{ // caso encontre o cpf, a funcao para
    printf("\nCPF ja existente!\n");
    return 0;
  }

  scanf("%d", &lc->c[lc->qtd].tipoDeConta); // armazena a variavel tipo de conta
  if (lc->c[lc->qtd].tipoDeConta != 1 && lc->c[lc->qtd].tipoDeConta != 0){ // caso o usuario digite um tipo de conta que nao existe
    printf("\nNumero invalido!\n");
    return 0;
  }

  printf("\nValor Inicial: ");
  scanf("%f", &lc->c[lc->qtd].valor); // armazen a variavel valor inicial

  printf("\nSenha: ");
  while ((c = getchar()) != '\n' && c != EOF) { } // limpar o buffer
  fgets(lc->c[lc->qtd].senha, 20, stdin); // armazena a variavel senha 
  lc->c[lc->qtd].senha[strcspn(lc->c[lc->qtd].senha, "\n")] = '\0';

  printf("Cliente criado com sucesso!\n"); // imprime as informacoes cadastradas 
  printf("\n\nNome: %s", lc->c[lc->qtd].nome); // imprime as informacoes cadastradas
  printf("\nCPF: %ld", lc->c[lc->qtd].cpf); // imprime as informacoes cadastradas
  printf("\nTipo de Conta : %d", lc->c[lc->qtd].tipoDeConta); // imprime as informacoes cadastradas
  printf("\nValor Inicial: %.2f", lc->c[lc->qtd].valor); // imprime as informacoes cadastradas
  printf("\nSenha: %s\n\n", lc->c[lc->qtd].senha); // imprime as informacoes cadastradas
  lc->qtd = lc->qtd + 1; // aumenta a quantidade de clientes em 1
  return 0;
}

int deletarCliente(ListaDeClientes *lc) { // funcao de deletar cliente
  printf("\nDeletar cliente\n");
  long cpf;  // cria a variavel cpf para a busca
  printf("Digite o CPF do cliente que deseja deletar: ");
  scanf("%ld", &cpf); // armazena a variavel cpf

int indexCliente = buscaCliente(*lc, cpf); // chama a funcao de busca do cliente a partir do cpf
  if (indexCliente == -1) {  // caso nao encontre o cpf na lista
    printf("Cliente com CPF %ld não encontrado na lista.\n", cpf);
    return 0;
  }


  for (int j = indexCliente; j < lc->qtd - 1; j++) {
    lc->c[j] = lc->c[j + 1]; // substitui todos os clientes criados apos o cliente deletado e os coloca em uma posicao anterior a que eles estavam
  }
  lc->qtd--; // reduz a quantidade em 1
  printf("Cliente com CPF %ld foi deletado com sucesso.\n", cpf); 
  return 0;
}

int listarCliente(ListaDeClientes lc) { // funcao de listar os clientes
  printf("\nListar CLientes\n");
    for (int i = 0; i < lc.qtd; i++){ // percorre por todos os clientes e imprime suas informacoes
      printf("\nCliente %d:\n", i + 1);
      printf("Nome: %s\n", lc.c[i].nome);
      printf("CPF: %ld\n", lc.c[i].cpf);
      if (lc.c[i].tipoDeConta == 0){ // se o tipo de conta for igual a 0, imprime como comum
        printf("Tipo de Conta: Comum\n");
      }
      else if (lc.c[i].tipoDeConta == 1){ // se o tipo de conta for igual a 1, imprime como plus
        printf("Tipo de Conta: Plus\n");
      }
      printf("Valor: %.2f\n", lc.c[i].valor);
    }
  return 0;
}

int debito(ListaDeClientes *lc) { // funcao de debito
  printf("\nDebito\n");
  long cpf; // cria variavel cpf
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf);

  int indexCliente = buscaCliente(*lc, cpf); // chama a funcao de busca do cliente pelo cpf

  if (indexCliente == -1){ // caso a funcao nao encontre o cliente
    printf("\nCliente nao encontrado\n");
    return 0;
  }

  char senha[20];
  printf("\nDigite sua senha: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { } // limpa buffer
  fgets(senha, 20, stdin); // recebe a senha digitada pelo ususario 
  senha[strcspn(senha, "\n")] = '\0';

  int verificacaoSenha = strcmp(lc->c[indexCliente].senha, senha); // funcao para comparar strings e verificar a senha

  if (verificacaoSenha == 0){ // caso a string senha sejam igual a cadastrada pelo usuario
    float debito; // define o valor a ser debitado
    printf("\nDigite o valor a ser debitado: ");
    scanf("%f", &debito);

    if (lc->c[indexCliente].tipoDeConta == 0){ // caso o tipo de conta for comum
      lc->c[indexCliente].valor = lc->c[indexCliente].valor - 1.05 * debito; // retira o valor e adiciona uma taxa
      sprintf(lc->c[indexCliente].e[lc->c[indexCliente].qtd].acao, "Acao: Debito | Valor: -%.2f | Taxa: 0.5%%", debito); // salva no extrato
      lc->c[indexCliente].qtd = lc->c[indexCliente].qtd + 1; // aumenta a quantidade de operacoes no extrato em 1
      
      if (lc->c[indexCliente].valor <= -1000){ // caso passe do limite minimo da conta
        printf("\nSaldo negativo atingido! Nao foi possivel concluir a acao.\n");
        lc->c[indexCliente].valor = lc->c[indexCliente].valor + 1.05 * debito; // retorna o valor para a conta 
        return 0;
      }
      printf("\nDebito realizado com sucesso!\n");
    }

    else if (lc->c[indexCliente].tipoDeConta == 1){ // caso o tipo de conta for plus
      lc->c[indexCliente].valor = lc->c[indexCliente].valor - 1.03 * debito; // retira o valor e adiciona uma taxa
      sprintf(lc->c[indexCliente].e[lc->c[indexCliente].qtd].acao, "Acao: Debito | Valor: -%.2f | Taxa: 0.3%%", debito); // salva no extrato
      lc->c[indexCliente].qtd = lc->c[indexCliente].qtd + 1; // aumenta a quantidade de operacoes no extrato em 1
      if (lc->c[indexCliente].valor <= -5000){ // caso passe do limite minimo da conta
      printf("\nSaldo negativo atingido! Nao foi possivel concluir a acao.\n");
      lc->c[indexCliente].valor = lc->c[indexCliente].valor + 1.03 * debito; // retorna o valor para a conta
      return 0;
    }
      printf("\nDebito realizado com sucesso!\n");
    }
  }

  else { // caso a senha esteja incorreta
    printf("\nSenha incorreta.\n");
    return 0;
  }

  return 0;
}

int deposito(ListaDeClientes *lc){ // funcao de deposito
  printf("\nDeposito\n");
  long cpf; // define a variavel cpf para busca
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf);

  int indexCliente = buscaCliente(*lc, cpf); // chama a funcao de busca pelo cliente a partir do cpf

  if (indexCliente == -1){ // se o cpf nao for encontrado 
    printf("\nCliente nao encontrado\n");
    return 0;
  }

  else { // csao o cliente seja encontrado executa a acao de deposito
    float deposito; // define o valor a ser depositado
    printf("\nDigite o valor a ser depositado: ");
    scanf("%f", &deposito);
    lc->c[indexCliente].valor = lc->c[indexCliente].valor + deposito; // adiciona o valor a conta
    sprintf(lc->c[indexCliente].e[lc->c[indexCliente].qtd].acao, "Acao: Deposito | Valor: +%.2f | Taxa: 0.0%%", deposito); // salva no extrato
    lc->c[indexCliente].qtd = lc->c[indexCliente].qtd + 1; // aumenta a quantidade de operacoes em 1
    printf("\nDeposito realizado com sucesso!\n");
  }

  return 0;
}

int extrato(ListaDeClientes *lc, Extratos e){ // funcao de extrato
  printf("\nExtrato\n");
  
  long cpf; // define a variavel cpf para busca
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf);

  int indexCliente = buscaCliente(*lc, cpf); // chama a funcao de busca pelo cliente a partir do cpf

  if (indexCliente == -1){ // se o cpf nao for encontrado
    printf("Cliente nao encontrado");
    return 0;
  }

  char senha[20];
  printf("\nDigite sua senha: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { } // limpa buffer
  fgets(senha, 20, stdin); // recebe a senha digitada pelo usuario
  senha[strcspn(senha, "\n")] = '\0';


  int verificacaoSenha = strcmp(lc->c[indexCliente].senha, senha); // funcao para comparar strings e verificar a senha

  if (verificacaoSenha == 0){ // caso a string senha sejam igual a cadastrada pelo usuario
    FILE *f = fopen("extrato.txt", "w"); // cria um arquivo para armazenar os extratos e escrever as operacoes
    for (int i = 0; i <= lc->c[indexCliente].qtd; i++){ // percorre por todas as operacoes no extrato e imprime as informacoes
      fprintf(f, "\n%s", lc->c[indexCliente].e[i].acao);
    }
    fclose(f); // fecha o arquivo
  }
  else{ // caso a senha esteja incorreta
    printf("\nSenha incorreta!\n");
    return 0;
  }
  return 0;
}


int transferencia(ListaDeClientes *lc){ // funcao de transferencia
  printf("\nTransferencia\n");
  long cpf1; // cria a variavel de cpf do primeiro cliente (expedidor)
  printf("\nDigite seu CPF: ");
  scanf("%ld", &cpf1);

  int indexCliente1 = buscaCliente(*lc, cpf1); // chama a funcao de busca pelo cliente a partir do cpf

  if (indexCliente1 == -1){ // se o cpf nao for encontrado
    printf("\nCliente nao encontrado\n");
    return 0;
  }

  char senha[20];
  printf("\nDigite sua senha: ");
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { } // limpa buffer
  fgets(senha, 20, stdin); // recebe a senha digitada pelo usuario
  senha[strcspn(senha, "\n")] = '\0';

  int verificacaoSenha = strcmp(lc->c[indexCliente1].senha, senha); // funcao para comparar strings e verificar a senha

  if (verificacaoSenha == 0){ // caso a string senha sejam igual a cadastrada pelo usuario
    long cpf2; // cria a variavel de cpf do segundo cliente (emitente)
    printf("\nDigite o CPF do destinatario: ");
    scanf("%ld", &cpf2);

    int indexCliente2 = buscaCliente(*lc, cpf2); // chama a funcao de busca pelo cliente a partir do cpf

    if (indexCliente2 == -1){ // se o cpf nao for encontrado
      printf("\nCliente nao encontrado\n");
      return 0;
    }

    float valor; // define o valor da tranferencia
    printf("\nDigite o valor a ser transferido: ");
    scanf("%f", &valor);
    if (lc->c[indexCliente1].tipoDeConta == 0){ // caso a conta do primeiro cliente seja comum
      lc->c[indexCliente2].valor = lc->c[indexCliente2].valor + valor; // adiciona o valor na conta do segundo cliente
      sprintf(lc->c[indexCliente2].e[lc->c[indexCliente2].qtd].acao, "Acao: Transferencia | Valor: +%.2f | Taxa: 0.0%%", valor); // salva no extrato do segundo cliente
      lc->c[indexCliente2].qtd = lc->c[indexCliente2].qtd + 1; // aumenta a quantidade de operacoes do segundo cliente em 1 

      lc->c[indexCliente1].valor = lc->c[indexCliente1].valor - valor * 1.05; // reduz o valor da conta do primeiro cliente e adiciona uma taxa
      if (lc->c[indexCliente1].valor <= -1000){ // caso passe do limite minimo da conta
        printf("\nSaldo negativo atingido! Nao foi possivel concluir a acao.\n");
        lc->c[indexCliente1].valor = lc->c[indexCliente1].valor + 1.05 * valor; // retorna o valor para a conta
        return 0;
      }
      sprintf(lc->c[indexCliente1].e[lc->c[indexCliente1].qtd].acao, "Acao: Transferencia | Valor: -%.2f | Taxa: 0.5%%", valor); // salva no extrato do primerio cliente
      lc->c[indexCliente1].qtd = lc->c[indexCliente1].qtd + 1; // aumenta a quantidade de operacoes do primeiro cliente em 1 
    }
    else if (lc->c[indexCliente1].tipoDeConta == 1){ // caso a conta do primeiro cliente seja plus
      lc->c[indexCliente2].valor = lc->c[indexCliente2].valor + valor; // adiciona o valor na conta do segundo cliente
      sprintf(lc->c[indexCliente2].e[lc->c[indexCliente2].qtd].acao, "Acao: Transferencia | Valor: +%.2f | Taxa: 0.0%%", valor); // salva no extrato do segundo cliente
      lc->c[indexCliente2].qtd = lc->c[indexCliente2].qtd + 1; // aumenta a quantidade de operacoes do segundo cliente em 1 

      lc->c[indexCliente1].valor = lc->c[indexCliente1].valor - valor * 1.03; // reduz o valor da conta do primeiro cliente e adiciona uma taxa
      if (lc->c[indexCliente1].valor <= -5000){ // caso passe do limite minimo da conta
        printf("\nSaldo negativo atingido! Nao foi possivel concluir a acao.\n");
        lc->c[indexCliente1].valor = lc->c[indexCliente1].valor + 1.03 * valor; // retorna o valor para a conta
        return 0;
      }
      sprintf(lc->c[indexCliente1].e[lc->c[indexCliente1].qtd].acao, "Acao: Transferencia | Valor: -%.2f | Taxa: 0.3%%", valor); // salva no extrato do primerio cliente
      lc->c[indexCliente1].qtd = lc->c[indexCliente1].qtd + 1; // aumenta a quantidade de operacoes do primeiro cliente em 1 
    }

  }
  
  else { // caso a senha esteja incorreta
    printf("\nSenha incorreta.\n");
  return 0;
  }
  return 0;
}


int carregarLista(ListaDeClientes *lc, char arquivo[]){ // funcao de carregar a lista de clientes
  FILE *f = fopen(arquivo, "rb"); // abre o arquivo em binario para leitura
  if (f == NULL){  // caso esteja vazio retorne 1
  return 1;
  }
  fread(lc, sizeof(ListaDeClientes), 1, f);  // leitura do arquivo
  fclose(f);  // fecha o arquivo
  return 0;
}

int salvarLista(ListaDeClientes lc, char arquivo[]){ // funcao de salvar a lista de clientes
  FILE *f = fopen(arquivo, "wb");  // abre o arquivo em binario para escrita
  if (f == NULL){  // caso esteja vazio retorne 1
    return 1;
  }
  fwrite(&lc, sizeof(ListaDeClientes), 1, f); // escreve o arquivo atualizado
  fclose(f);  // fecha o arquivo
  return 0;
}