#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
#include "ultilidade.h"
bool validarCPF(const char *cpf);
bool validaNome(const char nome[]);
int validaEmail(const char *email);
int valida_data(int dia, int mes, int ano);
bool validaFone(const char fone[]);
bool valida_cpf(const char *cpf);
void limparBuffer();
struct funcionario
{
char cpf_funcionario[12];
char nome_funcionario[61];
char email_funcionario[61];
char data_funcionario[21];
char situacao_funcionario;
};

void salvar_funcionario(struct funcionario *funcionario) {
    FILE *arquivo = fopen("funcionarios.txt", "a");  // Abre o arquivo em modo de anexo (append)
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%s %s %s %s %c\n", funcionario->cpf_funcionario, funcionario->nome_funcionario, funcionario->email_funcionario,
                                         funcionario->data_funcionario, funcionario->situacao_funcionario);

    fclose(arquivo);
}

void carregar_funcionario(struct funcionario *funcionario) {
    FILE *arquivo = fopen("funcionarios.txt", "r");  // Abre o arquivo em modo de leitura
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Supondo que o arquivo tem um formato consistente, você pode usar fscanf para ler os dados
    fscanf(arquivo, "%s %s %s %s %c", funcionario->cpf_funcionario, funcionario->nome_funcionario, funcionario->email_funcionario,
           funcionario->data_funcionario, &funcionario->situacao_funcionario);

    fclose(arquivo);
}

void tela_cadastrar_funcionario(void) {
    struct funcionario funcionario;
    char cpf[12];
    char nome[61];
    char email[61];
    char fone[15];
    char situacao;
    int dia,mes,ano;
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
    printf("///            = = = = = = = = Cadastrar Funcionario = = = = = = = =        ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                              ///\n");

    scanf("%s",cpf);
    limparBuffer();
    valida_cpf(cpf);
       
    printf("///            Nome completo:                                               ///\n");
    scanf("%61[^\n]", nome);  // Use o formato %x[^\n] para ler a entrada até a quebra de linha ou até x caracteres
    if (validaNome(nome)){
        printf("deu certo nome: %s\n",nome);
    }else{
        printf("deu errado nome: %s\n",nome);
    }
    limparBuffer();

    printf("///            E-mail:                                                      ///\n");
    scanf("%61[^\n]", email);  // Use o formato %x[^\n] para ler a entrada até a quebra de linha ou até x caracteres
    if (validaEmail(email)){
        printf("deu certo email: %s\n",email);
    }else{
        printf("deu errado email: %s\n",email);
    }
    limparBuffer();

    printf("///            Data de Nascimento (dd/mm/aaaa):                             ///\n");
    scanf("%d/%d/%d",&dia,&mes,&ano);  
    if (valida_data(dia,mes,ano)){
        printf("deu certo data: %d/%d/%d\n",dia,mes,ano);
    }else{
        printf("deu errado data: %d/%d/%d\n",dia,mes,ano);
    }
    limparBuffer();

    printf("///            Celular  (apenas números):                                   ///\n");
    scanf("%s", fone);  
    if ( validaFone(fone)){
        printf("deu certo fone: %s\n",fone);
    }else{
        printf("deu errado fone: %s\n",fone);
    }
    limparBuffer();
    situacao = 'A';
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
     strcpy(funcionario.cpf_funcionario, cpf);
    strcpy(funcionario.nome_funcionario, nome);
    strcpy(funcionario.email_funcionario, email);
    sprintf(funcionario.data_funcionario, "%d/%d/%d", dia, mes, ano);
    funcionario.situacao_funcionario = situacao; // Exemplo: define como 'Ativo'
    salvar_funcionario(&funcionario);
    limparBuffer();
}
void tela_pesquisar_funcionario(void) {
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///                    = = = =  Fragância Popular    = = = =                ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///               Developed by @JaedsonJunior -- since Ago, 2023               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar funcionario = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void tela_alterar_funcioinario(void) {
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
    printf("///            = = = = = = = = Alterar Funcionario = = = = = = = = =        ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    limparBuffer();
}
void tela_excluir_funcionario(void) {
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
    printf("///            = = = = = = = = Excluir funcionario = = = = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                             ///\n");
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
                tela_alterar_funcioinario();
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