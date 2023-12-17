#include <stdio.h>    
#include <stdlib.h>
void limpaTela(void) {
  if (system("clear") || system("cls")) {
    // limpa a tela, Linux, Mac e Windows
  }
}
void limparBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }
