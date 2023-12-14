#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultilidade.h"

typedef struct produto Produto;

struct produto
{
char nome[61];    
float preco[7];
int quantidade[4];
int capacidade[4];
};
void salvar_produto(Produto *aln) {
    FILE *arquivo = fopen("produto.bin", "ab");

    if (arquivo != NULL) {
        fwrite(aln, sizeof(Produto), 1, arquivo);
        fclose(arquivo);
        printf("Gravado com Sucesso!!\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

void ler_produto(void) {
    FILE *arquivo = fopen("produto.bin", "rb");

    if (arquivo != NULL) {
        Produto produto;

        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            printf("NOME: %s\n", produto.nome);
            printf("PRECO: %f\n", produto.preco[0]);
            printf("QUANTIDADE: %d\n", produto.quantidade[0]);
            printf("CAPACIDADE: %d\n", produto.capacidade[0]);
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

void pesquisar_produto(const char *nome) {
    FILE *arquivo = fopen("produto.bin", "rb");

    if (arquivo != NULL) {
        Produto produto;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            // Compara o CPF do cliente atual com o CPF desejado
            if (strcmp(produto.nome, nome) == 0) {
                printf("Produto encontrado:\n");
                printf("NOME: %s\n", produto.nome);
                printf("PRECO: %f\n", produto.preco[0]);
                printf("QUANTIDADE: %d\n", produto.quantidade[0]);
                printf("CAPACIDADE: %d\n", produto.capacidade[0]);
                
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        

            else if(!encontrado) {
                printf("Produto com nome %s não encontrado.\n", nome);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

Produto* tela_cadastrar_produto(void) {
    Produto *aln;
    aln = (Produto*) malloc(sizeof(Produto));
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragância Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar produto = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            nome:                                                        ///\n");
    scanf("%61[^\n]", aln->nome);
    limparBuffer();
    printf("///            preço:                                                       ///\n");
    scanf("%f", aln->preco);
    limparBuffer();
    printf("///            Quantidade:                                                  ///\n");
    scanf("%d", aln->quantidade);
    limparBuffer();
    printf("///            Capacidade(ml):                                              ///\n");
    scanf("%d", aln->capacidade);
    limparBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    salvar_produto(aln);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
    return aln;
    
}
void tela_pesquisar_produto(void) {
    char nome[61];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragância Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Produto = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Nome:                                                        ///\n");
    scanf("%[^\n]",nome);
	limparBuffer();
   system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");   
    pesquisar_produto(nome);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}

void tela_alterar_produto(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragância Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alteração de Produto = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            O que deseja altera:nome,preço,quantidade ou capacidade?      ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void tela_excluir_produto(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragância Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = excluir produto = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");   
    printf("///            Nome:                                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

int tela_menu_produto() {
    int opcaoC2;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragância Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu produto = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo produto                                 ///\n");
    printf("///            2. Pesquisar os dados de um produto                          ///\n");
    printf("///            3. Atualizar dados de um produto                             ///\n");
    printf("///            4. Excluir um produto do sistema                             ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &opcaoC2);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    switch (opcaoC2) {
            case 1:
                tela_cadastrar_produto();
                limparBuffer();
                break;
            case 2:
                tela_pesquisar_produto();
                limparBuffer();
                break;
            case 3:
                printf("saindo...\n");
                break;
            case 4:
                printf("saindo...\n");
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
return opcaoC2;
}