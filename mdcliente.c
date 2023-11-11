#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacao.h"
bool validarCPF(const char *cpf);
bool validaNome(const char nome[]);
int validaEmail(const char *email);
int valida_data(int dia, int mes, int ano);
bool validaFone(const char fone[]);
void limparBuffer();

struct cliente
{
char cpf_cliente[12];
char nome_cliente[61];
char email_cliente[61];
char data_cliente[21];
char situacao_cliente; 
};

void salvar_cliente(struct cliente *cliente) {
    FILE *arquivo = fopen("clientes.txt", "a");  // Abre o arquivo em modo de anexo (append)
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%s %s %s %s %c\n", cliente->cpf_cliente, cliente->nome_cliente, cliente->email_cliente,
                                         cliente->data_cliente, cliente->situacao_cliente);

    fclose(arquivo);
}

void carregar_cliente(struct cliente *cliente) {
    FILE *arquivo = fopen("clientes.txt", "r");  // Abre o arquivo em modo de leitura
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Supondo que o arquivo tem um formato consistente, você pode usar fscanf para ler os dados
    fscanf(arquivo, "%s %s %s %s %c", cliente->cpf_cliente, cliente->nome_cliente, cliente->email_cliente,
           cliente->data_cliente, &cliente->situacao_cliente);

    fclose(arquivo);
}

void tela_cadastrar_cliente(void) {
    struct cliente cliente;
    char situacao;
    char cpf[12];
    char nome[61];
    char email[61];
    char fone[15];
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
    printf("///            = = = = = = = = Cadastrar Cliente = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                              ///\n");

    scanf("%s",cpf);
    getchar();
    if (validarCPF(cpf)){
        printf("deu certo cpf: %s\n",cpf);
    }else{
        printf("deu errado cpf: %s\n",cpf);
    }
       
    printf("///            Nome completo:                                               ///\n");
    scanf("%61[^\n]", nome);  // Use o formato %x[^\n] para ler a entrada até a quebra de linha ou até x caracteres
    if (validaNome(nome)){
        printf("deu certo nome: %s\n",nome);
    }else{
        printf("deu errado nome: %s\n",nome);
    }
    getchar();

    printf("///            E-mail:                                                      ///\n");
    scanf("%61[^\n]", email);  // Use o formato %x[^\n] para ler a entrada até a quebra de linha ou até x caracteres
    if (validaEmail(email)){
        printf("deu certo email: %s\n",email);
    }else{
        printf("deu errado email: %s\n",email);
    }
    getchar();

    printf("///            Data de Nascimento (dd/mm/aaaa):                             ///\n");
    scanf("%d/%d/%d",&dia,&mes,&ano);  
    if (valida_data(dia,mes,ano)){
        printf("deu certo data: %d/%d/%d\n",dia,mes,ano);
    }else{
        printf("deu errado data: %d/%d/%d\n",dia,mes,ano);
    }
    situacao = 'A';
    getchar();

    printf("///            Celular  (apenas números):                                   ///\n");
    scanf("%s", fone);  
    if ( validaFone(fone)){
        printf("deu certo fone: %s\n",fone);
    }else{
        printf("deu errado fone: %s\n",fone);
    }
    
    getchar();

    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    strcpy(cliente.cpf_cliente, cpf);
    strcpy(cliente.nome_cliente, nome);
    strcpy(cliente.email_cliente, email);
    sprintf(cliente.data_cliente, "%d/%d/%d", dia, mes, ano);
    cliente.situacao_cliente = situacao; // Exemplo: define como 'Ativo'
    salvar_cliente(&cliente);

    getchar();
}
void tela_pesquisar_cliente(void) {
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
    printf("///            = = = = = = = = Pesquisar Cliente = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void tela_alterar_cliente(void) {
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
    printf("///            = = = = = = = = Alterar Cliente = = = = = = = = =             ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o CPF (apenas números):                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    getchar();
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
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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