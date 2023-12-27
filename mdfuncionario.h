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
struct funcionario *prox;
};

int tela_menu_funcionario();
Funcionario* tela_cadastrar_funcionario(void);
void tela_exibir_funcionario(void);
void tela_pesquisar_funcionario(void);
void tela_alterar_funcionario(void);
void tela_excluir_funcionario(void);
int compara_cpf_funcionario_cadastro(const char *cpf);
int compara_cpf_funcionario_pesquisa(const char *cpf);
void exibir_funcionario(void);
void exibir_funcionario_inativo(void);
void mini_exibir_funcionario(FILE *arquivo);
void atualizar_funcionario_telefone(const char *cpf, const char *novo_dado);
void atualizar_funcionario_data(const char *cpf, const char *novo_dado); 
void atualizar_funcionario_email(const char *cpf, const char *novo_dado);
void atualizar_funcionario_nome(const char *cpf, const char *novo_dado);
void pesquisar_funcionario(const char *cpf);
void ler_funcionario(void);
void salvar_funcionario(Funcionario *aln);
void atualizar_situacao_funcionario(const char *cpf);









#endif