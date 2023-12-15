
#include <stdio.h>
#include <stdlib.h>
#include "mdcliente.h"
#include "mdfuncionario.h"
#include "mdproduto.h"
typedef struct cliente Cliente;


//Assinaturas
int tela_menu_principal();
Cliente* tela_cadastrar_cliente();
void tela_pesquisar_cliente();
void tela_alterar_cliente(); 
void tela_excluir_cliente();
int tela_menu_funcionario();
void tela_cadastrar_funcionario();
void tela_pesquisar_funcionario();
void tela_alterar_funcioinario();
void tela_excluir_funcionario(); 
int tela_menu_produto();
void tela_cadastrar_produto();

/////
// Programa principal
int main() {
    int opcao=-1;
    
    do {
        opcao=tela_menu_principal();
    } while (opcao != 0);

    return 0;
}
int tela_menu_principal(void) {
    system("clear||cls");
    int opcao;
    int opcaoCl=-1;
    int opcaoC2=-1;
    int opcaoC3=-1;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragancia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = =    Gestao de Perfumaria   = = = = =                ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. modulo Cliente                                            ///\n");
    printf("///            2. modulo Produto                                            ///\n");
    printf("///            3. modulo funcionarios                                       ///\n");
    printf("///            4. modulo vendas                                             ///\n");
    printf("///            5. Sobre                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcaoo desejada: ");
    scanf("%d", &opcao);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    switch (opcao) {
            case 1:
            do
            {
            opcaoCl=tela_menu_cliente(); 
            } while (opcaoCl!=0);
                break;
            case 2:
                 do
            {
            opcaoC2=tela_menu_produto(); 
            } while (opcaoC2!=0);
                break;
            case 3:
                do
            {
            opcaoC3=tela_menu_funcionario(); 
            } while (opcaoC3!=0);
                break;
            case 4:
                printf("4 deu certo\n");
                break;
            case 5:
                printf("5 deu certo\n");
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

return opcao;        
}
