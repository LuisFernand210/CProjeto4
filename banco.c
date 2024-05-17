#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

#define MAX_CLIENTES 1000
#define MAX_OPERACOES 100

typedef struct {
    char nome[50];
    char cpf[12];
    char tipo_conta[6]; // "comum" ou "plus"
    float saldo;
    float limite_negativo;
    char senha[20];
    float operacoes[MAX_OPERACOES];
    int num_operacoes;
} Cliente;

Cliente clientes[MAX_CLIENTES];

int numClientes = 0;

void novoCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite máximo de clientes atingido.\n");
        return;
    }

    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[numClientes].nome);
    printf("Digite o CPF do cliente: ");
    scanf("%s", clientes[numClientes].cpf);
    printf("Digite o tipo de conta (comum ou plus): ");
    scanf("%s", clientes[numClientes].tipo_conta);
    printf("Digite o valor inicial da conta: ");
    scanf("%f", &clientes[numClientes].saldo);
    printf("Digite a senha do cliente: ");
    scanf("%s", clientes[numClientes].senha);

    if (strcmp(clientes[numClientes].tipo_conta, "comum") == 0) {
        clientes[numClientes].limite_negativo = -1000.0;
    } else if (strcmp(clientes[numClientes].tipo_conta, "plus") == 0) {
        clientes[numClientes].limite_negativo = -5000.0;
    } else {
        printf("Tipo de conta inválido.\n");
        return;
    }

    clientes[numClientes].num_operacoes = 0;

    numClientes++;

    printf("Cliente cadastrado com sucesso.\n");
}

void apagarCliente() {
    char cpf[12];
    printf("Digite o CPF do cliente que deseja apagar: ");
    scanf("%s", cpf);

    int encontrado = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Cliente não encontrado.\n");
        return;
    }

    for (int i = encontrado; i < numClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }

    numClientes--;

    printf("Cliente apagado com sucesso.\n");
}

void listarClientes() {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de Conta: %s\n", clientes[i].tipo_conta);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("Limite Negativo: %.2f\n", clientes[i].limite_negativo);
        printf("------------------------\n");
    }
}

void debito() {
    char cpf[12], senha[20];
    float valor, taxa;

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);
    printf("Digite o valor a ser debitado: ");
    scanf("%f", &valor);

    int encontrado = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1 || strcmp(clientes[encontrado].senha, senha) != 0) {
        printf("CPF ou senha incorretos.\n");
        return;
    }

    if (strcmp(clientes[encontrado].tipo_conta, "comum") == 0) {
        taxa = 0.05;
    } else if (strcmp(clientes[encontrado].tipo_conta, "plus") == 0) {
        taxa = 0.03;
    } else {
        printf("Tipo de conta invalido.\n");
        return;
    }

    float totalDebito = valor + (valor * taxa);
    if (clientes[encontrado].saldo - totalDebito < clientes[encontrado].limite_negativo) {
        printf("Saldo insuficiente.\n");
        return;
    }

    clientes[encontrado].saldo -= totalDebito;
    clientes[encontrado].operacoes[clientes[encontrado].num_operacoes++] = -totalDebito;

    printf("Debito realizado com sucesso. Saldo atual: %.2f\n", clientes[encontrado].saldo);
}

void deposito() {
    char cpf[12];
    float valor;

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("Digite o valor a ser depositado: ");
    scanf("%f", &valor);

    int encontrado = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    clientes[encontrado].saldo += valor;
    clientes[encontrado].operacoes[clientes[encontrado].num_operacoes++] = valor;

    printf("Deposito realizado com sucesso. Saldo atual: %.2f\n", clientes[encontrado].saldo);
}

void extrato() {
    char cpf[12], senha[20];

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    printf("Digite a senha do cliente: ");
    scanf("%s", senha);

    int encontrado = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1 || strcmp(clientes[encontrado].senha, senha) != 0) {
        printf("CPF ou senha incorretos.\n");
        return;
    }

    char filename[50];
    sprintf(filename, "extrato_%s.txt", cpf);
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Erro ao criar o arquivo de extrato.\n");
        return;
    }

    fprintf(file, "Extrato da conta - %s\n", clientes[encontrado].nome);
    fprintf(file, "CPF: %s\n", clientes[encontrado].cpf);
    fprintf(file, "Tipo de Conta: %s\n", clientes[encontrado].tipo_conta);
    fprintf(file, "Saldo Atual: %.2f\n", clientes[encontrado].saldo);
    fprintf(file, "Limite Negativo: %.2f\n", clientes[encontrado].limite_negativo);
    fprintf(file, "------------------------\n");
    fprintf(file, "Histórico de Operações:\n");

    for (int i = 0; i < clientes[encontrado].num_operacoes; i++) {
        fprintf(file, "%.2f\n", clientes[encontrado].operacoes[i]);
    }

    fclose(file);

    printf("Extrato gerado com sucesso. Arquivo: %s\n", filename);
}

void transferencia() {
    char cpf_origem[12], senha_origem[20], cpf_destino[12];
    float valor, taxa;

    printf("Digite o CPF da conta de origem: ");
    scanf("%s", cpf_origem);
    printf("Digite a senha da conta de origem: ");
    scanf("%s", senha_origem);
    printf("Digite o CPF da conta de destino: ");
    scanf("%s", cpf_destino);
    printf("Digite o valor a ser transferido: ");
    scanf("%f", &valor);

    int origem = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf_origem) == 0) {
            origem = i;
            break;
        }
    }

    if (origem == -1 || strcmp(clientes[origem].senha, senha_origem) != 0) {
        printf("CPF ou senha da conta de origem incorretos.\n");
        return;
    }

    int destino = -1;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf_destino) == 0) {
            destino = i;
            break;
        }
    }

    if (destino == -1) {
        printf("CPF da conta de destino nao encontrado.\n");
        return;
    }

    if (strcmp(clientes[origem].tipo_conta, "comum") == 0) {
        taxa = 0.05;
    } else if (strcmp(clientes[origem].tipo_conta, "plus") == 0) {
        taxa = 0.03;
    } else {
        printf("Tipo de conta de origem invalido.\n");
        return;
    }

    float totalDebito = valor + (valor * taxa);
    if (clientes[origem].saldo - totalDebito < clientes[origem].limite_negativo) {
        printf("Saldo insuficiente na conta de origem.\n");
        return;
    }

    clientes[origem].saldo -= totalDebito;
    clientes[origem].operacoes[clientes[origem].num_operacoes++] = -totalDebito;

    clientes[destino].saldo += valor;
    clientes[destino].operacoes[clientes[destino].num_operacoes++] = valor;

    printf("Transferencia realizada com sucesso.\n");
    printf("Saldo atual da conta de origem: %.2f\n", clientes[origem].saldo);
    printf("Saldo atual da conta de destino: %.2f\n", clientes[destino].saldo);
}
