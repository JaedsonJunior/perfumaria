#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ultilidade.h"

typedef struct produto Produto;

struct produto
{
char id[4];
char nome[61];    
char preco[7];
char quantidade[4];
char capacidade[4];
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
            printf("ID: %s\n",produto.id);
            printf("NOME: %s\n", produto.nome);
            printf("PRECO: %s\n", produto.preco);
            printf("QUANTIDADE: %s\n", produto.quantidade);
            printf("CAPACIDADE: %s\n", produto.capacidade);
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

void pesquisar_produto(const char *id) {
    FILE *arquivo = fopen("produto.bin", "rb");

    if (arquivo != NULL) {
        Produto produto;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            // Compara o id do produto atual com o produto desejado
            if (strcmp(produto.id, id) == 0) {
                printf("Produto encontrado:\n");
                printf("ID: %s\n",produto.id);
                printf("NOME: %s\n", produto.nome);
                printf("PRECO: %s\n", produto.preco);
                printf("QUANTIDADE: %s\n", produto.quantidade);
                printf("CAPACIDADE: %s\n", produto.capacidade);
                
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        

            else if(!encontrado) {
                printf("Produto com nome %s não encontrado.\n", id);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}

void atualizar_produto_nome(const char *id, const char *novo_dado) {
    FILE *arquivo = fopen("produto.bin", "r+b");

    if (arquivo != NULL) {
        Produto produto;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            if (strcmp(produto.id, id) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(produto.nome, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Produto), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&produto, sizeof(Produto), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }}

void atualizar_produto_preco(const char *id, const char *novo_dado) {
    FILE *arquivo = fopen("produto.bin", "r+b");

    if (arquivo != NULL) {
        Produto produto;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            if (strcmp(produto.id, id) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(produto.preco, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Produto), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&produto, sizeof(Produto), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }}

    void atualizar_produto_quantidade(const char *id, const char *novo_dado) {
    FILE *arquivo = fopen("produto.bin", "r+b");

    if (arquivo != NULL) {
        Produto produto;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            if (strcmp(produto.id, id) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(produto.quantidade, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Produto), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&produto, sizeof(Produto), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }}
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
    scanf("%s", aln->preco);
    limparBuffer();
    printf("///            Quantidade:                                                  ///\n");
    scanf("%s", aln->quantidade);
    limparBuffer();
    printf("///            Capacidade(ml):                                              ///\n");
    scanf("%s", aln->capacidade);
    limparBuffer();
    printf("///            ID(1 a 999):                                                          ///\n");
    scanf("%4s", aln->id);
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
    char id[4];
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
    printf("///            ID(1 a 999):                                                 ///\n");
    scanf("%3s",id);
	limparBuffer();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");   
    pesquisar_produto(id);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
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

void tela_alterar_produto(void) {
    char id[4];
    char nome[61];
    char preco[7];
    char quantidade[4];
    int alt;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                 = = = =   Fragância Popular     = = = =                 ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Cliente = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
	printf("///            Informe o ID (1 a 999):                                      ///\n");
	scanf("%3s",id);
	limparBuffer();
	
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     OPCOES DE ALTERACAO                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                     1- Alterar o nome                                   ///\n");
    printf("///                     2- Alterar o preco                                  ///\n");
    printf("///                     3- Alterar a quantidade                             ///\n");
    printf("///                     4- Alterar a capacidade                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%d",&alt);
    switch (alt)
    {
    case 1:
    
		printf(".> Digite o novo Nome:                                                    \n");
        limparBuffer();
		scanf("%61[^\n]",nome);
        atualizar_produto_nome(id,nome);
        limparBuffer();
        break;
    
    case 2:
        printf(".> Digite o novo preco:                                                    \n");
        limparBuffer();
		scanf(("%6s"),preco);
        atualizar_produto_preco(id,preco);
        limparBuffer();
        break;

    case 3:
        printf(".> Digite o novo preco:                                                    \n");
        limparBuffer();
		scanf(("%3s"),quantidade);
        atualizar_produto_quantidade(id,quantidade);
        limparBuffer();
        break;  

    default:
        break;
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
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
                tela_alterar_produto();
                limparBuffer();
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