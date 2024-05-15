#include <stdio.h>
#include "banco.h"

int main() {
    int opcao;

    while (1) {
        printf("\n\n--- Banco QuemPoupaTem ---\n");
        printf("1. Novo cliente\n");
        printf("2. Apagar cliente\n");
        printf("3. Listar clientes\n");
        printf("4. Debito\n");
        printf("5. Deposito\n");
        printf("6. Extrato\n");
        printf("7. Transferencia entre contas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                novoCliente();
                break;
            case 2:
                // Chamar a função para apagar um cliente
                // apagarCliente();
                break;
            case 3:
                // Chamar a função para listar todos os clientes
                // listarClientes();
                break;
            case 4:
                // Chamar a função para debitar um valor da conta do cliente
                // debito();
                break;
            case 5:
                // Chamar a função para depositar um valor na conta do cliente
                // deposito();
                break;
            case 6:
                // Chamar a função para gerar o extrato da conta do cliente
                // extrato();
                break;
            case 7:
                // Chamar a função para realizar a transferência entre contas
                // transferencia();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}