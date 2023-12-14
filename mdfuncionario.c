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

typedef struct funcionario Funcionario;





struct funcionario
{
char cpf[12];
char nome[61];
char email[61];
char data[12];
char fone[15];
char situacao;
};

void salvar_funcionario(Funcionario *aln) {
    FILE *arquivo = fopen("funcionario.bin", "ab");

    if (arquivo != NULL) {
        fwrite(aln, sizeof(Funcionario), 1, arquivo);
        fclose(arquivo);
        printf("Gravado com Sucesso!!\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }

}

void ler_funcionario(void) {
    FILE *arquivo = fopen("funcionario.bin", "rb");

    if (arquivo != NULL) {
        Funcionario funcionario;

        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            printf("CPF: %s\n", funcionario.cpf);
            printf("NOME: %s\n", funcionario.nome);
            printf("EMAIL: %s\n", funcionario.email);
            printf("DATA: %s\n", funcionario.data);
            printf("TELEFONE: %s\n", funcionario.fone);
            printf("SITUACAO: %c\n", funcionario.situacao);
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}


void pesquisar_funcionario(const char *cpf) {
    FILE *arquivo = fopen("funcionario.bin", "rb");

    if (arquivo != NULL) {
        Funcionario funcionario;

        int encontrado = 0; // Flag para indicar se o cliente foi encontrado

        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            // Compara o CPF do cliente atual com o CPF desejado
            if (strcmp(funcionario.cpf, cpf) == 0) {
                printf("Cliente encontrado:\n");
                printf("CPF: %s\n", funcionario.cpf);
                printf("NOME: %s\n", funcionario.nome);
                printf("EMAIL: %s\n", funcionario.email);
                printf("DATA: %s\n", funcionario.data);
                printf("TELEFONE: %s\n",funcionario.fone);
                printf("SITUACAO: %c\n",funcionario.situacao);
                
                encontrado = 1;
                break; // Se encontrou, sai do loop
            }
        

            else if(!encontrado) {
                printf("Funcionario com CPF %s não encontrado.\n", cpf);
        }}

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
}


// Função para atualizar um cliente no arquivo binário
void atualizar_funcionario_nome(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("funcionario.bin", "r+b");

    if (arquivo != NULL) {
        Funcionario funcionario;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            if (strcmp(funcionario.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(funcionario.nome, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Funcionario), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);

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
void atualizar_funcionario_email(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("funcionario.bin", "r+b");

    if (arquivo != NULL) {
        Funcionario funcionario;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            if (strcmp(funcionario.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(funcionario.email, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Funcionario), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

void atualizar_funcionario_data(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("funcionario.bin", "r+b");

    if (arquivo != NULL) {
        Funcionario funcionario;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            if (strcmp(funcionario.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(funcionario.data, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Funcionario), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

void atualizar_funcionario_telefone(const char *cpf, const char *novo_dado) {
    FILE *arquivo = fopen("funcionario.bin", "r+b");

    if (arquivo != NULL) {
        Funcionario funcionario;

        // Encontrar a posição do registro que possui o CPF fornecido
        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
            if (strcmp(funcionario.cpf, cpf) == 0) {
                // Atualizar os campos necessários do registro
                strcpy(funcionario.fone, novo_dado);

                // Voltar à posição do arquivo onde o registro foi lido
                fseek(arquivo, -sizeof(Funcionario), SEEK_CUR);

                // Escrever o registro modificado de volta no arquivo
                fwrite(&funcionario, sizeof(Funcionario), 1, arquivo);

                printf("%s atualizado com sucesso!\n",novo_dado);
                break;
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo para leitura e gravação.\n");
    }
}

// Função para excluir um cliente com base no CPF do arquivo binário
void excluir_funcionario(const char *cpf) {
    FILE *arquivo;
    FILE *temp_fun;
    Funcionario funcionario;

    // Abra o arquivo binário para leitura
    arquivo = fopen("funcionario.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Abra um arquivo temporário para escrita
    temp_fun = fopen("temp_fun.bin", "wb");
    if (temp_fun == NULL) {
        perror("Erro ao criar o arquivo temporário");
        fclose(arquivo);
        exit(EXIT_FAILURE);
    }

    // Leia os registros do arquivo e grave no arquivo temporário, exceto o que será excluído
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        if (strcmp(funcionario.cpf, cpf) != 0) {
            fwrite(&funcionario, sizeof(Funcionario), 1, temp_fun);
        }
    }

    // Feche os arquivos
    fclose(arquivo);
    fclose(temp_fun);

    // Remova o arquivo original e renomeie o temporário
    if (remove("funcionario.bin") != 0) {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("temp_fun.bin", "funcionario.bin") != 0) {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }

    printf("Funcionario com CPF %s excluído com sucesso.\n", cpf);
}

Funcionario* tela_cadastrar_funcionario(void) {
    Funcionario *aln;
	aln = (Funcionario*) malloc(sizeof(Funcionario));
    
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                  = = = =   Fragancia Popular     = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                     Developed by @JaedsonJunior                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar funcionario = = = = =              ///\n");
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
   
    salvar_funcionario(aln);
    limparBuffer();
    return aln;
    
}
void tela_pesquisar_funcionario(void) {
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
    printf("///                      Developed by @JaedsonJunior                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar funcionario = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
   do {
		printf("///            Informe o CPF (apenas números):                              ///\n");
		scanf("%[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf(cpf));
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");   
    pesquisar_funcionario(cpf);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void tela_alterar_funcionario(void) {
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
    printf("///                 = = = =   Fragância Popular     = = = =                 ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Alterar Fucionario = = = = = =               ///\n");
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
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%d",&alt);
    switch (alt)
    {
    case 1:
    
    do {
		printf(".> Digite o novo Nome:                                                    \n");
        limparBuffer();
		scanf("%61[^\n]",nome);
        
	} while (!validaNome(nome));
        atualizar_funcionario_nome(cpf,nome);
        limparBuffer();
        break;

    case 2:

     do {   
		printf(".> Digite o novo email:                                                   \n");
        limparBuffer();
		scanf("%61[^\n]",email);
	} while (!validaEmail(email));
        atualizar_funcionario_email(cpf,email);
        limparBuffer();
        break;

    case 3:

    do {
		printf(".> nova Data de Nascimento (dd/mm/aaaa):                                  \n");
        limparBuffer();
		scanf(("%11[0-9/]"),data);
	} while (!valida_data(data));
        atualizar_funcionario_data(cpf,data);
        limparBuffer();
        break;

    case 4:

         do {
		printf(".> Numero novo  (apenas números):                                          \n");
        limparBuffer();
		scanf("%[^\n]",fone);
	    } while (!validaFone(fone));
        atualizar_funcionario_telefone(cpf,fone);
        limparBuffer();
        break;

    default:
        break;
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void tela_excluir_funcionario(void) {
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = =   Fragância Popular     = = = =                      ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir funcionario = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
     do {
		printf("///            Informe o CPF (apenas números):                              ///\n");
		scanf("%12[^\n]",cpf);
		limparBuffer();
	} while (!valida_cpf(cpf));
    excluir_funcionario(cpf);
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}

int tela_menu_funcionario() {
    int opcaoC3;
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
    printf("///            = = = = = = = = =  Menu funcionario = = = = = = = = =        ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um funcionario                                 ///\n");
    printf("///            2. Pesquisar os dados de um funcionario                      ///\n");
    printf("///            3. Atualizar os dados de um funcionario                      ///\n");
    printf("///            4. Excluir um funcionario do sistema                         ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada: ");
    scanf("%d", &opcaoC3);
    limparBuffer();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
    switch (opcaoC3) {
            case 1:
                tela_cadastrar_funcionario();
                break;
            case 2:
                tela_pesquisar_funcionario();
                break;
            case 3:
                tela_alterar_funcionario();
                break;
            case 4:
                tela_excluir_funcionario();    
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }

return opcaoC3;        
}