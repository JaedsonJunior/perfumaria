#include <stdio.h>
#include <stdlib.h>
#include "ultilidade.h"

void tela_sobre(void) {
    limparBuffer();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Gestão de perfumaria                ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///       = = = = = Projeto Sistema de Gestão de perfumaria = = = = =       ///\n");
    printf("///                                                                         ///\n");
    printf("///  Programa exemplo utilizado na disciplina DCT1106 - Programação, para   ///\n");
    printf("///  fins de aprendizado e avaliativo ao aluno:Jaedson da Silva Soares Junior///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    
}

void tela_equipe(void) {
    limparBuffer();
    system("clear||cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///                Projeto Sistema de Gestao de perfumaria                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = Projeto Sistema de Gestao de perfumaria = = = = =  ///\n");
    printf("///                                                                         ///\n");
    printf("///            Este projeto exemplo foi desenvolvido por:                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Aluno: Jaedson Junior                                        ///\n");
    printf("///            E-mail: jaedson.junior.017@ufrn.edu.br                       ///\n");
    printf("///            Redes sociais: @jaedsonjunior09c                             ///\n");
    printf("///            Git: https://github.com/JaedsonJunior/perfumaria             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    
}

void mostrar_sobre(void){
    tela_sobre();
    tela_equipe();
}