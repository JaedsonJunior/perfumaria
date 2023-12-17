#ifndef mdfunionarios_h
#define mdfuncionarios_h

typedef struct funcionario Funcionario;

struct funcionario
{
char cpf[12];
char nome[61];
char email[61];
char data[12];
char fone[15];
char situacao;
};

int tela_menu_funcionario();
void tela_cadastrar_funcionario(void);
void tela_pesquisar_funcionario(void);
void tela_alterar_funcioinario(void);
void tela_excluir_funcionario(void);
int compara_cpf_funcionario_cadastro(const char *cpf);
int compara_cpf_funcionario_pesquisa(const char *cpf);
void exibir_funcionario(void);
void exibir_funcionario_inativo(void);

#endif