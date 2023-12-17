#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include "ultilidade.h"
#include "mdcliente.h"
#include "mdfuncionario.h"



//CPF ///https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
int validarCPF(const char *cpf){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;}


int valida_cpf_cliente_cadastro(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    int x;
    x = validarCPF(cpf);
    if (x==1){
        if (arquivo != NULL){
            fclose(arquivo);
            return compara_cpf_cliente_cadastro(cpf);
            
            }
        else{
            return 0;
        }

        
    }else 
    {
       printf("CPF invalido.");
       return 1;
    };
    
    return compara_cpf_cliente_cadastro(cpf);
}

int valida_cpf_cliente_pesquisa(const char *cpf) {
    FILE *arquivo = fopen("clientes.bin", "rb");
    int x;
    x = validarCPF(cpf);
    if (x==1){
        if (arquivo != NULL){
            fclose(arquivo);
            return compara_cpf_cliente_pesquisa(cpf);
            
            }
        else{
            return 0;
        }

        
    }else 
    {
       printf("CPF invalido.");
       return 0;
    };
    
    return compara_cpf_cliente_pesquisa(cpf);
}

int valida_cpf_funcionario_cadastro(const char *cpf) {
    FILE *arquivo = fopen ("funcionario.bin","rb");
    int x;
    x = validarCPF(cpf);
    if (x==1){
       if (arquivo != NULL){
            fclose(arquivo);
            return compara_cpf_funcionario_cadastro(cpf);
            
            }
        else{
            return 0;
        }

        
    }else 
    {
       printf("CPF invalido.");
       return 0;
    };
    
    return compara_cpf_funcionario_cadastro(cpf);
}


int valida_cpf_funcionario_pesquisa(const char *cpf) {
    FILE *arquivo = fopen ("funcionario.bin","rb");
    int x;
    x = validarCPF(cpf);
    if (x==1){
       if (arquivo != NULL){
            fclose(arquivo);
            return compara_cpf_funcionario_pesquisa(cpf);
            
            }
        else{
            return 0;
        }

        
    }else 
    {
       printf("CPF invalido.");
       return 0;
    };
    
    return compara_cpf_funcionario_pesquisa(cpf);
}



//nome /// adaptado de https://gist.github.com/jpcabana1/69054083240567faae13cb375e291e49
bool validaNome(const char nome[]) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha((unsigned char)nome[i]) && nome[i] != ' ' && nome[i] != '\'') {
            return false;
        }
    }
    return true;
}
  
//numero fone//adaptado chatgpt
bool validaFone(const char fone[]) {
    int i = 0;
    while (fone[i] != '\0') {
        if (fone[i] < '0' || fone[i] > '9') {
            return false; // Caractere não é um dígito (0-9)
        }
        i++;
    }

    if (i > 15) {
        return false; // O número de telefone é muito longo (mais de 15 dígitos)
    }

    return true; // O número de telefone é válido
}

//email//chatgpt
int validaEmail(const char *email) {
    int i, atpos = -1, dotpos = -1;

    // Verifica se o e-mail é vazio
    if (strlen(email) == 0)
        return 0;

    // Verifica se há exatamente um caractere '@'
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            if (atpos != -1) // Já existe um '@' anteriormente
                return 0;
            atpos = i;
        }
    }

    // Verifica se há pelo menos um caractere '.' após o '@'
    for (i = atpos; email[i] != '\0'; i++) {
        if (email[i] == '.') {
            dotpos = i;
            break;
        }
    }

    // Verifica se há pelo menos um caractere após o último '.'
    if (dotpos == -1 || dotpos == strlen(email) - 1)
        return 0;

    return 1;
}



// Função para verificar se um caractere é um dígito numérico
bool isDigit(char c) {
    return isdigit((unsigned char)c) != 0;
}
    
bool extrair_data(const char *data, int *dia, int *mes, int *ano) {
    // Utiliza sscanf para extrair dia, mês e ano da string no formato "dd/mm/aaaa"

    
    if (sscanf(data, "%d/%d/%d", dia, mes, ano) != 3) {
        // Se a conversão não foi bem-sucedida (não foram lidos 3 valores), retorna falso
        return false;
    }

    return true;
}


//data de nascimento// https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas && adaptada pelo chat GPT
bool valida_data(const char *data) {
    int dia, mes, ano;

    // Extrai dia, mês e ano da string
    if (!extrair_data(data, &dia, &mes, &ano)) {
        // Se a extração falhar, a data é considerada inválida
        return false;
    }


   if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) {
        if (mes == 2) {
            // Fevereiro
            if (dia > 29) {
                return false; // Mais de 29 dias em fevereiro
            } else if (dia == 29 && (ano % 4 != 0 || (ano % 100 == 0 && ano % 400 != 0))) {
                return false; // Ano não bissexto, mas tentando inserir 29 de fevereiro
            }
        } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
            return false; // Meses com 30 dias e dia maior que 30
        }
        // Todas as condições atendidas, a data é válida
        return true;
    }
    // Condições iniciais não atendidas, a data é inválida
    return false;
}

