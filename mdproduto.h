#ifndef mdproduto_h
#define mdproduto_h

typedef struct produto Produto;

struct produto
{
char id[4];
char nome[61];    
char preco[7];
char quantidade[4];
char capacidade[4];
};




int tela_menu_produto();
Produto* tela_cadastrar_produto(void);
void tela_exibir_produto(void);
void tela_pesquisar_produto(void);
void tela_alterar_produto(void);
void tela_excluir_produto(void);
int valida_id (const char *id);
void exibir_produto(void);
void excluir_produto(const char *id);
void atualizar_produto_capacidade(const char *id, const char *novo_dado);
void atualizar_produto_quantidade(const char *id, const char *novo_dado);
void atualizar_produto_preco(const char *id, const char *novo_dado);
void atualizar_produto_nome(const char *id, const char *novo_dado);
void pesquisar_produto(const char *id);
void ler_produto(void);
void salvar_produto(Produto *aln);


            
#endif