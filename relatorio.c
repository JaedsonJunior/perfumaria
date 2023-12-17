#include <stdio.h>
#include <stdlib.h>
#include "mdcliente.h"
#include "mdfuncionario.h"
#include "ultilidade.h"
#include "validacao.h"
#include "relatorio.h"

void relatorios_filtro_ativos(void);
int relatorios();
int relatorios_filtro(void);
void relatorios_filtro_inativo(void);
void exibir_cliente_tabela(void);
int relatorio_tabela(void);
void exibir_funcionario_tabela(void);

int relatorios()
{
  int opcao_relato = -1;
  do
  {
    int opcao_filtro = -1;
    int opcao_tab_cliente = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      Menu Relatorios               ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                  1. Relatorios Filtro              ||\n");
    printf("||                  2. Relatorios Tabela              ||\n");
    printf("||                 3. Relatorios Ordenados            ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao_relato);
    limparBuffer();
    switch (opcao_relato)
    {
    case 1:
    do{
      opcao_filtro=relatorios_filtro();
    }while (opcao_filtro!=0);
      break;
      case 2:
    do{
      opcao_tab_cliente=relatorio_tabela();
    }while (opcao_tab_cliente!=0);
      break;
    case 0:
    printf("Saindo...");
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (opcao_relato != 0);
  return opcao_relato;
}


int relatorios_filtro(void)
{
  int opcao_filtro = -1;
  do
  {
    
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                   Relatorios Filtro                ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Ativos                     ||\n");
    printf("||                     2. Inativos                    ||\n");
    printf("||                       0. Sair                      ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &opcao_filtro);
    limparBuffer();
    switch (opcao_filtro)
    {
    case 1:
      relatorios_filtro_ativos();
      break;
    case 2:
      relatorios_filtro_inativo();
      break;  
    case 0:
        printf("saindo");  
        limparBuffer();
        break;
    default:
        printf("Opcao Invalida");
        limparBuffer();
    }
    }while (opcao_filtro != 0);
  return opcao_filtro;
  }
   
void relatorios_filtro_ativos(void)
{
  int opcao_fativo = -1;
  do
  {
    opcao_fativo = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                 Relatorios Filtro Ativos           ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Clientes                   ||\n");
    printf("||                     2. Funcionarios                ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao_fativo);
    limparBuffer();
    switch (opcao_fativo)
    {
    case 1:
      exibir_cliente();
      limparBuffer();
      break;
    case 2:
      exibir_funcionario(); 
      limparBuffer();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (opcao_fativo != 0);
}



void relatorios_filtro_inativo(void)
{
  int opcao_iativo = -1;
  do
  {
    opcao_iativo = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                 Relatorios Filtro Inativo          ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Clientes                   ||\n");
    printf("||                     2. Funcionarios                ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao_iativo);
    limparBuffer();
    switch (opcao_iativo)
    {
    case 1:
      exibir_cliente_inativo();
      limparBuffer();
      break;
    case 2:
      exibir_funcionario_inativo();
      limparBuffer();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (opcao_iativo != 0);
}



int relatorio_tabela(void)
{
  int op_tab_cliente = -1;
  do
  {
    
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                   Relatorios de tabelas            ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Clientes                   ||\n");
    printf("||                     2. Funcionarios                ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\nOpcao: ");
    scanf("%d", &op_tab_cliente);
    limparBuffer();
    switch (op_tab_cliente)
    {
    case 1:
      exibir_cliente_tabela();
      limparBuffer();
      break;
    case 2:
      exibir_funcionario_tabela();
      limparBuffer();
      break;  
    case 0:
        printf("Saindo...");
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op_tab_cliente != 0);
  return op_tab_cliente;
}







void exibir_cliente_tabela(void) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    if (arquivo != NULL) {
        Cliente cliente;
        printf("|%-30s", "Nome:");
        printf("|%-15s", "CPF:");
        printf("|%-15s", "Data de nasci.:");
        printf("|%-30s", "Email:");
        printf("|%-15s", "Telefone:");
        printf("|%-5s", "Situacao:");
        printf("\n");
        while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) 
             {
                // Mostrar informações do cliente
                printf("|%-30s|%-15s|%-15s|%-30s|%-15s|%-5c\n", cliente.nome, cliente.cpf,  cliente.data, cliente.email, cliente.fone, cliente.situacao);
            }

        fclose(arquivo);
    }else {
        printf("Erro ao abrir o arquivo de clientes para leitura.\n");
    

}
}

void exibir_funcionario_tabela(void) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    if (arquivo != NULL) {
        Funcionario funcionario;
        printf("|%-30s", "Nome:");
        printf("|%-15s", "CPF:");
        printf("|%-15s", "Data de nasci.:");
        printf("|%-30s", "Email:");
        printf("|%-15s", "Telefone:");
        printf("|%-5s", "Situacao:");
        printf("\n");
        while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) 
             {
                // Mostrar informações do cliente
                printf("|%-30s|%-15s|%-15s|%-30s|%-15s|%-5c\n", funcionario.nome, funcionario.cpf,  funcionario.data, funcionario.email, funcionario.fone, funcionario.situacao);
            }

        fclose(arquivo);
    }else {
        printf("Erro ao abrir o arquivo de clientes para leitura.\n");
    

}
}









































