#ifndef mdcliente_h
#define mdcliente_h
typedef struct cliente Cliente;

struct cliente
{
char cpf[12];
char nome[61];
char email[61];
char data[12];
char fone[15];
char situacao; 
struct cliente *prox;
};

void exibir_cliente_inativo(void);
Cliente* tela_cadastrar_cliente(void);
void tela_pesquisar_cliente();
void tela_alterar_cliente(); 
void tela_excluir_cliente(); 
int tela_menu_cliente();
int compara_cpf_cliente_cadastro(const char *cpf);
int compara_cpf_cliente_pesquisa(const char *cpf);
void exibir_cliente(void);
void mini_exibir_cliente(FILE *arquivo);
void exibir_cliente(void);
void atualizar_situacao_cliente(const char *cpf);
void excluir_cliente(const char *cpf); 
void atualizar_cliente_telefone(const char *cpf, const char *novo_dado);
void atualizar_cliente_data(const char *cpf, const char *novo_dado);
void atualizar_cliente_email(const char *cpf, const char *novo_dado);
void atualizar_cliente_nome(const char *cpf, const char *novo_dado);
void pesquisar_cliente(const char *cpf);
void ler_cliente(void); 
void salvar_cliente(Cliente *aln);
void tela_exibir_cliente(void);











#endif