#ifndef validacao_h
#define validacao_h
#include <stdbool.h>
bool validarCPF(const char *cpf);
bool validaNome(const char nome[]);
bool validaFone(const char fone[]);
int validaEmail(const char *email);
bool valida_data(const char *data);
bool extrair_data(const char *data, int *dia, int *mes, int *ano);
bool isDigit(char c);
bool valida_cpf(const char *cpf);

#endif