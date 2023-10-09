
#include <stdio.h>
#include <stdlib.h>
#include "mdcliente.h"
//Assinaturas
int tela_menu_principal();
void tela_cadastrar_cliente();
void tela_pesquisar_cliente();
void tela_alterar_cliente(); 
void tela_excluir_cliente(); 

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
    int opcao;
    int opcaoCl=-1;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Gestão de perfumaria                ///\n");
    printf("///             Developed by @JaedsonJunior -- since Ago, 2023              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Gestão de Perfumaria = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Cliente                                            ///\n");
    printf("///            2. Módulo Produto                                            ///\n");
    printf("///            3. Módulo funcionarios                                       ///\n");
    printf("///            4. Módulo vendas                                             ///\n");
    printf("///            5. Sobre                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
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
                printf("2 deu certo\n");
                break;
            case 3:
                printf("3 deu certo\n");
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
                printf("Opção inválida\n");
                break;
        }

return opcao;        
}
