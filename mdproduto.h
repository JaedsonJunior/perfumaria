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
void tela_cadastrar_produto(void);
void tela_pesquisar_produto(void);
void tela_alterar_produto(void);
void tela_excluir_produto(void);
int valida_id (const char *id);
                    
#endif