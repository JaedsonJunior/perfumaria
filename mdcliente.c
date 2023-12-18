#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "validacao.h"
#include "ultilidade.h"

int validarCPF(const char *cpf);
bool validaNome(const char nome[]);
int validaEmail(const char *email);
bool extrair_data(const char *data, int *dia, int *mes, int *ano);
bool valida_data(const char *data);
bool validaFone(const char fone[]);
int valida_cpf_cliente_cadastro(const char *cpf);
int valida_cpf_cliente_pesquisa(const char *cpf);


void limparBuffer();

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
                printf("Cliente com CPF %s nao encontrado.\n", cpf);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}
int compara_cpf_cliente_cadastro(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo != NULL) {
        Cliente cliente;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            // Compara o CPF do cliente atual com o CPF desejado
            if (strcmp(cliente.cpf, cpf) == 0) {
                printf("\nCPF cadastrado.\n");
                
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        }

        fclose(arquivo);
        return encontrado;
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0; // Retorna 0 se houver erro ao abrir o arquivo
    }
}
int compara_cpf_cliente_pesquisa(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo != NULL) {
        Cliente cliente;

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            // Compara o CPF do cliente atual com o CPF desejado
            if (strcmp(cliente.cpf, cpf) == 0) {
                return 1;
                
            }
        }

        fclose(arquivo);
        return 0;
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0; // Retorna 0 se houver erro ao abrir o arquivo
    }
}



// Função para atualizar um cliente no arquivo binário
void atualizar_cliente_nome(const char *cpf, const char *novo_dado) {
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

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

// Função para atualizar um cliente no arquivo binário
void atualizar_cliente_email(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("clientes.bin", "r+b");

    if (arquivo != NULL) {
        Cliente cliente;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            if (strcmp(cliente.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(cliente.email, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

void atualizar_cliente_data(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("clientes.bin", "r+b");

    if (arquivo != NULL) {
        Cliente cliente;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            if (strcmp(cliente.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(cliente.data, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

void atualizar_cliente_telefone(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("clientes.bin", "r+b");

    if (arquivo != NULL) {
        Cliente cliente;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            if (strcmp(cliente.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(cliente.fone, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravacao.\n");
    }
}

// Função para excluir um cliente com base no CPF do arquivo binário
void excluir_cliente(const char *cpf) {
    FILE *arquivo;
    FILE *temp;
    Cliente cliente;

    // Abra o arquivo binário para leitura
    arquivo = fopen("clientes.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Abra um arquivo temporário para escrita
    temp = fopen("temp.bin", "wb");
    if (temp == NULL) {
        perror("Erro ao criar o arquivo temporario");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Leia os registros do arquivo e grave no arquivo temporário, exceto o que será excluído
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) != 0) {
            fwrite(&cliente, sizeof(Cliente), 1, temp);
        }
    }

    // Feche os arquivos
    fclose(arquivo);
    fclose(temp);

    // Remova o arquivo original e renomeie o temporário
    if (remove("clientes.bin") != 0) {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("temp.bin", "clientes.bin") != 0) {
        perror("Erro ao renomear o arquivo temporario");
        exit(EXIT_FAILURE);
    }

    printf("Cliente com CPF %s excluido com sucesso.\n", cpf);
}


void atualizar_situacao_cliente(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb+");
    char nova_situacao = 'I';

    if (arquivo != NULL) {
        Cliente cliente;

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            // Verifica se o CPF do cliente atual é o desejado
            if (strcmp(cliente.cpf, cpf) == 0) {
                // Atualiza a situação do cliente
                cliente.situacao = nova_situacao;

                // Volta para a posição do arquivo para escrever a alteração
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);

                printf("Cliente com CPF %s excluído com sucesso.\n", cpf);
                break; // Cliente encontrado, não precisa continuar procurando
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
    }
}
void mini_exibir_cliente(FILE *arquivo){
    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1){
    printf("|%-30s|%-15s|%-15s|%-30s|%-15s|%-5c\n", cliente.nome, cliente.cpf,  cliente.data, cliente.email, cliente.fone, cliente.situacao);
    }
}
void exibir_cliente(void) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    int i;
    if (arquivo != NULL) {
        Cliente cliente;
        i = 1;

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            if (cliente.situacao != 'I') {
                // Mostrar informações do cliente
                printf("Cliente encontrado:%d\n", i);
                printf("CPF: %s\n", cliente.cpf);
                printf("NOME: %s\n", cliente.nome);
                printf("EMAIL: %s\n", cliente.email);
                printf("DATA: %s\n", cliente.data);
                printf("TELEFONE: %s\n", cliente.fone);
                printf("SITUACAO: %c\n", cliente.situacao);
                printf("Proximo Cliente->\n");
                limparBuffer();
                i += 1;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de clientes para leitura.\n");
    }
}

void exibir_cliente_inativo(void) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    int i;
    if (arquivo != NULL) {
        Cliente cliente;
        i = 1;

        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
            if (cliente.situacao != 'A') {
                // Mostrar informações do cliente
                printf("Cliente encontrado:%d\n", i);
                printf("CPF: %s\n", cliente.cpf);
                printf("NOME: %s\n", cliente.nome);
                printf("EMAIL: %s\n", cliente.email);
                printf("DATA: %s\n", cliente.data);
                printf("TELEFONE: %s\n", cliente.fone);
                printf("SITUACAO: %c\n", cliente.situacao);
                printf("Proximo Cliente->\n");
                limparBuffer();
                i += 1;
            }else{
                printf("Sem Clientes Inativos !!!");
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo de clientes para leitura.\n");
    }
}
void tela_exibir_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                    = = = =  Fragancia Popular    = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = =  Lista Clientes  = = = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    exibir_cliente();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
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
    printf("///                  = = = =   Fragancia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    do {
		printf("///            Informe o CPF (apenas numeros): ");
		scanf("%12s]", aln->cpf);
        limparBuffer();
	} while (valida_cpf_cliente_cadastro(aln->cpf)!=0);
       
    
    do {
		printf("///            Nome completo: ");
		scanf("%61s", aln->nome);
		limparBuffer();
	} while (!validaNome(aln->nome));

     do {   
		printf("///            email: ");
		scanf("%61s", aln->email);
		limparBuffer();
	} while (!validaEmail(aln->email));

    
     do {
		printf("///            Data de Nascimento (dd/mm/aaaa): ");
		scanf(("%11[0-9/]"),aln->data);
		limparBuffer();
	} while (!valida_data(aln->data));
    

   
     do {
		printf("///            Celular (DDD): ");
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
    printf("///                    = = = =  Fragancia Popular    = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Cliente = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    do {
		printf("///            Informe o CPF (apenas numeros): ");
		scanf("%[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf_cliente_pesquisa(cpf));
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
    char email[61];
    char data[12];
    char fone[15];
    int alt;
    system("clear||cls");
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
    printf("///            = = = = = = = = Alterar Cliente = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    do {
		printf("///            Informe o CPF (apenas numeros): ");
		scanf("%[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf_cliente_pesquisa(cpf));
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                     OPCOES DE ALTERACAO                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                     1- Alterar o nome                                   ///\n");
    printf("///                     2- Alterar o email                                  ///\n");
    printf("///                     3- Alterar a data de nascimeto                      ///\n");
    printf("///                     4- Alterar o numero telefonico                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%d",&alt);
    switch (alt)
    {
    case 1:
    
    do {
		printf(".> Digite o novo Nome: ");
        limparBuffer();
		scanf("%61[^\n]",nome);
        
	} while (!validaNome(nome));
        atualizar_cliente_nome(cpf,nome);
        limparBuffer();
        break;

    case 2:

     do {   
		printf(".> Digite o novo email: ");
        limparBuffer();
		scanf("%61[^\n]",email);
	} while (!validaEmail(email));
        atualizar_cliente_email(cpf,email);
        limparBuffer();
        break;

    case 3:

    do {
		printf(".> nova Data de Nascimento (dd/mm/aaaa): ");
        limparBuffer();
		scanf(("%11[0-9/]"),data);
	} while (!valida_data(data));
        atualizar_cliente_data(cpf,data);
        limparBuffer();
        break;

    case 4:

         do {
		printf(".> Numero novo  (apenas números): ");
        limparBuffer();
		scanf("%[^\n]",fone);
	    } while (!validaFone(fone));
        atualizar_cliente_telefone(cpf,fone);
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
    char cpf[12];
    system("clear||cls");

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
    printf("///            = = = = = = = = Excluir Cliente = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
     do {
		printf("///            Informe o CPF (apenas numeros): ");
		scanf("%12[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf_cliente_pesquisa(cpf));
    atualizar_situacao_cliente(cpf);
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
    printf("///                  = = = =   Fragancia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
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
    printf("///            5. exibir clientes                                           ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
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
            case 5:
                tela_exibir_cliente();
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }

return opcaoCl;        
}