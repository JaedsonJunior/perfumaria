
#include <stdio.h>
#include <stdlib.h>

// Assinaturas
void tela_menu_principal();



/////
// Programa principal
int main() {
    int opcao;

    do {
        tela_menu_principal();
    } while (opcao != 0);

    return 0;}
void tela_menu_principal() {
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Gestão de perfumaria                 ///\n");
    printf("///             Developed by @JaedsonJunior -- since Ago, 2023               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Gestão de Perfumaria = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Módulo Cliente                                             ///\n");
    printf("///            2. Módulo Produto                                             ///\n");
    printf("///            3. Módulo funcionarios                                        ///\n");
    printf("///            4. Módulo vendas                                              ///\n");
    printf("///            5. Sobre                                                     ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    int opcao;
    scanf("%d", &opcao);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); // Limpa o caractere de nova linha do buffer
    switch (opcao) {
        case 1:
            printf("1 deu certo");
            break;
        case 2:
            printf("2 deu certo");
            break;
        case 3:
            printf("3 deu certo");
            break;
        case 4:
            printf("4 deu certo");
            break;
        case 5:
            printf("5 deu certo");
            break;    
        case 0:
            printf("0 deu certo");
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}
