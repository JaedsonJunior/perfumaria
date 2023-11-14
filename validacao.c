#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>



//CPF ///https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
bool validarCPF(const char *cpf){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
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



bool valida_cpf(const char *cpf) {
    printf(validarCPF(cpf) ? "ok\n" : "errado\n");
    return validarCPF(cpf);
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

//data de nascimento// https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas
int valida_data(int dia, int mes, int ano)
    {
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                return 0;
            }
      }
       else
           {
                return 0;
           }
}

// Função para verificar se um caractere é um dígito numérico
bool isDigit(char c) {
    return isdigit((unsigned char)c) != 0;
}
    
