
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Assinaturas
void tela_menu_principal(void);
void tela_sobre(void);
void tela_equipe(void);

/////
// Programa principal
int main(void){
    setlocale (LC_ALL, "");
    int a = 50;
    printf("O valor de a é = %d \n", a);
    scanf("%d", &a);
    printf("O valor de a mudou para %d ", a);
    
    //Lendo valor quebrado
    float b = 5.5;
    printf("\n");
    printf("O valor de b é = %.1f \n", b);
    scanf("%f", &b);
    printf("O valor de b mudou para %.1f ", b);
    
    //Lendo letra
    char letra = 't';
    printf("\n");
    printf("O valor de c é = %c \n", letra);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    scanf("%c", &letra);
    printf("O valor de c mudou para %c", letra);
    

    return 0;
}

