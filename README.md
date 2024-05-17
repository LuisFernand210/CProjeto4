# CProjeto4
# Banco QuemPoupaTem

Este é o sistema bancário do Banco QuemPoupaTem, desenvolvido em C. O sistema permite a criação, manutenção e gerenciamento de contas bancárias, incluindo operações de débito, depósito, transferência e geração de extratos.

## Funcionalidades

O sistema possui as seguintes funcionalidades:

1. **Novo cliente**: Cadastro de novos clientes com nome, CPF, tipo de conta, valor inicial e senha.
2. **Apaga cliente**: Remove um cliente cadastrado pelo CPF.
3. **Listar clientes**: Exibe uma lista de todos os clientes cadastrados.
4. **Débito**: Debita um valor da conta de um cliente.
5. **Depósito**: Deposita um valor na conta de um cliente.
6. **Extrato**: Gera um arquivo de extrato com o histórico de operações de um cliente.
7. **Transferência Entre Contas**: Realiza a transferência de um valor de uma conta para outra.

## Tipos de Conta

O banco trabalha com dois tipos de conta:
- **Comum**:
  - Cobra taxa de 5% a cada débito realizado.
  - Permite um saldo negativo de até R$ 1.000,00.
- **Plus**:
  - Cobra taxa de 3% a cada débito realizado.
  - Permite um saldo negativo de até R$ 5.000,00.

## Persistência de Dados

Os dados dos clientes e suas transações são armazenados em um arquivo binário (`clientes.dat`) para garantir que não sejam perdidos quando o programa for encerrado.

## Compilação e Execução

Para compilar e executar o projeto, siga as etapas abaixo:

### Compilação

1. Abra um terminal e navegue até o diretório onde os arquivos do projeto estão localizados.
2. Execute o seguinte comando para compilar o projeto:

    ```sh
    gcc main.c banco.c -o banco
    ```

### Execução

1. Após a compilação bem-sucedida, execute o programa com o comando:

    ```sh
    ./banco
    ```

2. Siga as instruções no menu para utilizar as funcionalidades do sistema bancário.
