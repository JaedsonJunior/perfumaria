#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mdcliente.h"
#include "mdfuncionario.h"
#include "mdproduto.h"
#include "mdvenda.h"
#include "ultilidade.h"
#include "validacao.h"
int tela_listar_venda();



int tela_menu_venda(void) {
    int opcao_lista= -1;
    nova_venda *aln;
    aln = (nova_venda *)malloc(sizeof(nova_venda));
    (void)system("clear");



    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragancia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu venda = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar uma venda                                       ///\n");
    printf("///            2. exibir lista de vendas                                    ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    int opcao_venda;
    scanf("%d", &opcao_venda);
    limparBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    switch (opcao_venda)
    {
    case 1:
        cadastrar_e_salvar_venda(aln);
        break;
    case 2:
        do  {
        opcao_lista=tela_listar_venda();; 
            } while (opcao_lista!=0);
        break;
        
        
        break;
    default:
        printf("Opcao invalida\n");
        break;    
   
    }
return opcao_venda;
}

void lista_geral() {
    FILE *arquivo = fopen("vendas.bin", "rb");

    if (arquivo != NULL) {
        struct venda venda_atual;

        while (fread(&venda_atual, sizeof(struct venda), 1, arquivo) == 1) {
            
                // Mostrar informações da venda
                printf("CPF Cliente: %s\n", venda_atual.cpf_cliente);
                printf("CPF Funcionário: %s\n", venda_atual.cpf_funcionario);
                printf("Nome do Produto: %s\n", venda_atual.nome_produto);
                printf("Data: %s\n", venda_atual.data);
                printf("-----------------\n");
                limparBuffer();
            
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de vendas para leitura.\n");
    }
}

void mostrar_vendas_por_cliente(const char *cpf_cliente) {
    FILE *arquivo = fopen("vendas.bin", "rb");

    if (arquivo != NULL) {
        struct venda venda_atual;

        while (fread(&venda_atual, sizeof(struct venda), 1, arquivo) == 1) {
            if (strcmp(venda_atual.cpf_cliente, cpf_cliente) == 0) {
                // Mostrar informações da venda
                printf("CPF Cliente: %s\n", venda_atual.cpf_cliente);
                printf("CPF Funcionário: %s\n", venda_atual.cpf_funcionario);
                printf("Nome do Produto: %s\n", venda_atual.nome_produto);
                printf("Data: %s\n", venda_atual.data);
                printf("-----------------\n");
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de vendas para leitura.\n");
    }
}
void mostrar_vendas_por_funcionario(const char *cpf_funcionario) {
    FILE *arquivo = fopen("vendas.bin", "rb");

    if (arquivo != NULL) {
        struct venda venda_atual;

        while (fread(&venda_atual, sizeof(struct venda), 1, arquivo) == 1) {
            if (strcmp(venda_atual.cpf_funcionario, cpf_funcionario) == 0) {
                // Mostrar informações da venda
                printf("CPF Cliente: %s\n", venda_atual.cpf_cliente);
                printf("CPF Funcionario: %s\n", venda_atual.cpf_funcionario);
                printf("Nome do Produto: %s\n", venda_atual.nome_produto);
                printf("Data: %s\n", venda_atual.data);
                printf("-----------------\n");
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de vendas para leitura.\n");
    }
}

void cadastrar_e_salvar_venda(nova_venda *aln) {
    // Preencha os campos da nova venda
    do {
		printf("///            Informe o CPF Cliente(apenas numeros): ");
		scanf("%12s]", aln->cpf_cliente);
        limparBuffer();
	} while (!valida_cpf_cliente_pesquisa(aln->cpf_cliente));

    do {
		printf("///            Informe o CPF Funcionario (numeros): ");
		scanf("%[^\n]", aln->cpf_funcionario);
		limparBuffer();
	} while (!valida_cpf_funcionario_pesquisa(aln->cpf_funcionario));
       

    printf("Informe o nome do produto: ");
    scanf("%61[^\n]", aln->nome_produto);
    limparBuffer();

    printf("Informe a data da venda (dd/mm/aaaa): ");
    scanf("%19s", aln->data);
    limparBuffer();

    salvar_venda(aln);
    limparBuffer();
}

 void venda_cliente(void) {
    char cpf [12];
    (void)system("clear");



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
    printf("///            = = = = = = = = =  venda cliente = = = = = = = = =           ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
     do {
		printf("///            Informe o CPF (apenas numeros): ");
		scanf("%12s]",cpf);
        limparBuffer();
	} while (!valida_cpf_cliente_pesquisa(cpf));
    pesquisar_cliente_venda(cpf);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void venda_funcionario(void) {
    char cpf [12];
    (void)system("clear");



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
    printf("///            = = = = = = = = =  venda funcionario = = = = = = = = =       ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
     do {
		printf("///            Informe o CPF (apenas numeros): ");
		scanf("%12s]",cpf);
        limparBuffer();
	} while (!valida_cpf_funcionario_pesquisa(cpf));
    pesquisar_funcionario_venda(cpf);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void venda_produto(void) {
    (void)system("clear");



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
    printf("///            = = = = = = = = =  venda produto = = = = = = = = =           ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///             EM ANDAMENTO                                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void pesquisar_cliente_venda(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo != NULL) {
        Cliente cliente;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            // Compara o CPF do cliente atual com o CPF desejado
            if (strcmp(cliente.cpf, cpf) == 0) {
                printf("Cliente encontrado:\n");
                mostrar_vendas_por_cliente(cpf);
              
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        

            else if(!encontrado) {
                printf("Cliente com CPF %s nao encontrado.\n", cpf);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}
void pesquisar_funcionario_venda(const char *cpf) {
    FILE *arquivo = fopen("funcionario.bin", "rb");

    if (arquivo != NULL) {
        Funcionario funcionario;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            // Compara o CPF do funcionario atual com o CPF desejado
            if (strcmp(funcionario.cpf, cpf) == 0) {
                printf("Funcionario encontrado:\n");
                mostrar_vendas_por_funcionario(cpf);
              
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        

            else if(!encontrado) {
                printf("Funcionario com CPF %s nao encontrado.\n", cpf);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
    }
void salvar_venda(nova_venda *aln) {
    FILE *arquivo = fopen("vendas.bin", "ab");

    if (arquivo != NULL) {
        fwrite(aln, sizeof(nova_venda), 1, arquivo);
        fclose(arquivo);
        printf("Gravado com Sucesso!!\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

}

int tela_listar_venda(void) {
    (void)system("clear");



    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragancia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu venda = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Lista Geral                                               ///\n");
    printf("///            2. Lista pesquisa cliente                                    ///\n");
    printf("///            3. Lista pesquisa funcionario                                ///\n");
    printf("///            0. voltar                                                    ///\n");
     printf("///                                                                        ///\n");
    printf("///            Escolha a opção desejada: ");
    int opcao_lista;
    scanf("%d", &opcao_lista);
    limparBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    switch (opcao_lista)
    {
    case 1:
        lista_geral();
        break;
    case 2:
        venda_cliente();
        break;
    case 3:
        venda_funcionario();
        break;
    default:
            printf("Opcao invalida\n");
            break;    
    }
return opcao_lista;
}