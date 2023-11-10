#include <stdio.h> 

int main() {
    char cpf[12]; // 11 dígitos + 1 caractere nulo

    printf("Digite seu CPF (apenas números): ");
    scanf("%s", cpf);

    int valido = validarCPF(cpf);

    if (valido) {
        printf("CPF válido.\n");
    } else {
        printf("CPF inválido.\n");
    }

    return 0;
}

int main() {
    char nome[100];

    printf("Informe um nome: ");
    fgets(nome, sizeof(nome), stdin);

    // Remova o caractere de nova linha (\n) se estiver presente no final da string
    size_t len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }

    if (validaNome(nome)) {
        printf("Nome válido: %s\n", nome);
    } else {
        printf("Nome inválido: %s\n", nome);
    }

    return 0;
}

int main() {
    char fone[100];

    printf("Informe um número de telefone: ");
    fgets(fone, sizeof(fone), stdin);

    // Remova o caractere de nova linha (\n) se estiver presente no final da string
    size_t len = strlen(fone);
    if (len > 0 && fone[len - 1] == '\n') {
        fone[len - 1] = '\0';
    }

    if (validaFone(fone)) {
        printf("Número de telefone válido: %s\n", fone);
    } else {
        printf("Número de telefone inválido: %s\n", fone);
    }

    return 0;
}

int main() {
    char email[100];
    
    printf("Informe um endereço de e-mail: ");
    scanf("%s", email);

    if (validaEmail(email))
        printf("E-mail válido.\n");
    else
        printf("E-mail inválido.\n");

    return 0;
}

int main() {
    int day, month, year;

    printf("Informe uma data no formato (dia mês ano): ");
    scanf("%d %d %d", &day, &month, &year);

    if (validate_date(day, month, year)) {
        printf("A data informada é válida!\n");
    } else {
        printf("A data informada é inválida.\n");
    }

    return 0;
}
