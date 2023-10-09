#ifndef validacao_h
#define validacao_h

int validarCPF(char *cpf);
bool validaNome(const char nome[]);
bool validaFone(const char fone[]);
int validaEmail(const char *email);
int validate_date(int day, int month, int year);

#endif