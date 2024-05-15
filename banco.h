#ifndef BANCO_H
#define BANCO_H

#define MAX_CLIENTES 1000

extern int numClientes;

void novoCliente();
void apagarCliente();
void listarClientes();
void debito();
void deposito();
void extrato();
void transferencia();

#endif /* BANCO_H */