#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
        int encontrado = 0; // Flag para indicar se o produto foi encontrado

        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            // Compara o id do produto atual com o produto desejado
            if (strcmp(produto.id, id) == 0) {
                printf("Produto encontrado:\n");
                printf("ID:%s\n",produto.id);
                printf("Nome: %s\n", produto.nome);
                printf("Preco: R$ %s\n", produto.preco);
                printf("Quantidade: %s Unidades\n", produto.quantidade);
                printf("Capacidade: %s ML\n", produto.capacidade);
                printf("Proximo produto->\n");
                limparBuffer();
                
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        }

        if (!encontrado) {
            printf("Produto com ID %s nao encontrado.\n", id);
        }

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
        printf("Erro ao abrir o arquivo para leitura e gravacao.\n");
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
        printf("Erro ao abrir o arquivo para leitura e gravacao.\n");
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
        printf("Erro ao abrir o arquivo para leitura e gravacao.\n");
    }}
    
    void atualizar_produto_capacidade(const char *id, const char *novo_dado) {
    FILE *arquivo = fopen("produto.bin", "r+b");

    if (arquivo != NULL) {
        Produto produto;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            if (strcmp(produto.id, id) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(produto.capacidade, novo_dado);

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
        printf("Erro ao abrir o arquivo para leitura e gravacao.\n");
    }}

    void excluir_produto(const char *id) {
    FILE *arquivo;
    FILE *temp_pro;
    Produto produto;

    // Abra o arquivo binário para leitura
    arquivo = fopen("produto.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Abra um arquivo temporário para escrita
    temp_pro = fopen("temp_pro.bin", "wb");
    if (temp_pro == NULL) {
        perror("Erro ao criar o arquivo temporario");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Leia os registros do arquivo e grave no arquivo temporário, exceto o que será excluído
    while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
        if (strcmp(produto.id, id) != 0) {
            fwrite(&produto, sizeof(Produto), 1, temp_pro);
        }
    }

    // Feche os arquivos
    fclose(arquivo);
    fclose(temp_pro);

    // Remova o arquivo original e renomeie o temporário
    if (remove("produto.bin") != 0) {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("temp_pro.bin", "produto.bin") != 0) {
        perror("Erro ao renomear o arquivo temporario");
        exit(EXIT_FAILURE);
    }

    printf("Cliente com CPF %s excluido com sucesso.\n", id);
}
void exibir_produto(void) {
    FILE *arquivo = fopen("produto.bin", "rb");
    int i;
    i = 1;
    if (arquivo != NULL) {
        Produto produto;
        
        while (fread(&produto, sizeof(Produto), 1, arquivo) == 1) {
            
                // Mostrar informações da venda
                printf("Produto encontrado: %d\n",i);
                printf("ID:%s\n",produto.id);
                printf("Nome: %s\n", produto.nome);
                printf("Preco: R$ %s\n", produto.preco);
                printf("Quantidade: %s Unidades\n", produto.quantidade);
                printf("Capacidade: %s ML\n", produto.capacidade);
                printf("Proximo produto->\n");
                limparBuffer();
                i+=1;
                
                
            
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de vendas para leitura.\n");
    }
}
void tela_exibir_produto(void) {
    limpaTela();






    printf("\n");
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
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///              = = = = =  Exibir Lista de Produto = = = =                 ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    exibir_produto();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
Produto* tela_cadastrar_produto(void) {
    Produto *aln;
    aln = (Produto*) malloc(sizeof(Produto));
    limpaTela();






    printf("\n");
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
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar produto = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            nome: ");
    scanf("%61[^\n]", aln->nome);
    limparBuffer();
    printf("///            preco: ");
    scanf("%s", aln->preco);
    limparBuffer();
    printf("///            Quantidade: ");
    scanf("%s", aln->quantidade);
    limparBuffer();
    printf("///            Capacidade(ml): ");
    scanf("%s", aln->capacidade);
    limparBuffer();
    printf("///            ID(1 a 999): ");
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
    limpaTela();






    printf("\n");
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
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Produto = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID(1 a 999): ");
    scanf("%3s",id);
	limparBuffer();
    limpaTela();






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
    char id[4];
    
    limpaTela();






    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   FragAncia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = excluir produto = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");   
    printf("///            ID(1-999): ");
    scanf("%3s",id);
    limparBuffer();
    excluir_produto(id);
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
    char capacidade[4];
    int alt;
    limpaTela();






    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                 = = = =   Fragancia Popular     = = = =                 ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Cliente = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
	printf("///            Informe o ID (1 a 999): ");
	scanf("%3s",id);
	limparBuffer();
	
    limpaTela();






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
    
		printf(".> Digite o novo Nome: ");
        limparBuffer();
		scanf("%61[^\n]",nome);
        atualizar_produto_nome(id,nome);
        limparBuffer();
        break;
    
    case 2:
        printf(".> Digite o novo preco: ");
        limparBuffer();
		scanf(("%6s"),preco);
        atualizar_produto_preco(id,preco);
        limparBuffer();
        break;

    case 3:
        printf(".> Digite a nova quantidade: ");
        limparBuffer();
		scanf(("%3s"),quantidade);
        atualizar_produto_quantidade(id,quantidade);
        limparBuffer();
        break;  

    case 4:
        printf(".> Digite a nova capacidade: ");
        limparBuffer();
		scanf(("%3s"),capacidade);
        atualizar_produto_capacidade(id,capacidade);
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
    limpaTela();






    printf("\n");
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
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu produto = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo produto                                 ///\n");
    printf("///            2. Pesquisar os dados de um produto                          ///\n");
    printf("///            3. Atualizar dados de um produto                             ///\n");
    printf("///            4. Excluir um produto do sistema                             ///\n");
    printf("///            5. Exibir Lista de Produto                                   ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
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
                
                break;
            case 2:
                tela_pesquisar_produto();
                
                break;
            case 3:
                tela_alterar_produto();
                
                break;
            case 4:
                tela_excluir_produto();
                
                break;
            case 5:
                exibir_produto();
                
                break;    
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
return opcaoC2;
}