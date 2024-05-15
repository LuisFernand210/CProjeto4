#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

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
    // Implementação da função apagarCliente
}

void listarClientes() {
    // Implementação da função listarClientes
}

void debito() {
    // Implementação da função debito
}

void deposito() {
    // Implementação da função deposito
}

void extrato() {
    // Implementação da função extrato
}

void transferencia() {
    // Implementação da função transferencia
}
