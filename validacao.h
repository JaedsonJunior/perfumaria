#ifndef validacao_h
#define validacao_h
#include <stdbool.h>
int validarCPF(const char *cpf);
bool validaNome(const char nome[]);
bool validaFone(const char fone[]);
int validaEmail(const char *email);
bool valida_data(const char *data);
bool extrair_data(const char *data, int *dia, int *mes, int *ano);
bool isDigit(char c);
int valida_cpf_cliente_cadastro(const char *cpf);
int valida_cpf_funcionario_cadastro(const char *cpf);
int valida_cpf_cliente_pesquisa(const char *cpf);
int valida_cpf_funcionario_pesquisa(const char *cpf);

#endif