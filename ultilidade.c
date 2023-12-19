#include <stdio.h>    
#include <stdlib.h>
#include <time.h>
#include "ultilidade.h"
void limparBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }

int data_hoje() {
    time_t t;
    struct tm *data_hora;

    time(&t);
    data_hora = localtime(&t);

    int dia = data_hora->tm_mday;
    int mes = data_hora->tm_mon + 1;  // O mês é baseado em zero
    int ano = data_hora->tm_year + 1900;

    // Exibindo a data no formato "dd/mm/yyyy"
    printf("Data atual: %02d/%02d/%04d\n", dia, mes, ano);

    // Retornando a data no formato numérico (para armazenar ou comparar)
    return dia * 1000000 + mes * 10000 + ano;
}




