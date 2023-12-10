#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
#include "ultilidade.h"
bool validarCPF(const char *cpf);
bool validaNome(const char nome[]);
int validaEmail(const char *email);
bool extrair_data(const char *data, int *dia, int *mes, int *ano);
bool valida_data(const char *data);
bool validaFone(const char fone[]);
bool valida_cpf(const char *cpf);
void limparBuffer();
void limpaTela();

typedef struct cliente Cliente;




struct cliente
{
char cpf[12];
char nome[61];
char email[61];
char data[12];
char fone[15];
char situacao; 
};

void salvar_cliente(Cliente *aln) {
    FILE *arquivo = fopen("clientes.bin", "ab");

    if (arquivo != NULL) {
        fwrite(aln, sizeof(Cliente), 1, arquivo);
        fclose(arquivo);
        printf("Gravado com Sucesso!!\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

}

void ler_cliente(void) {
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo != NULL) {
        Cliente cliente;

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            printf("CPF: %s\n", cliente.cpf);
            printf("NOME: %s\n", cliente.nome);
            printf("EMAIL: %s\n", cliente.email);
            printf("DATA: %s\n", cliente.data);
            printf("TELEFONE: %s\n", cliente.fone);
            printf("SITUACAO: %c\n", cliente.situacao);
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}


void pesquisar_cliente(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo != NULL) {
        Cliente cliente;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            // Compara o CPF do cliente atual com o CPF desejado
            if (strcmp(cliente.cpf, cpf) == 0) {
                printf("Cliente encontrado:\n");
                printf("CPF: %s\n", cliente.cpf);
                printf("NOME: %s\n", cliente.nome);
                printf("EMAIL: %s\n", cliente.email);
                printf("DATA: %s\n", cliente.data);
                printf("TELEFONE: %s\n", cliente.fone);
                printf("SITUACAO: %c\n", cliente.situacao);
                
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        

            else if(!encontrado) {
                printf("Cliente com CPF %s não encontrado.\n", cpf);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}


// Função para atualizar um cliente no arquivo binário
void atualizar_cliente(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("clientes.bin", "r+b");

    if (arquivo != NULL) {
        Cliente cliente;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            if (strcmp(cliente.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(cliente.nome, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);

                printf("Cliente atualizado com sucesso!\n");
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

Cliente* tela_cadastrar_cliente(void) {
    Cliente *aln;
	aln = (Cliente*) malloc(sizeof(Cliente));
    
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
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    do {
		printf("///            Informe o CPF (apenas números):                              ///\n");
		scanf("%[^\n]", aln->cpf);
		limparBuffer();
	} while (!valida_cpf(aln->cpf));
       
    
    do {
		printf("///            Nome completo:                                               ///\n");
		scanf("%[^\n]", aln->nome);
		limparBuffer();
	} while (!validaNome(aln->nome));

     do {   
		printf("///            email:                                                       ///\n");
		scanf("%[^\n]", aln->email);
		limparBuffer();
	} while (!validaEmail(aln->email));

    
     do {
		printf("///            Data de Nascimento (dd/mm/aaaa):                             ///\n");
		scanf(("%11[0-9/]"),aln->data);
		limparBuffer();
	} while (!valida_data(aln->data));
    

   
     do {
		printf("///            Celular  (apenas números):                                   ///\n");
		scanf("%[^\n]", aln->fone);
		limparBuffer();
	} while (!validaFone(aln->fone));

    aln->situacao = 'A';
    

    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
   
    salvar_cliente(aln);
    limparBuffer();
    return aln;
    
}
void tela_pesquisar_cliente() {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                    = = = =  Fragância Popular    = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Cliente = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    do {
		printf("///            Informe o CPF (apenas números):                              ///\n");
		scanf("%[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf(cpf));
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");   
    pesquisar_cliente(cpf);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void tela_alterar_cliente(void) {
    char cpf[12];
    char nome[61];
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
    do {
		printf("///            Informe o CPF (apenas números):                              ///\n");
		scanf("%[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf(cpf));
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     OPCOES DE ALTERACAO                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                     1- Alterar o nome                                   ///\n");
    printf("///                     2- Alterar o email                                  ///\n");
    printf("///                     3- Alterar a data de nascimeto                      ///\n");
    printf("///                     4- Alterar o numero telefonico                      ///\n");
    printf("///                     5- Alterar a situacao do cliente                    ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%d",&alt);
    switch (alt)
    {
    case 1:
    
    do {
		printf("///          Digite o novo Nome:                                               ///\n");
        limparBuffer();
		scanf("%61[^\n]",nome);
        
	} while (!validaNome(nome));
        atualizar_cliente(cpf,nome);
        limparBuffer();
        break;
    
    default:
        break;
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void tela_excluir_cliente(void) {

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
    printf("///            = = = = = = = = Excluir Cliente = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF(apenas números):                               ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}


int tela_menu_cliente() {
    int opcaoCl;
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
    printf("///            = = = = = = = = =  Menu Cliente = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo cliente                                 ///\n");
    printf("///            2. Pesquisar os dados de um cliente                          ///\n");
    printf("///            3. Atualizar o cadastro de um cliente                        ///\n");
    printf("///            4. Excluir um cliente do sistema                             ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &opcaoCl);
    limparBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
    switch (opcaoCl) {
            case 1:
                tela_cadastrar_cliente();
                break;
            case 2:
                tela_pesquisar_cliente();
                break;
            case 3:
                tela_alterar_cliente();
                break;
            case 4:
                tela_excluir_cliente();    
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

return opcaoCl;        
}