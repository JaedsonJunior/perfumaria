#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

//CPF ///https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
int validarCPF(char *cpf){
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

//data de nascimento//chatgpt
int validate_date(int day, int month, int year) {
    struct tm timeinfo;

    // Preencha a estrutura tm com a data fornecida
    timeinfo.tm_year = year - 1900; // Ano desde 1900
    timeinfo.tm_mon = month - 1;    // Mês (0-11)
    timeinfo.tm_mday = day;         // Dia do mês

    // Tente converter a data em um formato válido
    if (mktime(&timeinfo) != -1) {
        return 1; // Data válida
    } else {
        return 0; // Data inválida
    }
}

    
