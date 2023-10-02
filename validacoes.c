#include <stdio.h>
#include <string.h>
#include <time.h>

//Retorno: [1] - Se for válido | [0] - Se for inválido
//cpf
int validarCPF(char *cpf)
{
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
    return 1;
}
//celular
int validaFone(char* fone) {
    int tam;
    tam = strlen(fone);
    if (tam != 11) {
        return 0;
    }
    for (int i = 0; i < tam; i++) {
        if (!ehDigito(fone[i])) {
            return 0;
        }
    }
    return 1;
}
//nome
int validarNome(char* nome) {

    for (int i=0; nome[i]!='\0'; i++) {
        if (!ehLetra(nome[i])) {
            return 0;
        }
    }
    return 1;
}
// data
int ValidarData(char *entrada)
{
  const char substring[3] = "//";

  if (strstr(entrada, substring) != NULL)
  {
    return 0;
  }

  if (verificarNumero(entrada))
  {
    printf("São numéricos.\n");
  }
  else
  {
    printf("Não são numéricos.\n");
    return 0;
  }

  int i = 0;
  long data[3];
  const char delimitador[2] = "/";
  char *token = strtok(entrada, delimitador);

  // Alimenta o vetor de inteiros
  while (token != NULL)
  {
    data[i++] = strtol(token, NULL, 10);
    token = strtok(NULL, delimitador);
  }

  // Realize suas validações. Se alguma não for atingida, retorne '0'

  printf("Dia: %d\n", data[0]);
  printf("Mes: %d\n", data[1]);
  printf("Ano: %d\n", data[2]);

  // Caso contrário, retorne '1'

  return 1;
}
// email
int validarEmail(void) {

  char email[50]={"abc@xyz.se"};
  int tam=strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } // for

  if (i == tam && depoisPonto > 1)
    printf("Valido");
  else
    printf("Invalido");
}